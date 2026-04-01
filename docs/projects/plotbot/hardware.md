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

![](/docs/images/projects/plotbot/system_diagram.jpg)

### Schematics

![](/docs/images/projects/plotbot/V0.2_schematics_pico.png)

![](/docs/images/projects/plotbot/V0.2_schematics_driver.png)

### PCB

- Double-sided (LM2596 mounted at the bottom)

![](/docs/images/projects/plotbot/PCB_top.jpg)

### Pinout

![](/docs/images/projects/plotbot/pinout.jpg)

## Mechanical design

1. Modeling strategy (F3D)
    - Use external/internal components
    - Ref: [Fusion 360 Components and Assemblies Explained](https://youtu.be/kj3_doWX2Kg?si=Wuf_BjsMH80fZwv-)
1. Component layout
    - The 6000 mAh battery at the center bottom between the motors
    - The minimum dimensions defined by the four motors and the battery  
1. Frame: Topology optimization ([Grasshopper tOpos](https://www.food4rhino.com/en/app/topos))
    - Boundary: box excluding space for components
    - Loads: battery, PCB etc.
    - Support: Mounting points for the motors
    - Ref: [Topology Optimization 101](https://formlabs.com/blog/topology-optimization/?srsltid=AfmBOop-21FSWjzrRfT_V_dcDMQh743sqI0DHfcjQxuELNHLn6EK_Idw)
    - `IsoMesh` > `Quad Remesh` > `SubD from Mesh` > Export as STEP > Import into F3D

    ![](/docs/images/projects/plotbot/tOpos.jpg)

<div class="media-embed">
  <iframe 
    src="https://gmail4741456.autodesk360.com/shares/public/SH28cd1QT2badd0ea72be0ccbab005fc1d79?mode=embed"
    width="100%"
    height="600"
    allowfullscreen
  ></iframe>
</div>

---

## Industrial design

- Simplify the TO results
- Slightly rounded base surface for appearance quality
