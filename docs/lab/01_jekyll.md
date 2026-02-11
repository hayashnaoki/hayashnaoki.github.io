---
layout: default
title: Jekyll
---

# Jekyll

## Overview

**Jekyll** is a static site generator used by GitHub Pages.

Markdown is converted into static HTML/CSS at build time.

## Core Concepts

### Jekyll

- Build-time only
- Fixed structure
- No server or backend

### Theme

- Provides layouts + default CSS
- Repo files override theme files
- GitHub Pages supports limited themes/versions

### CSS / SCSS

- `assets/main.scss` is the entry point
- Compiled to `assets/main.css`
- Build fails if SCSS has errors

## Minimal Structure

```
.
├── _config.yml
├── Gemfile
├── index.md
├── docs/
├── assets/
│   └── main.scss

```

## Essential Steps

1. Create repo
2. Set theme
3. Write Markdown
4. Customize CSS
5. Preview locally
6. Push to GitHub

## Things to Watch Out For

- Local vs GitHub Pages build differences
- Theme CSS overriding custom styles
- SCSS compile errors
- Git history rewrites breaking push

---
Notes: 

## [This link to the Jekyll project](/docs/projects/01_jekyll) will work.

Description goes here. Of course sushi is still scalable.

[![](/docs/images/404.jpg)](/docs/projects/01_jekyll)

## [<u>This text is underlined</u> and works as a link to the Sushi Rolls project.](/docs/projects/01_jekyll)

{: .note}
Note: Sometimes css changes take time. Be patient...  
Links like `[name](projects/page.md)` work after pushing, but <u>won't work during local preview.</u>

{: .warning}
Links like `[name](/test/docs/projects/page)` work.  
Always write **<u>absolute link</u>** and **<u>avoid suffix</u>** like `.md`.

---
Example: 

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
