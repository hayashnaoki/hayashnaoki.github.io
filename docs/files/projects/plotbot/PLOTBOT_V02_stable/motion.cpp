#include <Arduino.h>
#include <AccelStepper.h>
#include <Servo.h>

#include "pins.h"
#include "config.h"
#include "motion.h"

float currentX = 0;
float currentY = 0;
float currentR = 0;
int   currentZ = SERVO_DEFAULT_ANGLE;

AccelStepper stepperRF(AccelStepper::DRIVER, PIN_STEP_RF, PIN_DIR_RF);
AccelStepper stepperLF(AccelStepper::DRIVER, PIN_STEP_LF, PIN_DIR_LF);
AccelStepper stepperRB(AccelStepper::DRIVER, PIN_STEP_RB, PIN_DIR_RB);
AccelStepper stepperLB(AccelStepper::DRIVER, PIN_STEP_LB, PIN_DIR_LB);

Servo servoZ;

void motionInit() {
    pinMode(PIN_LIMIT_X, INPUT_PULLUP);
    pinMode(PIN_LIMIT_Y, INPUT_PULLUP);

    stepperRF.setMaxSpeed(MAX_SPEED);
    stepperLF.setMaxSpeed(MAX_SPEED);
    stepperRB.setMaxSpeed(MAX_SPEED);
    stepperLB.setMaxSpeed(MAX_SPEED);

    stepperRF.setAcceleration(ACCELERATION);
    stepperLF.setAcceleration(ACCELERATION);
    stepperRB.setAcceleration(ACCELERATION);
    stepperLB.setAcceleration(ACCELERATION);

    servoZ.attach(PIN_SERVO_Z, SERVO_MIN_US, SERVO_MAX_US);
    servoZ.write(currentZ);
}

void homeAxes() {
    stepperRF.setSpeed( 100);
    stepperLF.setSpeed(-100);
    stepperRB.setSpeed(-100);
    stepperLB.setSpeed( 100);

    while (digitalRead(PIN_LIMIT_X)) {
        stepperRF.runSpeed();
        stepperLF.runSpeed();
        stepperRB.runSpeed();
        stepperLB.runSpeed();
    }

    stepperRF.setSpeed(-100);
    stepperLF.setSpeed(-100);
    stepperRB.setSpeed(-100);
    stepperLB.setSpeed(-100);

    while (digitalRead(PIN_LIMIT_Y)) {
        stepperRF.runSpeed();
        stepperLF.runSpeed();
        stepperRB.runSpeed();
        stepperLB.runSpeed();
    }

    stepperRF.setCurrentPosition(0);
    stepperLF.setCurrentPosition(0);
    stepperRB.setCurrentPosition(0);
    stepperLB.setCurrentPosition(0);

    currentX = currentY = currentR = 0;
}

void moveTo(float x, float y, float r) {
    float dx = x - currentX;
    float dy = y - currentY;
    float dr = r - currentR;

    stepperRF.move(-dx * STEPS_PER_MM_X + dy * STEPS_PER_MM_Y - dr * STEPS_PER_DEG_R);
    stepperLF.move( dx * STEPS_PER_MM_X + dy * STEPS_PER_MM_Y + dr * STEPS_PER_DEG_R);
    stepperRB.move( dx * STEPS_PER_MM_X + dy * STEPS_PER_MM_Y - dr * STEPS_PER_DEG_R);
    stepperLB.move(-dx * STEPS_PER_MM_X + dy * STEPS_PER_MM_Y + dr * STEPS_PER_DEG_R);

    while (stepperRF.isRunning() || stepperLF.isRunning() ||
           stepperRB.isRunning() || stepperLB.isRunning()) {
        stepperRF.run();
        stepperLF.run();
        stepperRB.run();
        stepperLB.run();
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