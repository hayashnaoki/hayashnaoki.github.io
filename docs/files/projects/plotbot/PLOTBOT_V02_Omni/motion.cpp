#include <AccelStepper.h>
#include <Arduino.h>
#include <Servo.h>

#include "config.h"
#include "motion.h"
#include "pins.h"

float currentX = 0;
float currentY = 0;
float currentR = 0;
int currentZ = SERVO_DEFAULT_ANGLE;

AccelStepper stepperM1(AccelStepper::DRIVER, PIN_STEP_M1, PIN_DIR_M1);
AccelStepper stepperM2(AccelStepper::DRIVER, PIN_STEP_M2, PIN_DIR_M2);
AccelStepper stepperM3(AccelStepper::DRIVER, PIN_STEP_M3, PIN_DIR_M3);

Servo servoZ;

void motionInit() {
  pinMode(PIN_LIMIT_X, INPUT_PULLUP);
  pinMode(PIN_LIMIT_Y, INPUT_PULLUP);

  stepperM1.setMaxSpeed(MAX_SPEED);
  stepperM2.setMaxSpeed(MAX_SPEED);
  stepperM3.setMaxSpeed(MAX_SPEED);

  stepperM1.setAcceleration(ACCELERATION);
  stepperM2.setAcceleration(ACCELERATION);
  stepperM3.setAcceleration(ACCELERATION);

  servoZ.attach(PIN_SERVO_Z, SERVO_MIN_US, SERVO_MAX_US);
  servoZ.write(currentZ);
}

void homeAxes() {
  stepperM1.setSpeed(87);
  stepperM2.setSpeed(87);
  stepperM3.setSpeed(100);

  while (digitalRead(PIN_LIMIT_X)) {
    stepperM1.runSpeed();
    stepperM2.runSpeed();
    stepperM3.runSpeed();
  }

  stepperM1.setSpeed(-100);
  stepperM2.setSpeed(100);
  stepperM3.setSpeed(0);

  while (digitalRead(PIN_LIMIT_Y)) {
    stepperM1.runSpeed();
    stepperM2.runSpeed();
    stepperM3.runSpeed();
  }

  stepperM1.setCurrentPosition(0);
  stepperM2.setCurrentPosition(0);
  stepperM3.setCurrentPosition(0);

  currentX = currentY = currentR = 0;
}

void moveTo(float x, float y, float r) {
  float dx = x - currentX;
  float dy = y - currentY;
  float dr = r - currentR;

  // Apply drift compensation to correct Y-axis drift during X-axis movement
  float abs_dx = (dx >= 0.0f) ? dx : -dx;
  float dy_corr = dy + abs_dx * X_Y_DRIFT_COMPENSATION;

  // Calculate target step counts for each motor
  float steps1 = -dx * 0.866025f * STEPS_PER_MM_X +
                 dy_corr * 0.5f * STEPS_PER_MM_Y - dr * STEPS_PER_DEG_R;
  float steps2 = -dx * 0.866025f * STEPS_PER_MM_X -
                 dy_corr * 0.5f * STEPS_PER_MM_Y - dr * STEPS_PER_DEG_R;
  float steps3 = -dx * STEPS_PER_MM_X * M3_X_SCALE + dr * STEPS_PER_DEG_R;

  // Find the maximum steps to be traveled by any single motor
  float maxSteps = max(abs(steps1), max(abs(steps2), abs(steps3)));

  // If no movement is required, return early
  if (maxSteps < 0.1f)
    return;

  // Calculate proportional scaling factors
  float scale1 = abs(steps1) / maxSteps;
  float scale2 = abs(steps2) / maxSteps;
  float scale3 = abs(steps3) / maxSteps;

  // Coordinated speed and acceleration scaling for linear interpolation
  stepperM1.setMaxSpeed(max(MAX_SPEED * scale1, 1.0f));
  stepperM1.setAcceleration(max(ACCELERATION * scale1, 1.0f));

  stepperM2.setMaxSpeed(max(MAX_SPEED * scale2, 1.0f));
  stepperM2.setAcceleration(max(ACCELERATION * scale2, 1.0f));

  stepperM3.setMaxSpeed(max(MAX_SPEED * scale3, 1.0f));
  stepperM3.setAcceleration(max(ACCELERATION * scale3, 1.0f));

  // Move motors to the calculated step positions
  stepperM1.move(round(steps1));
  stepperM2.move(round(steps2));
  stepperM3.move(round(steps3));

  // Execute coordinated motion
  while (stepperM1.isRunning() || stepperM2.isRunning() ||
         stepperM3.isRunning()) {
    stepperM1.run();
    stepperM2.run();
    stepperM3.run();
  }

  currentX = x;
  currentY = y;
  currentR = r;
}

void setServoZ(int angle) {
  angle = constrain(angle, 0, 180);
  servoZ.write(angle);
  currentZ = angle;
}