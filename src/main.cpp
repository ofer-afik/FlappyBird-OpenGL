/*
### For Debug
A single macro, defined in the opening of `main.cpp` that
determines whether to enable debug features or not.

#### Dependent functions/features:
- `Log()` macro - defined in `log.hpp`. Allows logging of info,
errors, and warnings to console
*/
#define LOG true

// C++ Includes
#include <iostream>

// Library Includes
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Local Includes
#include "core/renderer.hpp"
#include "core/log.hpp"
#include "core/color.hpp"

// Global variables
int WINDOW_WIDTH  = 600;
int WINDOW_HEIGHT = 800;

glm::vec4 CLEAR_COLOR = color::ToUnitRGBA(glm::vec3(172, 245, 251), color::COLOR_FORMAT::RGB8);

int main()
{
    Log("Program started!", LOG_TYPE::INFO);

    // Window set up
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Required for macos
    #endif
    glfwSwapInterval(1);

    GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Flappy Bird", NULL, NULL);
    if (window == NULL)
    {
        Log("Failed to create window", LOG_TYPE::ERROR);
        glfwTerminate();
        return -1;    
    }
    glfwMakeContextCurrent(window);
    
    Log("GLFW window created!", LOG_TYPE::INFO);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Log("Failed to load GL function pointers!", LOG_TYPE::ERROR);
        return -1;
    }

    Log("GLAD GL function pointers loaded!", LOG_TYPE::INFO);

    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
    }
    
    // De-initialization
    glfwTerminate();
    return 0;
}