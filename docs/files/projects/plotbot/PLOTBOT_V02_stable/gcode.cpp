#include <Arduino.h>
#include "gcode.h"
#include "motion.h"

void gcodeInit() {}

void parseAndExecute(const String& cmd) {
    String c = cmd;
    c.trim();
    c.toUpperCase();

    if (c.startsWith("G28")) {
        homeAxes();
        return;
    }

    if (!c.startsWith("G1")) return;

    float x = currentX;
    float y = currentY;
    float r = currentR;

    int zi = c.indexOf('Z');
    if (zi != -1) setServoZ(c.substring(zi + 1).toInt());

    int xi = c.indexOf('X');
    if (xi != -1) x = c.substring(xi + 1).toFloat();

    int yi = c.indexOf('Y');
    if (yi != -1) y = c.substring(yi + 1).toFloat();

    int ri = c.indexOf('R');
    if (ri != -1) r = c.substring(ri + 1).toFloat();

    moveTo(x, y, r);
}