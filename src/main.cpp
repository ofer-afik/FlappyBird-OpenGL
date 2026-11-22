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
#include <memory>
#include <algorithm>

// Library Includes
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Local Includes
#include "core/log.hpp"
#include "core/state_machine.hpp"
#include "core/color.hpp"
#include "core/globals.hpp"
#include "core/game_setup.hpp"
#include "assets/quad_vertices.hpp"

int main()
{
    Log("Program started!", LOG_TYPE::INFO);

    GLFWwindow *window = setupGame();

    globals::CURRENT_STATE = std::make_unique<Playing>();

    Log("Render loop beginning...", LOG_TYPE::INFO);

    while (!glfwWindowShouldClose(window))
    {
        double currentTime = glfwGetTime();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        globals::CURRENT_STATE->Update(globals::DELTA_TIME);
        globals::CURRENT_STATE->Draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
        double dt = glfwGetTime() - currentTime;
        globals::DELTA_TIME = dt;
    }
    
    Log("Rendering loop ended! De-initializing game...", LOG_TYPE::INFO);

    // De-initialization
    glfwTerminate();
    return 0;
}