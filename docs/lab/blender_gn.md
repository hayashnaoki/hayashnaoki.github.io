---
layout: default
---

# Blender Geometry Nodes

2026-ongoing \| Computational design \| Blender

I finally started learning Blender Geometry Nodes, encouraged by the idea of using LLMs as coach.

### Basics 
- Blender version: [Blender 4.5 LTS](https://www.blender.org/download/lts/4-5/) (the last Intel Mac compatible)
- Geometry nodes are "modifier", run on an object
- Go to `Modifier` at the right, `Add Modifier` > `Geometry Nodes`
- Group Input > `Processes` > Group output
- `Shift + A`: Add modifier
- `X`: delete
- To disconnect, grab a connector and release
- Drag a component on a connector to insert it

### Examples
1. 2D grid
  - `Grid`, `Mesh to Points`: generate a plane mesh and convert it into points
1. 3D lattice
  - `Mesh Line`, another `Instance on Points`: multiply the grid a long Z axis > 3D lattice
  - `Instance on Points`: generate instance (lightweight references) on points > 2D grid
  - `Set Material`
    ![](/docs/images/lab/blender_gn/gn_lattice.jpg)

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
    ![](/docs/images/lab/blender_gn/gn_3D_math.jpg)

    > Blender’s field system hides the loop and hides the list unlike Python or Grasshopper
    - It doesn't run 3 loops unlike Python
        ```py
        points = []
        for z in range(10):
            for y in range(10):
                for x in range(10):
                    points.append((x, y, z))
        ```
    - It doesn't have data tree, everything is flatten, unlike Grasshopper

### Ref.

- [Blender 5.0 Manual \| Geometry Nodes](https://docs.blender.org/manual/en/latest/modeling/geometry_nodes/index.html#)
- [Blender Tutorial: Geometry Nodes for Beginners - Part 1](https://youtu.be/aO0eUnu0hO0?si=01_L2nU1kbolwsOf)
