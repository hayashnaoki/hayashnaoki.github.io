#pragma once

// UART
#define PIN_UART_TX 0
#define PIN_UART_RX 1

// I2C
#define PIN_I2C_SDA 2
#define PIN_I2C_SCL 3

// SPI
#define PIN_SPI_MISO 4
#define PIN_SPI_CS 5
#define PIN_SPI_SCK 6
#define PIN_SPI_MOSI 7

// General GPIO
#define PIN_GPIO_8 8
#define PIN_GPIO_9 9
#define PIN_GPIO_10 10
#define PIN_GPIO_11 11
#define PIN_GPIO_13 13

// Servo
#define PIN_SERVO_Z 12

// Limit switches
#define PIN_LIMIT_X 14
#define PIN_LIMIT_Y 15

// A4988 drivers - 3 Omni wheels (120 degree)
#define PIN_DIR_M1 16 // Front Right
#define PIN_STEP_M1 17
#define PIN_STEP_M3 18 // Back
#define PIN_DIR_M3 19
#define PIN_STEP_SPARE 20 // Spare driver
#define PIN_DIR_SPARE 21
#define PIN_DIR_M2 22 // Front Left
#define PIN_STEP_M2 27
#define EN_PIN 28

// ADC
#define PIN_ADC_VBAT 26
#define PIN_ADC_VSYS 29

// Build-in LED
#define PIN_STATUS_LED LED_BUILTIN