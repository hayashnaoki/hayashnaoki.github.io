---
layout: default
---

# PET Filament Maker

2026-ongoing \| DFAB \| Mod

This project is a [Kingroon KP3S](https://kingroon.com/products/official-kingroon-kp3s-3d-printer?srsltid=AfmBOoptXjyvrIYEGUsXfR4ZVJksl2Kdfds86Gv6ok0xnnXQCr3-zhqA)-optimized version of the [Recreator 3D](https://www.printables.com/model/179820-recreator-3d-mk5kit-ender3-pultrusion-unit), a pultrusion-type PET filament maker, designed to maximize the reuse of original parts. It simplifies the build by using a minimalist hardware setup controlled by a basic G-code script that only manages heat and a single puller motor. The goal is to provide an easy-to-build recycling solution that maximizes the utility of existing KP3S components.

### Build steps:
1. Disassembling the Kingroon KP3S
    - Testing the disassembled parts such as the main board, motors, hotend and fans
      ![](/docs/images/projects/pet_filament_maker/disassembled.jpg)
    - Dismantling the hotend: To remove the heatbreak (threaded tube) from the heatsink, I used the double-nut method by tightening two nuts against each other and loosening them together with two wrenches while holding the heatbreak with pliers ([Reference](https://youtu.be/hjzzOs8b7V8?si=cmTR70hekV86XznI)).
      <div class="image-grid">
        <a class="grid-item">
          <div class="image-wrapper">
              <img src="/docs/images/projects/pet_filament_maker/double_nut.jpg" alt="">
          </div>
        </a>

        <a class="grid-item">
          <div class="image-wrapper">
              <img src="/docs/images/projects/pet_filament_maker/heatblock.jpg" alt="">
          </div>
        </a>
      </div>
1. Enlarging the nozzle to a dia. 1.75 mm
    - Using a drilling machine with dia. 1.5 mm drill, the nozzle was enlarged until a 1.75 mm filament ld pass through it
      <div class="image-grid">
        <a class="grid-item">
          <div class="image-wrapper">
              <img src="/docs/images/projects/pet_filament_maker/drilling_machine.jpg" alt="">
          </div>
        </a>

        <a class="grid-item">
          <div class="image-wrapper">
              <img src="/docs/images/projects/pet_filament_maker/nozzle.jpg" alt="">
          </div>
        </a>
      </div>
1. 3D printing and assembling


**Work in progress...**

<!--
<div class="media-wrapper">
    <video src="/docs/images/lab/VIDEO_GOES_HERE"
    autoplay
    muted
    loop
    playsinline></video>
</div>

<iframe 
  src="EMBEDDED_LINK_GOES_HERE" 
  width="100%" 
  height="auto" 
  style="aspect-ratio:16/9;" 
  frameborder="0" 
  allow="autoplay; fullscreen; picture-in-picture; clipboard-write; encrypted-media; web-share" 
  referrerpolicy="strict-origin-when-cross-origin" 
  title="TITLE_GOES_HERE">
</iframe>

<img src="/docs/images/BW_IMAGE_GOES_HERE" class="bw" alt="">

<div class="image-grid">
  <a class="grid-item">
    <div class="image-wrapper">
        <img src="/docs/images/projects/pet_filament_maker/kp3s_1.jpg" alt="">
    </div>
  </a>

  <a class="grid-item">
    <div class="image-wrapper">
        <img src="/docs/images/projects/pet_filament_maker/disassembled.jpg" alt="">
    </div>
  </a>

  <a class="grid-item wide">
    <div class="image-wrapper">
        <img src="/docs/images/projects/pet_filament_maker/double_nut.jpg" alt="">
    </div>
  </a>
</div>
-->