#pragma once

#include <memory>

#include <glm/glm.hpp>

#include "core/state_machine.hpp"

namespace globals
{
    extern int WINDOW_HEIGHT;
    extern int WINDOW_WIDTH;

    inline std::unique_ptr<GameState> CURRENT_STATE;

    extern double DELTA_TIME;
    inline constexpr double MAX_DELTA_TIME = 0.05; 

    extern glm::vec4 CLEAR_COLOR;
}