---
layout: default
---

# 3. Production

>
Back to [PLOT BOT](index)  
[1. Hardware](hardware)  
[2. Software](software)  
[4. BOM and files](bom_files)  

## Goals

1. Fab-able
    - CNC milling double-sided PCB
    - 3D printable frame wheels

## Electronics production

The custom PCB was fabricated using a CNC milling machine at FabLab Kannai. Since the board is double-sided, a flipping process was required while aligning the top and bottom layers. That was achieved using "Gerber2Png" developed by FabLab Kerala. 

> Detailed process: [Fab Academy documentation](https://fabacademy.org/2025/labs/kannai/students/naoki-hayashi/projects/02_Second_spiral/01_electronics_design/#2-electronics-production)  
Ref: [Gerber2Png](https://gerber2png.fablabkerala.in/) / [Documentation](https://git.fablabkerala.in/midlaj/gerber2png/-/wikis/home)  

### PCB milling

Alignment cut

![](/docs/images/projects/plotbot/milling_top.jpg)

Bottom side

<div class="media-wrapper">
    <video src="/docs/images/projects/plotbot/milling.mp4"
    autoplay
    loop
    muted>
    playsinline></video>
</div>

Soldered

![](/docs/images/projects/plotbot/board_top.jpg)

![](/docs/images/projects/plotbot/board_bottom.jpg)

Board test

<div class="media-wrapper">
    <video src="/docs/images/projects/plotbot/board_test.mp4"
    autoplay
    loop
    muted>
    playsinline></video>
</div>

## Machine building

### Frame

### Mecanum wheel

TPU printing for the rollers

[TINMORRY TPU](https://tinmorry.net/en-jp/products/filament-tpu-1-75-mm-tinmorry-3d-printing-materials-tpu-filament-for-fdm-3d-printer-1-kg-1-spool-black?srsltid=AfmBOoqwXkjCUYJ0XjtRtM4RGYZ3RPq6oBJl7ol4-Ket09vFCg_WA8Nv): Shore hardness: 95A

Ref.
- [Bambu Lab Wiki - TPU printing](https://wiki.bambulab.com/en/knowledge-sharing/tpu-printing-guide)
- [TINMORRY filament profile for Bambu](https://github.com/TINMORRY/TINMORRY-filament-profile-for-Bambu-printers/blob/main/TPU(A1mini-Bambu-TINMORRY).json)
- [Bambu Lab Wiki - Cold pull](https://wiki.bambulab.com/en/x1/maintenance/what-is-cold-pull-and-how-to-perform-it)
