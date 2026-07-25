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

### Animation & Micro-Interactions

- Easing Functions: Applying smooth easing curves to eyelid motion drastically improved the natural cadence of blinks.
- Micro-Saccades & Idle Drift: Adding a gentle, slow vertical drift to the baseline eye positioning avoids a frozen state and gives a subtle sense of breathing.
- Slight Convergence (Cross-Eyed Offset): Angling the focal axes slightly inward creates a realistic depth of field and immediate personality.

**Code:** [GitHub Repository](https://github.com/hayashnaoki/micro-oled-eyes)

---

### Testing Antigravity IDE & PlatformIO

The primary goal of this project was to test **[Antigravity IDE](https://antigravity.google/product/antigravity-ide)** alongside **[PlatformIO](https://platformio.org/)** and establish a cleaner Git/GitHub workflow, shifting from the standard Arduino IDE.

1. **Key Concept Differences**  
    Unlike the Arduino IDE, which manages libraries and boards globally, PlatformIO handles them on a per-project basis.
    - No Global Libraries: Boards, core frameworks, and libraries are declared inside each project. Multiple projects can use different versions of the same library without conflict.
    - Strict C++: Arduino `.ino` files are pre-processed automatically. PlatformIO uses standard `.cpp` files, requiring explicit header inclusion and standard C++ structure.

2. **Environment & Extension Setup**  
    Antigravity IDE utilizes the open-source Open VSX marketplace. Install the following two extensions:
    - `PlatformIO IDE`: Handles toolchains, core frameworks, and libraries automatically.
    - `clangd`: Provides high-performance C/C++ code completion and error linting.

3. **Project Configuration (`platformio.ini`)**  
    Every project requires a `platformio.ini` file at its root. This file explicitly declares the target hardware and dependencies.

    Example:
    ```cpp
    [env:seeed_xiao_rp2040]
    platform = raspberrypi
    board = seeed_xiao_rp2040
    framework = arduino
    lib_deps =
        olikraus/U8g2 @ ^2.35.30
    ```

4. **C++ Code Structure (`src/main.cpp`)**  
    When migrating code from Arduino IDE, your main file must conform to standard C++ rules:
    1. Explicit Headers: You must explicitly include `#include <Arduino.h>` and any required library headers at the top of the file.
    2. Forward Declarations: Functions must be declared before they are called.
    3. Entry Point: An explicit `int main()` block must handle the hardware initialization loop.

    ```cpp
    #include <Arduino.h>

    // Forward declarations
    void setup();
    void loop();

    int main() {
        init(); // Initializes hardware clocks and timers
        setup();
        while (1) {
            loop();
        }
        return 0;
    }
    ```

5. **Toolbar and Terminal Panel**  
    1. Core Toolbar Operations (PlatformIO shortcuts located in the bottom status bar of the IDE):
        - Build (`✔︎`): Compiles the source code. On the first run, PlatformIO automatically downloads the specified boards, core frameworks, and dependencies into a local hidden directory.
        - Upload (`→`): Compiles and flashes the binary image directly onto the connected microcontroller over USB.
    1. Terminal Panel Contexts (The bottom panel houses distinct terminal tabs. Understanding their context prevents workflow confusion):

        | Terminal Context | Typical Names | Purpose & Usage |
        | --- | --- | --- |
        | Auto-Pilot (Task) | `Upload...`, `Build...` | Read-only logs. Spawns automatically when clicking `✔︎` or `→`. Do not type here. Safe to close after seeing `[SUCCESS]`. |
        | Cloud & Blueprint (System) | `bash`, `zsh` | Version control and OS tasks. Use this exclusively for running `git` commands (`git add`, `git commit`) to manage repository history. |
        | Hardware Interactive| `PlatformIO CLI`, `Device Monitor` | Microcontroller interaction. Wired directly to your physical desk setup. Use this tab for serial debugging outputs (`Serial.print`) or running explicit PIO commands. |


![](/docs/images/lab/micro-oled-eyes/antigravity.jpg)
