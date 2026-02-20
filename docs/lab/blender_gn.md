---
layout: default
---

# Blender Geometry Nodes

2026 \| Computational design \| Blender

I have been interested in Blender Geometry Nodes, especially because of its strong rendering capabilities, but its steep learning curve has discouraged me from learning. However, I heard that LLMs like Gemini can become a good coach, that finally encouraged me to learn...

### Basics 
- Blender version: [Blender 4.5 LTS](https://www.blender.org/download/lts/4-5/) (the last Intel Mac compatible)
- Geometry nodes are "modifier", run on an object.
- `Shift + A`: Add modifier
- `X`: delete
- Group Input > `Processes` > Group output


1. 2D grid
  - `Grid`, `Mesh to Points`: generate a plane mesh and turn it into points
  - `Instance on Points`: generate instance (lightweight references) on points > 2D grid
    ![](/docs/images/lab/blender_gn/gn_lattice.jpg)
1. 3D lattice
  - `Mesh Line`, another `Instance on Points`: to copy Z axis > 3D lattice
  - `Set Material`

### Ref.

- [Blender 5.0 Manual \| Geometry Nodes](https://docs.blender.org/manual/en/latest/modeling/geometry_nodes/index.html#)
- [Blender Tutorial: Geometry Nodes for Beginners - Part 1](https://youtu.be/aO0eUnu0hO0?si=01_L2nU1kbolwsOf)
