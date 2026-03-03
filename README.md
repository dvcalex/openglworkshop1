## Prerequisites

- CMake 3.15 or higher
- C++17 compatible compiler
- Python 3 with `jinja2`
- Git
- Internet connection to fetch dependencies

After installing Python, install the required package:

```bash
pip install jinja2
```

> [!NOTE]
> If `pip` doesn't work, try `pip3 install jinja2` instead.

### Windows

1. Install [Visual Studio](https://visualstudio.microsoft.com/) with the **"Desktop development with C++"** workload (includes MSVC and CMake), or install CMake and a C++17 compiler separately
2. Install [Git](https://git-scm.com/download/win)
3. Install [Python 3](https://www.python.org/downloads/). Make sure to check **"Add python.exe to PATH"** during installation
4. Search for **Developer Command Prompt** or **Developer PowerShell** in the Windows Start Menu to run CMake from the command line

### macOS

```bash
xcode-select --install
brew install cmake python3
```

Xcode Command Line Tools provides Clang and Git. CMake can also be installed from [cmake.org](https://cmake.org/download/). Python 3 is included with macOS but can be updated via Homebrew.

### Linux (Ubuntu/Debian)

```bash
sudo apt update
sudo apt install build-essential cmake git python3 python3-pip libgl1-mesa-dev libx11-dev \
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

## Branches

- [`main`](https://github.com/dvcalex/openglworkshop1/tree/main) - template code with empty stubs to fill in during the workshop (requires Python 3 with `jinja2` for GLAD2 generation)
- [`pregenglad2`](https://github.com/dvcalex/openglworkshop1/tree/pregenglad2) - same as `main` but with pre-generated GLAD2 files (no Python or `jinja2` needed)
- [`completed`](https://github.com/dvcalex/openglworkshop1/tree/completed) - the finished project with all steps implemented

To view the completed code: `git switch completed`

## Building

Clone the repo

```bash
git clone https://github.com/dvcalex/openglworkshop1.git
cd openglworkshop1
```

### Command Line

Build the project

```bash
cmake -B build
cmake --build build
```

Run the executable from the **project root** (shaders and textures are loaded with relative paths):

```bash
# Windows
build\bin\Debug\openglworkshop1.exe

# Linux/macOS
./build/bin/openglworkshop1
```

## Dependencies

- GLFW 3.4
- GLAD 2.0.8 (OpenGL 4.1 Core)
- GLM (header-only, included in `vendor` directory)
- stb_image (header-only, included in `vendor` directory)

GLFW and GLAD are fetched from the internet via CMake FetchContent.
