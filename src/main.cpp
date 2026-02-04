#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    if (!glfwInit())
    {
        std::cout << "error with glfwInit()!" << std::endl;
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create a window and its opengl context
    GLFWwindow* window = glfwCreateWindow(640, 480, "openglworkshop1", NULL, NULL);
    if (!window)
    {
        std::cout << "error with glfwCreateWindow()!" << std::endl;
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window); // make the window's context current

    glfwSwapInterval(1);

    // can only init glew once we have a valid context
    if (glewInit() != GLEW_OK)
    {
        std::cout << "error with glewInit()!" << std::endl;
        return -1;
    }
    std::cout << glGetString(GL_VERSION) << std::endl;

    // vertex buffer object
    GLuint vbo;
    glGenBuffers(1, &vbo);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT); // clear the screen

        // --- render here ---

        glfwSwapBuffers(window); // swap front and back buffers

        glfwPollEvents(); // poll for and process events
    }

    // cleanup
    glfwTerminate();
    return 0;
}
