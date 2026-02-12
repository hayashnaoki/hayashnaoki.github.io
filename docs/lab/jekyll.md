---
layout: default
title: Jekyll
---

# Jekyll

2026, Web development

Jekyll is a static site generator used by GitHub Pages that converts Markdown files into static HTML and CSS at build time. It requires no server or database, produces fully static output, and operates entirely at build time without any runtime processing.

### Configurations

1. Theme
    - Provides layouts and default CSS
    - This site uses the `minima` theme 
    - Some parts are customized using `custom.scss`
    - Files in the repository override theme files
1. CSS / SCSS
    - `assets/main.scss` is the entry point
    - Compiled into `assets/main.css`
    - Build fails if SCSS contains errors
1. Minimal structure

    ```
    .
    |-- _config.yml
    |-- Gemfile
    |-- assets/
    |   |-- main.scss
    |-- index.md
    |-- docs/
        |-- projects/
        |   |-- prj_A.md
        |   |-- prj_B.md...
        |-- labs/
        |   |-- lab_A.md...
        |-- images/
        |   |-- prj_A/...
        |-- projects.md
        |-- lab.md
        |-- about.md
    ```

1. Recommended content organization

    ```
    _projects/
    project-a.md

    _lab/
    experiment-01.md

    assets/
    projects/project-a/
    lab/experiment-01/
    ```

    - Keep Markdown and images separate
    - Create one folder per project or lab
    - Match the slug (file name) with the asset folder name

    Example: `assets/projects/project-a/cover.jpg`

### Workflow and rules

1. Editing workflow
    - Create a new `.md` file in `_projects/` or `_lab/`
    - Create a matching folder in `images/projects/` or `images/lab/`
    - Add images to that folder
    - Use absolute paths in Markdown: `![cover](/images/projects/project-a/cover.jpg)`
1. Local preview: `jekyll serve`
    - Open [http://localhost:4000](http://localhost:4000/)
    - Changes reload automatically
1. Link rules (important)
    Recommended: `[Project](/projects/project-a)`
    - Use absolute paths
    - Do not include `.md`
1. Common issues
    - CSS not applied → theme overrides your styles
    - Build fails → SCSS error
    - Broken links → relative paths used
    - Push rejected → Git history rewritten

---
### Example: 

# This is an H1 and appears very large. Maybe too large.

## This is an H2. Sushi can be understood as a system defined by clear parameters—portion, proportion, sequence, and repetition. 

### This is an H3. The same rules that define a single piece of sushi can be applied repeatedly without changing their logic. Scale changes the quantity, not the structure.

This is an body. This site is open to the public as a repository for scalable, sushi-generating Grasshopper definitions. The recipes and definitions are open and reproducible. Raw materials are not included; users are responsible for sourcing their own tuna.

# これは日本語です。

## 意図しない改行を防ぐため、長い英単語は避けてください。

このサイトは、スケーラブルな寿司生成のための Grasshopper 定義を共有する公開リポジトリです。レシピや定義は公開されていますが、原材料については各自でご用意ください。マグロは含まれていません。

# 这是中文。

##  Noto Sans JP 对中国的支持尚不完善。

寿司看似简单，但由比例、顺序和重复构成。正因为这些清晰的规则，寿司可以在保持结构不变的情况下不断扩展和复制。

[https://hayashnaoki.github.io/](https://hayashnaoki.github.io/)

![](./docs/images/rhgh.jpg)

<iframe 
  src="https://player.vimeo.com/video/904894755?badge=0&autopause=0&player_id=0&app_id=58479&controls=0&autoplay=1&muted=1&loop=1" 
  width="100%" 
  height="auto" 
  style="aspect-ratio:1/1;" 
  frameborder="0" 
  allow="autoplay; fullscreen; picture-in-picture; clipboard-write; encrypted-media; web-share" 
  referrerpolicy="strict-origin-when-cross-origin" 
  title="GH Lab | 2022_2023">
</iframe>

Embedded video without control

```html
<iframe 
  src="https://player.vimeo.com/video/904894755?badge=0&autopause=0&player_id=0&app_id=58479&controls=0&autoplay=1&muted=1&loop=1" 
  width="100%" 
  height="auto" 
  style="aspect-ratio:1/1;" 
  frameborder="0" 
  allow="autoplay; fullscreen; picture-in-picture; clipboard-write; encrypted-media; web-share" 
  referrerpolicy="strict-origin-when-cross-origin" 
  title="GH Lab | 2022_2023">
</iframe>
```

| Name | Descriptions | Quantity |
| --- | --- | --- |
| Rhino | Sushi modeling software | 1 |
| Grasshopper | Scalable sushi delivery solution | 46 |

Inline code: `code goes here`  
インラインコード: `コードが通ります`

```py
def prepare_rice(rice_type="short_grain"):
    print(f"Washing and cooking {rice_type} rice...")
    return "fluffy_sushi_rice"

def slice_fish(fish="salmon", thickness="thin"):
    print(f"Slicing {fish} into {thickness} pieces.")
    return f"{fish}_slices"

def roll_maki(rice, fish, extras=None):
    extras = extras or ["nori"]
    print(f"Rolling maki with {rice}, {fish}, and {', '.join(extras)}.")
    return "maki_roll"

def add_wasabi(level="small"):
    print(f"Adding a {level} amount of wasabi.")
    return "wasabi_dab"

def plate_sushi(roll, garnish="pickled_ginger"):
    print(f"Plating {roll} with {garnish}.")
    return "finished_sushi_plate"

# Example flow (not real execution logic)
# これは日本語のコメントです
rice = prepare_rice()
fish = slice_fish("tuna")
roll = roll_maki(rice, fish, extras=["cucumber", "nori"])
wasabi = add_wasabi("medium")
plate = plate_sushi(roll)

print("Sushi ready to serve.")
```

> Quotes:
>
- Keep calm and eat sushi.  
- You had me at sushi.  
- Sushi makes miso happy.  
- Life is better with a sushi roll in hand.  
- Just roll with it.  
- Whatever the question, the answer is sushi.

Menu

1. Rhino sushi
1. Grasshopper sushi
    1. Kangaroo sushi
    1. Galapagos sushi
    1. Firefly sushi
    1. GhPython sushi

{: .note}
This is a **note** (`{: .note}`). Sushi is fundamentally scalable.

{: .warning}
This is a **warning** (`{: .warning}`). Sushi is exponentially scalable.
