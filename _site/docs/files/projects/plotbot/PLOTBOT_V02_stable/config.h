#pragma once

// Motion calibration
constexpr float STEPS_PER_MM_X  = 17.95f;
constexpr float STEPS_PER_MM_Y  = 17.00f;
constexpr float STEPS_PER_DEG_R = 45.50f;

// Motion limits
constexpr int MAX_SPEED     = 1500; //1500
constexpr int ACCELERATION  = 1500; //2000
constexpr int HOMING_SPEED  = 200;
constexpr int BACK_OFF_STEPS = 500;

// Servo
constexpr int SERVO_MIN_US = 500;
constexpr int SERVO_MAX_US = 2400;
constexpr int SERVO_DEFAULT_ANGLE = 120;

// Power
constexpr float VBAT_DIVIDER = 5.7f;
constexpr float VSYS_DIVIDER = 3.0f;

// System
constexpr unsigned long INACTIVITY_TIMEOUT = 5000;