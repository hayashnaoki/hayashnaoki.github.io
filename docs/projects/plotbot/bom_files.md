---
layout: default
---

# 4. BOM and files

>
Back to [PLOT BOT](index)  
[1. Hardware design](hardware)  
[2. Software design](software)  
[3. Production](production)  

## BOM

### Electronics components

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
|  | Stepper connections | - | 1×08SMD | ↑ | 8 | ↑ |
|  | Motor driver logic pins | - | 1×04SMD | ↑ | 4 | ↑ |
|  | I²C / UART / SPI / GPIO expansion | - | 2×20SMD | ↑ | 1 | ↑ |
| Terminal block | Power switch / Battery connector | - | 1×2, 3.5mm pitch, straight, 300V, 10A | Adafruit, 1X2-3.5MM | 2 | [AliExpress](https://ja.aliexpress.com/item/10000004364694.html?spm=a2g0o.order_list.order_list_main.17.24f8585aMSQVdT&gatewayAdapt=glo2jpn) |
| Li-ion Battery Pack | 12V ~6000mAh Li-ion battery with BMS | 12V, 6000mAh | 3S2P | - | 1 | [Amazon](https://www.amazon.co.jp/gp/product/B0FBGFS16S) |
| Stepper motor | Nema17 (W/H 42 mm) | Standard (L 37 mm) | - | - | 4 | [AliExpress](https://ja.aliexpress.com/i/32376023464.html?gatewayAdapt=glo2jpn) |
| Servo motor | SF180M | 180° | - | - | 1 | [Akiduki](https://akizukidenshi.com/catalog/g/g108761/) |

## Files

>
[Schematics (PDF)]()
[PCB mill files (PNG)]()    
[CAD (F3D)]()  
[3D print (Printables)]()  
[Arduino]()  
[Processing]()  