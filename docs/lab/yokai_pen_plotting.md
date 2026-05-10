---
layout: default
---

# Yokai pen plotting

2022 \| Computational design \| Gh/G-code \| w/ Yuki Okuno

An experiment in pen-plotting [Yuki Okuno](https://www.instagram.com/yuki.okuno_design/)’s Karasu Tengu drawing with a 3D printer. A Grasshopper algorithm converts 2D curves into toolpaths and G-code for brush-pen drawing. A slight up-and-down movement was added to replicate the motion of a brush.

### Grasshopper definition for converting curves into G-code

This Grasshopper definition, based on the following webinar,  not only converts curves into G-code, but also visually demonstrates how the process works.

Ref.
- [Book: Advanced 3D printing with Grasshopper](https://www.food4rhino.com/en/resource/advanced-3d-printing-grasshopper-clay-and-fdm)
- [Rhino User Webinar: Advanced 3D printing with Grasshopper](https://youtu.be/OE_daHEf1MM?si=CwHDtrxsyAjLUD3N)

Grasshopper file: [crvToG-code.gh](/docs/files/lab/yokai_pen_plotting/crvToG-code.gh)

![](/docs/images/lab/yokai_pen_plotting/gh.jpg)

<div class="media-wrapper">
    <video src="/docs/images/lab/yokai_pen_plotting/gcode.mp4"
    autoplay
    muted
    loop
    playsinline></video>
</div>

### Demo

<iframe 
    src="https://player.vimeo.com/video/1164292989?badge=0&autopause=0&player_id=0&app_id=58479&controls=0&autoplay=1&muted=1&loop=1" 
    width="100%" 
    height="auto" 
    style="aspect-ratio:1/1;" 
    frameborder="0" 
    allow="autoplay; fullscreen; picture-in-picture; clipboard-write; encrypted-media; web-share" 
    referrerpolicy="strict-origin-when-cross-origin" 
    title="keima_pen_plotting">
</iframe>

[IG post](https://www.instagram.com/p/Cknwis-PDm6/?utm_source=ig_web_copy_link&igsh=MzRlODBiNWFlZA==)
