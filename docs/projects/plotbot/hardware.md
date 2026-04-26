---
layout: default
---

# 1. Hardware design

>
Back to [PLOT BOT](index)  
[2. Software design](/docs/projects/plotbot/software)  
[3. Production](production)  
[4. BOM and files](bom_files)  

## Goals

1. Making the machine wireless/battery powered
    - Add a safety circuit and battery monitoring
1. Improving expandability
1. Making the machine compact
1. Improve robustness
    - Resistant to external impacts

## Electronics design

- A 12 V 6000 mAh Li-ion battery directly powers the A4988 motor drivers
- Battery voltage is monitored by the Pico's ADC via voltage divider
- A LM2596 buck converter module converts 12 V to 5 V for the Pico
- UART, I2C, SPI, and extra GPIOs are available for easy expansion such as additional micro controller (e.g., ESP32-S3), an OLED display, sensors, limit switches, a fan, or a servo
- In this setup, the Pico works as the "spine", and a wirelessly connected PC or additional micro controller works as the "brain"

<img src="/docs/images/projects/plotbot/system_diagram.jpg" style="width: 800px;" alt="">

### Schematics

![](/docs/images/projects/plotbot/V0.2_schematics_pico.png)

![](/docs/images/projects/plotbot/V0.2_schematics_driver.png)

### PCB

- Double-sided (LM2596 mounted at the bottom)

![](/docs/images/projects/plotbot/PCB_top.jpg)

### Pinout

![](/docs/images/projects/plotbot/pinout.jpg)

## Mechanical design

The original mecanum wheels lacked the necessary precision, and more accurate alternatives were either too expensive or too bulky. I also wanted to compare both mecanum and omni types, so I decided to switch to a 120-degree triple omni-wheel configuration for this build.

1. Modeling strategy (F3D)
    - Use external/internal components
    - Ref: [Fusion 360 Components and Assemblies Explained](https://youtu.be/kj3_doWX2Kg?si=Wuf_BjsMH80fZwv-)
1. Component layout
    - The 6000 mAh battery at the center bottom between the motors
    - The minimum dimensions defined by the four motors and the battery  
1. Frame: Topology optimization  
    Instead of using Fusion 360's generative design features, I decided to optimize the frame using [Grasshopper tOpos](https://www.food4rhino.com/en/app/topos).
    - Boundary: box excluding space for components
    - Loads: battery, PCB etc.
    - Support: Mounting points for the motors
    - Ref: [Topology Optimization 101](https://formlabs.com/blog/topology-optimization/?srsltid=AfmBOop-21FSWjzrRfT_V_dcDMQh743sqI0DHfcjQxuELNHLn6EK_Idw)
    - `IsoMesh` > `Quad Remesh` > `SubD from Mesh` > Export as STEP > Import into F3D

    <div class="image-grid">
    <a class="grid-item">
        <div class="image-wrapper">
        <img src="/docs/images/projects/plotbot/tOpos.jpg" alt="">
        </div>
    </a>

    <a class="grid-item">
        <div class="media-wrapper">
        <video src="/docs/images/projects/plotbot/tOpos.mp4"
            autoplay
            muted
            loop
            playsinline></video>
        </div>
    </a>
    </div>

## Industrial design
Using the topology optimization results as a reference, I designed the machine to convey a sense of refined complexity and an intelligent aesthetic.

![](/docs/images/projects/plotbot/frame_sketch.jpg)

<div class="media-embed">
  <iframe 
    src="https://gmail4741456.autodesk360.com/shares/public/SH28cd1QT2badd0ea72be0ccbab005fc1d79?mode=embed"
    width="100%"
    height="800"
    allowfullscreen
  ></iframe>
</div>

| Imported models | Sources |
| --- | --- |
| [NEMA17 Stepper Motor](https://www.mcmaster.com/6627T66/) | McMaster |
| [58mm Double Row Omni-Wheel](https://grabcad.com/library/omniwheel-15) (modified) | GrabCAD |
| [SG90 Micro Servo](https://grabcad.com/library/sg90-micro-servo-9g-tower-pro-1) | GrabCAD |
| [Pi Pico](https://grabcad.com/library/raspberry-pi-pico-3) | GrabCAD |
| [LM2596](https://www.autodesk.com/community/gallery/project/165596/lm2596-dc-dc) | Autodesk Community |
| [A4988](https://grabcad.com/library/a4988-stepper-driver-with-pins-socketed-1) | GrabCAD |