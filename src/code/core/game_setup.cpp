#include "game_setup.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "globals.hpp"
#include "log.hpp"

GLFWwindow* setupGLFW()
{
    // Window set up
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Required for macos
    #endif
    
    GLFWwindow *window = glfwCreateWindow(globals::WINDOW_WIDTH, globals::WINDOW_HEIGHT, "Flappy Bird", NULL, NULL);
    if (window == NULL)
    {
        Log("Failed to create window", LOG_TYPE::ERROR);
        return nullptr;
    }
    
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    
    Log("GLFW window created!", LOG_TYPE::INFO);
    return window;
}


bool setupGL()
{
    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Log("Failed to load GL function pointers!", LOG_TYPE::ERROR);
        return false;
    }

    Log("GLAD OpenGL function pointers loaded!", LOG_TYPE::INFO);
    return true;
}

GLFWwindow* setupGame()
{
    GLFWwindow *window = setupGLFW();
    if (!setupGL() || !window)
    {
        Log("Failed to set up game!", LOG_TYPE::ERROR);
        return nullptr;
    }

    glClearColor(globals::CLEAR_COLOR.r,
                 globals::CLEAR_COLOR.g,
                 globals::CLEAR_COLOR.b,
                 1.0f);

    Log("Game set up complete!", LOG_TYPE::INFO);
    
    return window;
}