---
layout: default
---

# V0.2 Software

>
Back to [PLOT BOT](index)  
Go to [V0.2 Hardware](hardware)  

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
| 4. Mecanum kinematics | Maps body motion into actuator commands → `(Vx, Vy, ω)` | Motor commands `(ω1..ω4)` |

- The Arduino code was split according to the layers and others functions
- By adding header (`.h`) and source (`.cpp`) files, the `.ino` file focus on orchestration
- `pins.h` and `config.h` for hardware abstraction

![](/docs/images/projects/plotbot/dependencies.jpg)

### Interpolation

- Without interpolation (V0.1), a move like `[X100 Y200]` is executed as `[X100 Y100]` > `[Y200]`
- With linear interpolation (`G1`), the X and Y motor speeds are continuously adjusted for linear path from `[0, 0]` to `[X100 Y200]`
- Arc interpolation (`G2/G3`), `I` and `J` represent center offset from the start point.

![](/docs/images/projects/plotbot/interpolation.jpg)

Formula: `Position(Time) = Start + (Total change) * Time`

```
P0 = (x0, y0)
P1 = (x1, y1)

P(s) = (1 − s)·P0 + s·P1
P(s) = P0 + s·(P0 - Y0)

x(s) = x0 + s·(x1 − x0)
y(s) = y0 + s·(y1 − y0)
```

Ref: 

- [RepRap G-code](https://reprap.org/wiki/G-code#G0_.26_G1:_Move)
- [CNC Cookbook G00 and G01 G-Code Mastery](https://www.cnccookbook.com/g00-g01-cnc-g-code/)

### Mecanum kinematics

## Files

>
[Arduino]()  
[Processing]()  
