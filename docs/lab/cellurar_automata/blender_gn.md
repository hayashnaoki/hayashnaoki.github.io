---
layout: default
---

# Blender Geometry Nodes

> Back to [Cellular automata](/docs/lab/cellurar_automata/index)

I finally started learning Blender Geometry Nodes, encouraged by the idea of using LLMs as coach.

### Basics 
- Blender version: [Blender 4.5 LTS](https://www.blender.org/download/lts/4-5/) (the last Intel Mac compatible)

**Basic commands:**
- `G`: Move
- `R`: Rotate
- `S`: Scale
- `G/R/S + x,y,z`: axis-controlled transformations
- `N`: Sidebar for numerical input
- `Shift + D`: Duplicate
- `Tab`: Edit mode
- `Corner drag`: split the viewport panel, position the mouse over the top-right corner of the panel until `+` sign appears
- `Right-click` the boarder between panels: `Join Right/Left`

**Rendering**
- Set a camera
  - Look through the camera: `Numpad 0` or Camera icon at the right
  - `N` to open the side menu panel > `View` tab
  - Check the `Camera to View`
  - Frame the view as standard viewport (camera follows)
  - Uncheck the `Camera to View`
- Adjust camera settings
  - {: .note} Select the camera first
  - Properties tab (at bottom right) > `Data` tab (only appears when a camera selected)
    - Focal length etc.
- Add lights
  - `Shift + A` add area light
  - Move and rotate lights
  - Select the light and go to Properties tab (green light bulb icon)
  - Settings
    - Power, color, size etc.
- Set background
  - Go to World tab (red globe icon)
  - Surface > Background
- Set render settings
  - Go to Output tab (printer icon)
    - Set resolution, frame rate, frame range (Frame start - End)
    - Output > File format > `PNG` sequence or `FFmpeg video` for animation (FFmpeg for short test)
    - {: .note} Encoding > Container: `MPEG-4` (Default: `Matroska`)
  - Go to Scene tab (camera icon)
    - Render engines > Eevee or Cycles
    - {: .note} Render > `Max Samples`, `Time Limit` for setting quality
- Render
  - Go to Render menu at the top (File / Edit / Render ...) > Render Animation

**Geometry nodes:**
- Geometry nodes are "modifier", run on an object
- Go to `Modifier` at the right, `Add Modifier` > `Geometry Nodes`
- Or got to Geometry Nodes panel, click `New` at the top
- Group Input > `Processes` > Group output
- `Shift + A`: Add modifier
- `X`: delete
- To disconnect, grab a connector and release
- Drag a component on a connector to insert it
- `M` on a node: temporarily mute

### Examples
1. 2D grid
  - `Grid`, `Mesh to Points`: generate a plane mesh and convert it into points
1. 3D lattice
  - `Mesh Line`, another `Instance on Points`: multiply the grid a long Z axis > 3D lattice
  - `Instance on Points`: generate instance (lightweight references) on points > 2D grid
  - `Set Material`
    ![](/docs/images/lab/cellular_automata/blender_gn/gn_3D_math.jpg)

1. 3D lattice using mathematical process
  - `Mesh Line`: Generate vertices (count: 1000, offset: 100 mm) > output as a mesh > `Mesh to Points`: convert the mesh into points
  - `Index`: get the index number of <u>the element currently being processed</u> like `i` in `for i in range(N):` (this case, Mesh Line: 0, 1, 2, 3, ... 999)
  ([Document](https://docs.blender.org/manual/en/latest/modeling/geometry_nodes/geometry/read/input_index.html))
  - To create 10 x 10 x 10 lattice points, do some math: 
      ```
      X goes 0–9 repeatedly             : X = i % 10
      Y goes 0–9 per block              : Y = (i / 10) % 10
      after 100 numbers go one layer up : Z = i / 100
      ```
  - `Combine XYZ` > `Set Position`
  - `Instance on Points` to generate cube instances
    ![](/docs/images/lab/cellular_automata/blender_gn/gn_3D_math.jpg

    > Blender’s field system hides the loop and hides the list unlike Python or Grasshopper
    - Unlike Python, it does not perform 3 loops
        ```py
        points = []
        for z in range(10):
            for y in range(10):
                for x in range(10):
                    points.append((x, y, z))
        ```
    - Unlike Grasshopper, there is no data tree, everything is flattened.

1. Perforated ball (based on [Geometry Nodes Ep02 – Working with Geometry](https://entagma.com/courses/geometry-nodes/geometry-nodes-ep02-working-with-geometry/)) 
  - `Ico Sphere` > `Dual Mesh`: create "dual" (turning faces into vertices, vertices into faces) [docs](https://docs.blender.org/manual/en/dev/modeling/geometry_nodes/mesh/operations/dual_mesh.html)
  - `Extrude Mesh` (Offset: 0.0) > `Scale Elements` (Scale: 0.9)
  - `Delete Geometry` (Selection: connect `Top` from `Extrude Mesh`)
  - `Extrude Mesh` + `Flip Faces` > `Join Geometry`: create extruded and closed faces > `Merge by Distance`: merge edges
  - `Subdivide Surface` > `Set Shade Smooth`
    ![](/docs/images/lab/cellular_automata/blender_gn/gn_sphere.jpg)

### 3D cubes

This is a test randomly removing cubes as the initial state of the CA.

![](/docs/images/lab/cellular_automata/blender_gn/gn_cubes.jpg)

<div class="media-wrapper">
    <video src="/docs/images/lab/cellular_automata/blender_gn/cubes.mp4"
    autoplay
    muted
    loop
    playsinline></video>
</div>

Ref: 
- [Blender 5.0 Manual - Geometry Nodes](https://docs.blender.org/manual/en/latest/modeling/geometry_nodes/index.html#)
- [ENTAGMA - Geometry Nodes](https://entagma.com/courses/geometry-nodes/)