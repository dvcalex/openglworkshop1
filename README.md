## Prerequisites

- CMake 3.15 or higher
- C++17 compatible compiler
- Python 3 with `jinja2` (required by GLAD2 to generate the OpenGL loader)
- Git

After installing Python, install the required package:
```bash
pip install jinja2
```

### Windows

Install [Visual Studio](https://visualstudio.microsoft.com/) with the "Desktop development with C++" workload (includes MSVC and CMake), or install CMake and a C++17 compiler separately. Use the **Developer Command Prompt** or **Developer PowerShell** (search for it in the Start menu) to run CMake from the command line. Git can be installed from [git-scm.com](https://git-scm.com/download/win). Install [Python 3](https://www.python.org/downloads/) and make sure to check **"Add python.exe to PATH"** during installation.

### macOS

```bash
xcode-select --install
brew install cmake python3
```

Xcode Command Line Tools provides Clang and Git. CMake can also be installed from [cmake.org](https://cmake.org/download/). Python 3 is included with macOS but can be updated via Homebrew.

### Linux (Ubuntu/Debian)

```bash
sudo apt update
sudo apt install build-essential cmake git python3 libgl1-mesa-dev libx11-dev \
    libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libxext-dev \
    libwayland-dev libxkbcommon-dev
```

### Linux (Fedora)

```bash
sudo dnf install gcc-c++ cmake git python3 mesa-libGL-devel libX11-devel \
    libXrandr-devel libXinerama-devel libXcursor-devel libXi-devel \
    libXext-devel wayland-devel libxkbcommon-devel
```

### Linux (Arch)

```bash
sudo pacman -S base-devel cmake git python mesa libx11 libxrandr libxinerama \
    libxcursor libxi wayland libxkbcommon
```

## Building

Clone the repo
```bash
git clone https://github.com/dvcalex/openglworkshop1.git
cd openglworkshop1
```

Build the project
```bash
cmake -B build
cmake --build build
```

Run the executable
```bash
# Windows
build\bin\Debug\openglworkshop1.exe

# Linux/macOS
./build/bin/openglworkshop1
```

## Dependencies

All dependencies are automatically fetched with CMake FetchContent
- GLFW 3.4
- GLAD 2.0.8 (OpenGL 4.1 Core)
- GLM (header-only, included in `vendor` directory)
- stb_image (header-only, included in `vendor` directory)
