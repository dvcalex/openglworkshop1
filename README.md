# OpenGL Workshop

This is some code for the Graphics Programming Knights X Knight Hacks OpenGL Workshop. Follow the installation instructions below per operating system.

The completed workshop code is available in `src/completed.cpp` for reference.

## Windows

> **Pick ONE of the options below. Most people should use Visual Studio Build Tools.**

### Visual Studio Build Tools (Recommended)

```powershell
# Install dependencies
winget install Microsoft.VisualStudio.2022.BuildTools --override "--add Microsoft.VisualStudio.Workload.VCTools --passive"
winget install Git.Git
```

Open **Developer PowerShell for VS** from the Windows Start Menu and run the below commands:

```powershell
# Clone repo
git clone https://github.com/dvcalex/openglworkshop1.git
cd openglworkshop1

# Build project
cmake -B build
cmake --build build

# Run project
build\bin\Debug\openglworkshop1.exe
```

<details>
<summary><h3>winget + MinGW (Alternative — only if you can't use Visual Studio)</h3></summary>

```powershell
# Install dependencies
winget install Kitware.CMake
winget install Git.Git
winget install MSYS2.MSYS2
```

Open **MSYS2 UCRT64** from the Windows Start Menu and run the below commands:

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-make
```

Add `C:\msys64\ucrt64\bin` to your [system PATH](https://www.architectryan.com/2018/03/17/add-to-the-path-on-windows-10/), then restart your terminal.

```powershell
# Clone repo
git clone https://github.com/dvcalex/openglworkshop1.git
cd openglworkshop1

# Build project
cmake -B build -G "MinGW Makefiles"
cmake --build build

# Run project
build\bin\openglworkshop1.exe
```

</details>

## macOS

```bash
# Install dependencies
xcode-select --install
brew install cmake

# Clone repo
git clone https://github.com/dvcalex/openglworkshop1.git
cd openglworkshop1

# Build project
rm -rf build  # If rebuilding
cmake -B build
cmake --build build

# Run project
./build/bin/openglworkshop1
```

Xcode Command Line Tools provides Clang and Git. CMake can also be installed from [cmake.org](https://cmake.org/download/).

## Linux

```bash
# Debian install dependencies
sudo apt update
sudo apt install build-essential cmake git libgl1-mesa-dev libx11-dev \
    libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libxext-dev \
    libwayland-dev libxkbcommon-dev
# RHEL install dependencies
sudo dnf install -y gcc-c++ cmake git mesa-libGL-devel libX11-devel \
    libXrandr-devel libXinerama-devel libXcursor-devel libXi-devel \
    libXext-devel wayland-devel libxkbcommon-devel
# Arch install dependencies
sudo pacman -S base-devel cmake git mesa libx11 libxrandr libxinerama \
    libxcursor libxi wayland libxkbcommon

# Clone repo
git clone https://github.com/dvcalex/openglworkshop1.git
cd openglworkshop1

# Build project
rm -rf build  # If rebuilding
cmake -B build
cmake --build build

# Run project
./build/bin/openglworkshop1
```

## Dependencies

Don't worry about these unless it looks like something specific is failing.

- CMake 3.15 or higher
- C++17 compatible compiler
- Git
- GLFW 3.4
- GLAD 2.0.8 (OpenGL 4.1 Core, pre-generated in `vendor/glad/`)
- GLM (header-only, included in `vendor` directory)
- stb_image (header-only, included in `vendor` directory)
- Internet connection to fetch some dependencies
