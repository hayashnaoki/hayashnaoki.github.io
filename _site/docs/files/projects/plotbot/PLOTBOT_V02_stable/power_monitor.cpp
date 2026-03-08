#include <Arduino.h>
#include "pins.h"
#include "config.h"
#include "power_monitor.h"

float readVSYS() {
    uint16_t raw = analogRead(PIN_ADC_VSYS);
    return (raw * 3.3f / 4095.0f) * VSYS_DIVIDER;
}

void powerInit() {
    analogReadResolution(12);
    pinMode(PIN_ADC_VBAT, INPUT);
    pinMode(PIN_LED, OUTPUT);
}

float readVBAT() {
    digitalWrite(PIN_STATUS_LED, HIGH);

    uint16_t raw = analogRead(PIN_ADC_VBAT);
    float v_adc = raw * 3.3f / 4095.0f;
    float v_bat = v_adc * 4.3f;   // 10k + 33k divider
    if (v_bat < 6.0f) v_bat = 0.0f;     // battery not present

    Serial.print("VBAT: ");
    Serial.print(v_bat, 3);
    Serial.println(" V");

    digitalWrite(PIN_STATUS_LED, LOW);
    return v_bat;
}