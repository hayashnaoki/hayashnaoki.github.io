---
layout: default
---

# PLOT BOT

2025-ongoing \| Digital fabrication \| Prototype

## Mecanum wheeled pen plotter with infinite plotting area

The project started as a final project of [Fab Academy](https://fabacademy.org/) 2025. This is a mobile pen plotter with mecanum wheels, capable of drawing over an area much larger than its body. It uses a Raspberry Pi Pico to parse G-code via serial communication, controlling four wheels, stepper motors, and a Z-axis servo, with end stops for homing. I have learned everything from project management and mechanical and electronics design to PCB fabrication, and assembly.

### V0.1: Proof of concept

[Fab Academy repository](https://fabacademy.org/2025/labs/kannai/students/naoki-hayashi/projects/01_Final_project/final-project_00/)

![](/docs/images/projects/plotbot/plotbot.jpg)

<iframe 
  src="https://player.vimeo.com/video/1164902224?badge=0&autopause=0&player_id=0&app_id=58479" 
  width="100%" 
  height="auto" 
  style="aspect-ratio:16/9;" 
  frameborder="0" 
  allow="autoplay; fullscreen; picture-in-picture; clipboard-write; encrypted-media; web-share" 
  referrerpolicy="strict-origin-when-cross-origin" 
  title="PLOTBOT V0.1">
</iframe>

### Implications

The idea started from a simple curiosity: could a machine print or draw things bigger than itself? Traditional 3D printers are limited by their fixed frames. This machine moves freely in X and Y directions using omni-wheels, and could later add a Z-axis arm for height. In the future, it might even be able to climb onto its own printed objects and keep building—making truly large-scale 3D printing possible.

### Next spirals

1. Improvements as a pen plotter
  - Add absolute tracking for position correction
  - Enable wireless control and battery power
1. Learn and incorporate 3D printing technologies
  - Improve Z-axis design for 3D printing
  - Learn 3D printing through building filament recycling machine
  - Learn 3D printing firmware
1. System integration: PRINT BOT V1.0
  - Integrate filament feeding system and extruder

---

## V0.2

V0.2 focuses on 2 goals:

1. Making the machine wireless
    - A 12 V 6000 mAh Li-ion battery directly powers the A4988 motor drivers
    - Battery voltage is monitored by the Pico's ADC via voltage divider
    - A LM2596 buck converter module converts 12 V to 5 V for the Pico
1. Improving expandability
    - UART, I2C, SPI, and extra GPIOs are available for easy expansion such as additional micro controller (e.g., ESP32-S3), an OLED display, sensors, limit switches, a fan, or a servo
    - In this setup, the Pico works as the "spine", and a wirelessly connected PC or additional micro controller works as the "brain"

![](/docs/images/projects/plotbot/system_diagram.jpg)
