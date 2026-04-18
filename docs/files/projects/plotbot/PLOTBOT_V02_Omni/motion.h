#pragma once

void motionInit();
void homeAxes();
void executeG1(float x, float y, float r);
void moveLinear(float targetX, float targetY, float targetR, float step_mm);
void moveTo(float x, float y, float r);
void setServoZ(int angle);

extern float currentX;
extern float currentY;
extern float currentR;
extern int currentZ;