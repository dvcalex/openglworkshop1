cmake_minimum_required(VERSION 3.15)
project(openglworkshop1 VERSION 1.0.0 LANGUAGES C CXX)

# c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

# GLFW (we don't need docs, tests or examples)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
    GIT_SHALLOW TRUE
)

# GLAD2 OpenGL loader
FetchContent_Declare(glad GIT_REPOSITORY https://github.com/Dav1dde/glad.git GIT_TAG v2.0.8 SOURCE_SUBDIR cmake)

# Automatically detect and use Python from virtual environment if available
if(DEFINED ENV{VIRTUAL_ENV})
    find_program(_venv_python NAMES python3 python PATHS "$ENV{VIRTUAL_ENV}/Scripts" "$ENV{VIRTUAL_ENV}/bin" NO_DEFAULT_PATH)
    set(Python_EXECUTABLE "${_venv_python}" CACHE FILEPATH "Path to Python executable")
    set(Python3_EXECUTABLE "${_venv_python}" CACHE FILEPATH "Path to Python3 executable")
    message(STATUS "Using Python from virtual environment: $ENV{VIRTUAL_ENV}")
endif()

# Find Python (required for glad generator, needs jinja2 package)
find_package(Python3 REQUIRED COMPONENTS Interpreter)
find_package(Python REQUIRED COMPONENTS Interpreter)

FetchContent_MakeAvailable(glfw glad)
glad_add_library(glad_gl_core_41 REPRODUCIBLE STATIC API gl:core=4.1)
find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/shader.cpp
    vendor/stb_image/stb_image.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include SYSTEM PRIVATE vendor)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad_gl_core_41 OpenGL::GL)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
