#include "pins.h"
#include "config.h"
#include "motion.h"
#include "gcode.h"
#include "power_monitor.h"
#include "display.h"

String input;

unsigned long lastCommandTime = 0;

void setup() {
    Serial.begin(14101);
    analogReadResolution(12);

    motionInit();
    gcodeInit();
    displayInit();
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.println("VBAT monitor started");

    Serial.println("PlotBot ready");

    pinMode(EN_PIN, OUTPUT);
    digitalWrite(EN_PIN, LOW);
    lastCommandTime = millis();
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    float vbat = readVBAT();
    float vsys = readVSYS();
    digitalWrite(LED_BUILTIN, LOW);
    displayVoltages(vbat, vsys);
    delay(1000);

    while (Serial.available()) {
        digitalWrite(EN_PIN, LOW);     // enable drivers
        char c = Serial.read();
        if (c == '\n' || c == '\r') {
            if (input.length()) {
                parseAndExecute(input);
                input = "";
                Serial.println("ok");
            }
        } else {
            input += c;
        }
    }

    delay(1000);

    // Sleep mode
    if (millis() - lastCommandTime > INACTIVITY_TIMEOUT) {
        digitalWrite(EN_PIN, HIGH);     // disable drivers
    }
}