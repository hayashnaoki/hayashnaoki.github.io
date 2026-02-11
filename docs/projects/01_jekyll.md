---
layout: default
title: Jekyll
---

# Jekyll

## Jekyll Overview

**Jekyll** is a static site generator used by GitHub Pages.

Markdown is converted into static HTML/CSS at build time.

---

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

---

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

---

## Essential Steps

1. Create repo
2. Set theme
3. Write Markdown
4. Customize CSS
5. Preview locally
6. Push to GitHub

---

## Things to Watch Out For

- Local vs GitHub Pages build differences
- Theme CSS overriding custom styles
- SCSS compile errors
- Git history rewrites breaking push

[Home](/test/docs/projects)