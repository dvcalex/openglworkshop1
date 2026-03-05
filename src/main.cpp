#include "cube.hpp"
#include "shader.hpp"
#include "stb_image/stb_image.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

int main()
{
    // ### GLFW Init ###

    if (!glfwInit())
    {
        std::cout << "error with glfwInit()!" << std::endl;
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create a window and its opengl context
    constexpr int Width = 640;
    constexpr int Height = 480;
    GLFWwindow* window = glfwCreateWindow(Width, Height, "openglworkshop1", NULL, NULL);
    if (!window)
    {
        std::cout << "error with glfwCreateWindow()!" << std::endl;
        glfwTerminate();
        return 1;
    }

    // make the window's context current
    glfwMakeContextCurrent(window);

    // not necessary, but caps the framerate to the monitor refresh rate
    glfwSwapInterval(1);

    // ### GLAD Init ###

    // load GL functions once we have a valid context
    if (!gladLoadGL(glfwGetProcAddress))
    {
        std::cout << "error with gladLoadGL()!" << std::endl;
        glfwTerminate();
        return 1;
    }
    std::cout << glGetString(GL_VERSION) << std::endl;

    // ### Enable depth testing ###

    // ### Create VBO (vertex buffer object) ###

    // ### Create VAO (vertex array object) + vertex attributes ###

    // ### Create EBO (element buffer object) ###

    // ### Load and compile shaders ###

    GLuint shaderProgram = shader::createProgram("res/shaders/cube.vert", "res/shaders/cube.frag");

    // ### Load texture ###

    stbi_set_flip_vertically_on_load(1);
    int width, height, bpp;
    unsigned char* tempTexBuf = stbi_load("res/textures/brainrot.png", &width, &height, &bpp, 4);

    // generate and bind texture

    // set texture parameters

    // free cpu-side image buffer
    if (tempTexBuf)
        stbi_image_free(tempTexBuf);

    // ### Render Loop ###

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // ### Bind VAO and shader program ###

        // ### Bind texture to slot 0 ###

        // ### Define MVP matrix and send to shader ###

        // ### Draw ###

        glfwSwapBuffers(window); // swap front and back buffers
        glfwPollEvents();        // poll for and process events
    }

    // ### Cleanup ###
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}
