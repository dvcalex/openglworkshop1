# OpenGL Workshop

This is some code for the Graphics Programming Knights X Knight Hacks OpenGL Workshop. Follow the installation instructions below per operating system.

## Windows

### Option A: Visual Studio

1. Install [Visual Studio](https://visualstudio.microsoft.com/) with the **"Desktop development with C++"** workload (includes MSVC and CMake)
2. Install [Git](https://git-scm.com/download/win)
3. Install [Python 3](https://www.python.org/downloads/). Make sure to check **"Add python.exe to PATH"** during installation
4. Search for **Developer Command Prompt** or **Developer PowerShell** in the Windows Start Menu to run CMake from the command line

OR just install Build Tools from the command line:

```powershell
winget install Microsoft.VisualStudio.2022.BuildTools --override "--add Microsoft.VisualStudio.Workload.VCTools --passive"
winget install Git.Git
winget install Python.Python.3.12
```

Then open **Developer PowerShell for VS** from the Start Menu.

```powershell
# Clone repo
git clone https://github.com/dvcalex/openglworkshop1.git
cd openglworkshop1

# Start virtual environment
python3 -m venv venv
.\venv\Scripts\activate
python -m pip install jinja2

# Build project
cmake -B build
cmake --build build

# Run project
build\bin\Debug\openglworkshop1.exe
```

### Option B: winget + MinGW

```powershell
# Install dependencies
winget install Kitware.CMake
winget install Git.Git
winget install Python.Python.3.12
winget install MSYS2.MSYS2
```

Open **MSYS2 UCRT64** from the Start Menu and install the compiler:

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-make
```

Add `C:\msys64\ucrt64\bin` to your [system PATH](https://www.architectryan.com/2018/03/17/add-to-the-path-on-windows-10/), then restart your terminal.

```powershell
# Clone repo
git clone https://github.com/dvcalex/openglworkshop1.git
cd openglworkshop1

# Start virtual environment
python3 -m venv venv
.\venv\Scripts\activate
python -m pip install jinja2

# Build project
cmake -B build -G "MinGW Makefiles"
cmake --build build

# Run project
build\bin\openglworkshop1.exe
```

## macOS

```bash
# Install dependencies
xcode-select --install
brew install cmake python3

# Clone repo
git clone https://github.com/dvcalex/openglworkshop1.git
cd openglworkshop1

# Start virtual environment
python3 -m venv venv
source venv/bin/activate
python -m pip install jinja2

# Build project
rm -rf build  # If rebuilding
cmake -B build
cmake --build build

# Run project
./build/bin/openglworkshop1
```

Xcode Command Line Tools provides Clang and Git. CMake can also be installed from [cmake.org](https://cmake.org/download/). Python 3 is included with macOS but can be updated via Homebrew.

## Linux

```bash
# Debian install dependencies
sudo apt update
sudo apt install build-essential cmake git python3 python3-venv libgl1-mesa-dev libx11-dev \
    libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libxext-dev \
    libwayland-dev libxkbcommon-dev
# RHEL install dependencies
sudo dnf install -y gcc-c++ cmake git python3 mesa-libGL-devel libX11-devel \
    libXrandr-devel libXinerama-devel libXcursor-devel libXi-devel \
    libXext-devel wayland-devel libxkbcommon-devel
# Arch install dependencies
sudo pacman -S base-devel cmake git python mesa libx11 libxrandr libxinerama \
    libxcursor libxi wayland libxkbcommon

# Clone repo
git clone https://github.com/dvcalex/openglworkshop1.git
cd openglworkshop1

# Start virtual environment
python3 -m venv venv
chmod +x ./venv/bin/activate
source venv/bin/activate
pip3 install jinja2

# Build project
rm -rf build  # If rebuilding
cmake -B build
cmake --build build

# Run project
./build/bin/openglworkshop1
```

## Branches

- [`main`](https://github.com/dvcalex/openglworkshop1/tree/main) - template code with empty stubs to fill in during the workshop (requires Python 3 with `jinja2` for GLAD2 generation)
- [`pregenglad2`](https://github.com/dvcalex/openglworkshop1/tree/pregenglad2) - same as `main` but with pre-generated GLAD2 files (no Python or `jinja2` needed)
- [`completed`](https://github.com/dvcalex/openglworkshop1/tree/completed) - the finished project with all steps implemented

To view the completed code: `git switch completed`

## Dependencies

Don't worry about these unless it looks like something specific is failing.

- CMake 3.15 or higher
- C++17 compatible compiler
- Python 3 with `jinja2`
- Git
- Internet connection to fetch dependencies
- GLFW 3.4
- GLAD 2.0.8 (OpenGL 4.1 Core)
- GLM (header-only, included in `vendor` directory)
- stb_image (header-only, included in `vendor` directory)
