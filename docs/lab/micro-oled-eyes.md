---
layout: default
---

# Micro OLED Eyes

2026 \| DFAB \| Cpp

A small hardware exploration using a Seeed Studio XIAO RP2040 and two SH1106 OLED displays to drive synchronized eye-tracking animations.

<div class="media-wrapper">
    <video src="/docs/images/lab/micro-oled-eyes/oled-eye.mp4"
    autoplay
    muted
    loop
    playsinline></video>
</div>

## Animation & Micro-Interactions

- Easing Functions: Applying smooth easing curves to eyelid motion drastically improved the natural cadence of blinks.
- Micro-Saccades & Idle Drift: Adding a gentle, slow vertical drift to the baseline eye positioning avoids a frozen state and gives a subtle sense of breathing.
- Slight Convergence (Cross-Eyed Offset): Angling the focal axes slightly inward creates a realistic depth of field and immediate personality.

## Testing Antigravity IDE & PlatformIO

The primary goal of this project was to test **Antigravity IDE** alongside **PlatformIO** and establish a cleaner Git/GitHub workflow, moving away from the standard Arduino IDE.

- **Hardware:** Seeed Studio XIAO RP2040, 2x SH1106 OLED screens
- **Software:** C++, PlatformIO, Antigravity IDE, GitHub



![](/docs/images/lab/micro-oled-eyes/antigravity.jpg)

**Code & Details:** [GitHub Repository](https://github.com/hayashnaoki/micro-oled-eyes)

[GitHub](https://github.com/hayashnaoki/micro-oled-eyes)
