---
layout: default
---

# Blender Geometry Nodes

2026-ongoing \| Computational design \| Blender

I finally started learning Blender Geometry Nodes, encouraged by the idea of using LLMs as a coach.

### Basics 
- Blender version: [Blender 4.5 LTS](https://www.blender.org/download/lts/4-5/) (the last Intel Mac compatible)
- Geometry nodes are "modifier", run on an object
- Go to `Modifier` at the right, `Add Modifier` > `Geometry Nodes`
- Group Input > `Processes` > Group output
- `Shift + A`: Add modifier
- `X`: delete
- To disconnect, grab a connector and release

1. 2D grid
  - `Grid`, `Mesh to Points`: generate a plane mesh and turn it into points
1. 3D lattice
  - `Mesh Line`, another `Instance on Points`: to copy Z axis > 3D lattice
  - `Instance on Points`: generate instance (lightweight references) on points > 2D grid
  - `Set Material`
    ![](/docs/images/lab/blender_gn/gn_lattice.jpg)


### Ref.

- [Blender 5.0 Manual \| Geometry Nodes](https://docs.blender.org/manual/en/latest/modeling/geometry_nodes/index.html#)
- [Blender Tutorial: Geometry Nodes for Beginners - Part 1](https://youtu.be/aO0eUnu0hO0?si=01_L2nU1kbolwsOf)
