# SimpleRender



A minimalist 3D renderer written in C++ using OpenGL, GLFW, and GLAD. It creates a simple cube as a basis for developing graphics applications and displays camera coordinates and frame rates in the console.



## Requirements



\- C++17 compiler

\- CMake 3.15+

\- OpenGL 3.3+ capable GPU and drivers



## Dependencies Installation



### Linux (Ubuntu/Debian)



```bash

sudo apt update

sudo apt install build-essential cmake libglfw3-dev libgl1-mesa-dev libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libglm-dev

```

&nbsp;!!! There is no [GLAD](https://glad.dav1d.de) package in Debian/Ubuntu/Arch, so be sure to generate it manually.

### Linux (Arch)



```bash

sudo pacman -Syu

sudo pacman -S base-devel cmake glfw-x11 mesa libx11 libxrandr libxinerama libxcursor libxi glm

```
### AUR install
```bash
yay -S glad

```

&nbsp;Recommendation Generate [GLAD](https://glad.dav1d.de) manually

## Manual Setup



\- Download GLFW from [Link](https://psglfw.org)

&nbsp; to `libs/glfw`.



\- Generate GLAD from [Link](https://glad.dav1d.de)

&nbsp; to `libs/glad/inlude/glad/glad.h`.
&nbsp; to `libs/glad/src/glad.c`.



\- Download GLM from [Link](https://github.comg-trucglm)

&nbsp; to `libs/glm`.



## Build \& Run



```bash

mkdir build \&\& cd build

cmake ..

make

./SimpleRender

```



## Project Structure



```bash

SimpleRender

├── include/common
├── resources
│   ├── shaders
│   └── textures
└── src
    ├── core
    ├── rendering
    │    ├── buffers
    │    └── shaders
    ├── scene
    └── utils

```

