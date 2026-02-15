---
layout: default
---

# V0.2 Hardware

>
Back to [PLOT BOT](index)  
Go to [V0.2 Software](software)  

## Goals

1. Making the machine wireless/battery powered
    - Add a safety circuit and battery monitoring
1. Improving expandability
1. Making the machine compact

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

### BOM


| Category | Name | Value | Package | Fusion Library | Qty | Link |
| --- | --- | --- | --- | --- | --- | --- |
| MCU | Raspberry Pi Pico | - | PICO-PKG-TH | [RPI-Pico-Eagle-lib](https://github.com/Lobo-T/RPI-Pico-Eagle-lib), RASPBERRY_PICOTH | 1 | [Akizuki](https://akizukidenshi.com/catalog/g/g116132/) |
| Motor Driver | A4988 stepper motor driver carrier | - | - | [Eagle-Library-Pololu (unofficial)](https://github.com/suzakulab/Eagle-Library-Pololu/tree/master), 1182-A4988 | 4 | [Switch-Science](https://www.switch-science.com/products/582) |
| Protection | Mini blade fuse & holder | 32V, 15A | - | Custom made | 1 | [AliExpress](https://ja.aliexpress.com/item/1005006954864680.html) |
|  | SBR diode (Schottky) | Peak Withstand Voltage: 30V, Average Forward Current: 15A | SBR15U30SP5 | Custom made | 1 | [Akizuki](https://akizukidenshi.com/catalog/g/g107391/) |
|  | TVS Diode | Bidirectional, VRWM: 45 V, VBR: 50–55.3 V, Peak Pulse Power: 400 W | TVS_SMBJ45CA | Custom made | 1 | [Akizuki](https://akizukidenshi.com/catalog/g/g107410/) |
| Regulator | LM2596 buck converter module | In: 3.0 ~ 40V, out: 1.5〜35V | - | Custom made | 1 | [AliExpress](https://ja.aliexpress.com/item/1005003629985077.html?spm=a2g0o.detail.pcDetailTopMoreOtherSeller.3.21ac2Cjd2CjdYc&gps-id=pcDetailTopMoreOtherSeller&scm=1007.40050.354490.0&scm_id=1007.40050.354490.0&scm-url=1007.40050.354490.0&pvid=882146ee-068b-4095-9065-ea0445588905&_t=gps-id:pcDetailTopMoreOtherSeller,scm-url:1007.40050.354490.0,pvid:882146ee-068b-4095-9065-ea0445588905,tpp_buckets:668%232846%238111%231996&pdp_ext_f=%7B%22order%22%3A%2238%22%2C%22eval%22%3A%221%22%2C%22sceneId%22%3A%2230050%22%2C%22fromPage%22%3A%22recommend%22%7D&pdp_npi=6%40dis%21JPY%21108%2146%21%21%210.68%210.29%21%402101246417644793887896009ee347%2112000026569221043%21rec%21JP%212916345207%21XZ%211%210%21n_tag%3A-29919%3Bd%3A8b25bf9%3Bm03_new_user%3A-29895&utparam-url=scene%3ApcDetailTopMoreOtherSeller%7Cquery_from%3A%7Cx_object_id%3A1005003629985077%7C_p_origin_prod%3A) |
| Capacitors | Electrolytic capacitor (bulk)  | 35V, 220µF | CAPAE830X1050N | C-POL-US_ECAP-8.5MM | 6 | [AliExpress](https://ja.aliexpress.com/item/1005008827159096.html) |
|  | Ceramic Capacitor | 0.1µF | CAPC3216X135 | C-US_CHIP-1206(3216-METRIC) | 3 | ↑ |
| Resistors | Voltage divider | 33kΩ | R1206 | R-US_R1206 | 1 | [AliExpress](https://ja.aliexpress.com/item/1005008789698065.html) |
|  | Pull-down / divider | 10kΩ | R1206 | R-US_R1206 | 4 | ↑ |
| Pin Headers | Raspberry Pi Pico connection | - | 1×20SMD, 2.54mm pitch, square | pinhead-2, PINHD-1X20_2.54-SMD | 2 | ↑ |
|  | Microstepping selection | - | 1×09SMD | ↑ | 1 | ↑ |
|  | Stepper connections | - | 1×08SMD | ↑ | 8 | ↑ |
|  | Motor driver logic pins | - | 1×04SMD | ↑ | 4 | ↑ |
|  | I²C / UART / SPI / GPIO expansion | - | 2×13SMD | ↑ | 1 | ↑ |
| Terminal block | Power switch / Battery connector | - | 1×2, 3.5mm pitch, straight, 300V, 10A | Adafruit, 1X2-3.5MM | 2 | [AliExpress](https://ja.aliexpress.com/item/10000004364694.html?spm=a2g0o.order_list.order_list_main.17.24f8585aMSQVdT&gatewayAdapt=glo2jpn) |
| Li-ion Battery Pack | 12V ~6000mAh Li-ion battery with BMS | 12V, 6000mAh | 3S2P | - | 1 | [Amazon](https://www.amazon.co.jp/gp/product/B0FBGFS16S) |
| Stepper motor | Nema17 (W/H 42 mm) | Standard (L 37 mm) | - | - | 4 | - |

## Mechanical design

1. Modeling strategy (F3D)
    - Use external/internal components
    - [Fusion 360 Components and Assemblies Explained](https://youtu.be/kj3_doWX2Kg?si=Wuf_BjsMH80fZwv-)
1. Component layout
    - The 6000 mAh battery at the center bottom between the motors
    - The minimum dimensions defined by the four motors and the battery  
1. Topology optimization (Grasshopper tOpos)
    - Boundary: box excluding space for components
    - Loads: battery, PCB etc.
    - Support: Mounting points for the motors


## Files

>
[Schematics (PDF)]()  
[PCB (PNG)]()  
[CAD (F3D)]()  
[3D print (Printables)]()  