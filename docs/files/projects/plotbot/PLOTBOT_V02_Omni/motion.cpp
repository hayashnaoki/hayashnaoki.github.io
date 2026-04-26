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
  stepperM1.setSpeed(50);
  stepperM2.setSpeed(50);
  stepperM3.setSpeed(-100);

  while (digitalRead(PIN_LIMIT_X)) {
    stepperM1.runSpeed();
    stepperM2.runSpeed();
    stepperM3.runSpeed();
  }

  stepperM1.setSpeed(-86.6025);
  stepperM2.setSpeed(86.6025);
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

  const float SIN_30 = 0.5f;
  const float COS_30 = 0.8660254f;

  float m1_steps = -SIN_30 * dx * STEPS_PER_MM_X +
                   COS_30 * dy * STEPS_PER_MM_Y + dr * STEPS_PER_DEG_R;
  float m2_steps = -SIN_30 * dx * STEPS_PER_MM_X -
                   COS_30 * dy * STEPS_PER_MM_Y + dr * STEPS_PER_DEG_R;
  float m3_steps = 1.0f * dx * STEPS_PER_MM_X + 0.0f * dy * STEPS_PER_MM_Y +
                   dr * STEPS_PER_DEG_R;

  stepperM1.move(m1_steps);
  stepperM2.move(m2_steps);
  stepperM3.move(m3_steps);

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