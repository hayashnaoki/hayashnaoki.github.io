---
layout: default
---

# 2. Software design

>
Back to [PLOT BOT](index)  
[1. Hardware design](hardware)  
[3. Production](production)  
[4. BOM and files](bom_files)  

## Goals
1. Modular Architecture: Organize firmware into abstract, decoupled layers.
2. Coordinated Motion: Implement linear interpolation to ensure smooth, straight-line multi-axis movements.

## Architecture Overview

### Firmware Layers

To keep the main orchestration file (`.ino`) clean and focused, the codebase is split into dedicated hardware abstraction layers using header (`.h`) and source (`.cpp`) files.

| Layer | Component / File | Role | Input to Output |
| --- | --- | --- | --- |
| Orchestration | `PLOTBOT_V02.ino` | Manages top-level application state, sleep modes, inactivity timeouts, and loops peripheral checking. | Raw data / serial characters to Triggers for execution and states |
| Application | G-code Parser (`gcode.cpp`) | Directs programmatic intent. Discovers commands, tokenizes strings, and extracts target coordinates. | Command string (G1 X100 Y200) to Numerical targets (X, Y, R, Z) |
| Trajectory | Motion Control (`motion.cpp`) | Implements linear interpolation. Scales velocity and acceleration curves to guarantee straight paths. | Target position coordinates to Synchronized motor speed profiles |
| Kinematics | Wheel Mapping (`motion.cpp`) | Handles vehicle geometry. Transforms cartesian vectors into individual physical wheel rotations. | Coordinated movement vectors to Step targets per motor (M1, M2, M3) |
| Hardware | Abstraction (`pins.h`, `config.h`) | Configures static pin parameters, microstepping outputs, and handles real-time driver pulse execution. | Motor step requirements to Electronic pulses and hardware movement |

<img src="/docs/images/projects/plotbot/dependencies.jpg" style="width: 600px;" alt="Software Dependency Diagram">

## A. Main Orchestration
`PLOTBOT_V02.ino`

[Placeholder: Detailed breakdown of the Main Orchestration (.ino) file loop, sleep states, and power-saving logic goes here]

## B. G-code Parsing & Execution
`gcode.cpp`

[Placeholder: 3. G-code Parsing & Execution Subsystem (gcode.cpp)]

Detailed explanation of string tokenization, command isolation (G0, G1, G28), and parameter extraction.

## C. Motion Control
`motion.cpp`

The core of PlotBot's physical movement is handled within motion.cpp, which translates abstract target coordinates into precise, synchronized stepper motor pulses.

### 1. Omni-Wheel Kinematics
PlotBot uses a 3-wheel omnidirectional chassis. This requires mapping target Cartesian movements (dx, dy) and rotation (dr) into individual motor step targets.

```cpp
float steps1 = -dx * 0.866025f * STEPS_PER_MM_X + dy_corr * 0.5f * STEPS_PER_MM_Y - dr * STEPS_PER_DEG_R;
float steps2 =  dx * 0.866025f * STEPS_PER_MM_X + dy_corr * 0.5f * STEPS_PER_MM_Y + dr * STEPS_PER_DEG_R;
float steps3 =  dx * STEPS_PER_MM_X * M3_X_SCALE + dr * -STEPS_PER_DEG_R;
```

- The Y-Axis Component (sin 30 degrees = 0.5): M1 and M2 are angled relative to the forward direction; only 50 percent of their rotation contributes to forward/backward (Y) motion.
- The X-Axis Component (cos 30 degrees = 0.866025): Because of their mounting angles, 86.6 percent of M1 and M2's rotation translates into horizontal (X) translation.
- The Passive Axis (M3): Because M3 is mounted perfectly sideways, it is mathematically isolated from Y-axis movements, rolling passively on its sub-rollers during forward/backward motion.

| Motor | +X Movement (Right) | +Y Movement (Forward) | +R Rotation (Clockwise) | Theoretical Formula |
| --- | --- | --- | --- | --- |
| M1 (Front Left) | Counter-Clockwise | Clockwise | Counter-Clockwise | -0.866 * dx + 0.5 * dy - dr |
| M2 (Front Right) | Clockwise | Clockwise | Clockwise | +0.866 * dx + 0.5 * dy + dr |
| M3 (Back) | Clockwise | Static (0) | Counter-Clockwise | +1.0 * dx + 0 * dy - dr |

### 2. Linear Interpolation & Coordinated Motion

Without proper interpolation, multi-axis moves execute unevenly, resulting in jagged, staggered paths.

To achieve true straight-line linear interpolation (G1), motion.cpp dynamically scales the maximum speed and acceleration of each motor. This ensures all motors start and stop exactly at the same time, regardless of how many steps each individual motor needs to take.

1. Identify the dominant axis: Find the maximum step count required by any single motor.

    ```cpp
    float maxSteps = max(abs(steps1), max(abs(steps2), abs(steps3)));
    ```
    
2. Calculate proportional scaling factors: Determine each motor's travel distance relative to the dominant axis (scale value between 0 and 1).
    
    ```cpp
    float scale1 = abs(steps1) / maxSteps;
    ```
    
3. Scale Speeds and Accelerations: Constrain the AccelStepper parameters dynamically before execution so that slower motors step proportionally to the fastest one.C++
    
    ```cpp
    stepperM1.setMaxSpeed(max(MAX_SPEED * scale1, 1.0f));
    stepperM1.setAcceleration(max(ACCELERATION * scale1, 1.0f));
    ```

<img src="/docs/images/projects/plotbot/interpolation.jpg" style="width: 600px;" alt="">

Ref: 

- [RepRap G-code](https://reprap.org/wiki/G-code#G0_.26_G1:_Move)
- [CNC Cookbook G00 and G01 G-Code Mastery](https://www.cnccookbook.com/g00-g01-cnc-g-code/)

### 3. Empirical Drift Compensation

Real-world physical systems rarely match idealized mathematics perfectly. Mechanical tolerances, sub-roller friction, and structural weight distribution require empirical adjustments to eliminate drift.

1. Motor 3 Scaling (M3_X_SCALE = 1.85f)
    - The Problem: When moving purely in the X direction, the combined drag/force of M1 and M2 does not naturally match the output of M3, causing the machine to rotate unintentionally.
    - The Fix: Scales M3's contribution during horizontal travel to balance the physical force vector.C++
    
    ```cpp
    float steps3 = dx * STEPS_PER_MM_X * M3_X_SCALE + dr * -STEPS_PER_DEG_R;
    ```
1. Cross-Talk Compensation (X_Y_DRIFT_COMPENSATION = 0.02f)
    - The Problem: Pure horizontal (X) movements can trigger minor, unintended tracking errors along the Y-axis due to directional traction differences in omni-wheel sub-rollers.
    - The Fix: Dynamically introduces a minor Y-axis correction step proportional to the absolute distance traveled in X.C++
    
    ```cpp
    float abs_dx = (dx >= 0.0f) ? dx : -dx;
    float dy_corr = dy + abs_dx * X_Y_DRIFT_COMPENSATION;
    ```

## D. Telemetry & Peripheral Control
`display.cpp` and `power_monitor.cpp`

[Placeholder: 4. Telemetry & Peripheral Control (display.cpp and power_monitor.cpp)]

Detailed breakdown of the SSD1306 OLED interface, system/battery voltage monitoring via integrated ADCs, and hardware safety routines.


<!---
## Goals

1. Organize the code into abstract layers
1. Implement linear interpolation

## Embedded programming

### Layers

| Layer | Role (abstract) | Input → Output |
| --- | --- | --- | --- |
| 1. G-code & Intent | Describes what motion is desired, independent of hardware | `G1 X100 Y200` → Target pose + path type |
| 2. Interpolation | Converts geometric intent into a time-parameterized reference | Target pose → Trajectory `x(t), y(t), θ(t)` |
| 3. Correction | Aligns reference motion with estimated actual state | Trajectory + pose estimate → Body velocity `(Vx, Vy, ω)` |
| 4. Omni wheel kinematics | Maps body motion into actuator commands → `(Vx, Vy, ω)` | Motor commands `(ω1..ω4)` |

- The Arduino code was split according to the layers and others functions
- By adding header (`.h`) and source (`.cpp`) files, the `.ino` file focus on orchestration
- `pins.h` and `config.h` for hardware abstraction

<img src="/docs/images/projects/plotbot/dependencies.jpg" style="width: 800px;" alt="">



### A. Omni wheel kinematics

``` cpp
float stepsM1 = -dx * 0.866025f * STEPS_PER_MM_X + dy * 0.5f * STEPS_PER_MM_Y - dr * STEPS_PER_DEG_R;
float stepsM2 =  dx * 0.866025f * STEPS_PER_MM_X + dy * 0.5f * STEPS_PER_MM_Y + dr * STEPS_PER_DEG_R;
```
- `0.5` (`sin 30°`): Only `50 %` of their rotation contributes to moving forward or backward.
- `0.866025` (`cos 30°`): Since M1 and M2 are angled, only `86.6 %` of their rotation contributes to moving left or right.

``` cpp
float stepsM3 =  dx * STEPS_PER_MM_X + dr * STEPS_PER_DEG_R;
```
- Because M3 is perfectly sideways, it cannot help or hinder `Y` movement at all mathematically.

| Motor | When moving +X (Right) | When moving +Y (Forward) | When moving +R (Clockwise) | Theoretical Formula Component |
| --- | --- | --- | --- | --- |
| M1 (Front Left) | CCW (M1 and M2's Y components cancel each other) | Forward (CW) | Backward (CCW)| −0.866⋅dX+0.5⋅dY−dR |
| M2 (Front Right) | Forward (CW)Pushes diagonally forward-right. | Forward (CW)Pushes diagonally forward-right.| Forward (CW)Rotates the chassis clockwise. | +0.866⋅dX+0.5⋅dY+dR |
| M3 (Back) | Forward (CW)Pushes directly right. | Stopped (0)Rolls passively on its sub-rollers. | Forward (CW)Rotates the tail to the right (spinning nose right). | +1.0⋅dX+0⋅dY+dR |

### B. Compensation

These are additional compensations ​​to offset the actual drift from the theoretical value.

1. M3 scale: `M3_X_SCALE = 1.85f`
    - To balance the M1 + M2 motors and M3 when moving in the X direction
    - Without this, the M3 motor drag the machine and causes rotational drifting

    ``` cpp
    float steps3 =  dx * STEPS_PER_MM_X * M3_X_SCALE + dr * STEPS_PER_DEG_R;
    ```
1. X/Y drift compensation: `X_Y_DRIFT_COMPENSATION = 0.02f`
    - To cancel out the imbalance between clockwise and counterclockwise rotation
    - Without this, the cancellation of the Y-direction components of the M1 and M2 motors becomes uneven, resulting in a slight drift in the Y-direction.

    ``` cpp
    float abs_dx = (dx >= 0.0f) ? dx : -dx;
    float dy_corr = dy + abs_dx * X_Y_DRIFT_COMPENSATION;
    ```


### C. Interpolation

- Without interpolation (V0.1), a move like `[X100 Y200]` is executed as `[X100 Y100]` > `[Y200]`
- With linear interpolation (`G1`), the X and Y motor speeds are continuously adjusted for linear path from `[0, 0]` to `[X100 Y200]`
- Arc interpolation (`G2/G3`), `I` and `J` represent center offset from the start point.

<img src="/docs/images/projects/plotbot/interpolation.jpg" style="width: 800px;" alt="">

1. Geometric interpolation (Position-based)
    - e.g., Move 0.01 mm each update
1. Time-based interpolation
    - e.g., Compute next position very 1 ms

Formula: `Position(Time) = Start + Time * (Total change)`

```
P0 = (x0, y0)
P1 = (x1, y1)

P(s) = (1 − s)·P0 + s·P1
P(s) = P0 + s·(P0 - P1)

x(s) = x0 + s·(x1 − x0)
y(s) = y0 + s·(y1 − y0)
```

Ref: 

- [RepRap G-code](https://reprap.org/wiki/G-code#G0_.26_G1:_Move)
- [CNC Cookbook G00 and G01 G-Code Mastery](https://www.cnccookbook.com/g00-g01-cnc-g-code/)

## Application programming

--->
