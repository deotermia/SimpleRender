# SimpleRender

A minimal 3D renderer in C++ using OpenGL, GLFW, and GLAD. Renders a basic triangle as a foundation for graphics application development.

## Requirements

- C++17 compiler
- CMake 3.15+
- OpenGL 3.3+

## Dependencies Installation

### Linux (Ubuntu/Debian)

```bash
sudo apt update
sudo apt install build-essential cmake libglfw3-dev libgl1-mesa-dev libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev
```

## Manual Setup

- Download GLFW from glfw.org
  to `libs/glfw/`.

- Generate GLAD from glad.dav1d.de
  to `libs/glad/`.

- Download GLM from github.com/g-truc/glm
  to `libs/glm/`.

## Build & Run

```bash
mkdir build && cd build
cmake ..
make
./SimpleRender
```

## Project Structure

```bash
SimpleRender/
├── src/
├── libs/
└── resources/
```
