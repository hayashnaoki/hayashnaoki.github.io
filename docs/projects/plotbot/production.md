---
layout: default
---

# 3. Production

>
Back to [PLOT BOT](index)  
[1. Hardware design](hardware)  
[2. Software design](software)  
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

![](/docs/images/projects/plotbot/board_top_asm.jpg)

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

![](/docs/images/projects/plotbot/frame_printed.jpg)