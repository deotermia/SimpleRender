\# SimpleRender



A minimalist 3D renderer written in C++ using OpenGL, GLFW, and GLAD. It creates a simple cube as a basis for developing graphics applications and displays camera coordinates and frame rates in the console.



\## Requirements



\- C++17 compiler

\- CMake 3.15+

\- OpenGL 3.3+ capable GPU and drivers



\## Dependencies Installation



\### Linux (UbuntuDebian)



```bash

sudo apt update

sudo apt install build-essential cmake libglfw3-dev libgl1-mesa-dev libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libglm-dev

```

&nbsp;!!! There is no \[GLAD](httpsglad.dav1d.de) package in DebianUbuntu, so be sure to generate it manually.

\### Linux (Arch)



```bash

sudo pacman -Syu

sudo pacman -S base-devel cmake glfw-x11 mesa libx11 libxrandr libxinerama libxcursor libxi glm



yay -S glad

```

&nbsp;Recommendation Generate \[GLAD](httpsglad.dav1d.de) manually

\## Manual Setup



\- Download GLFW from \[Link](httpsglfw.org)

&nbsp; to `libsglfw`.



\- Generate GLAD from \[Link](httpsglad.dav1d.de)

&nbsp; to `libsglad`.



\- Download GLM from \[Link](httpsgithub.comg-trucglm)

&nbsp; to `libsglm`.



\## Build \& Run



```bash

mkdir build \&\& cd build

cmake ..

make

.SimpleRender

```



\## Project Structure



```bash

SimpleRender

├── includecommon

├── resources

│   ├── shaders

│   └── textures

└── src

&nbsp;    ├── core

&nbsp;    ├── rendering

&nbsp;    │    ├── buffers

&nbsp;    │    └── shaders

&nbsp;    ├── scene

&nbsp;    └── utils

```

