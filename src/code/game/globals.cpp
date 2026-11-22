#include "core/globals.hpp"

#include <glm/glm.hpp>

#include "core/color.hpp"

int globals::WINDOW_HEIGHT = 600;
int globals::WINDOW_WIDTH = 800;

glm::vec4 globals::CLEAR_COLOR = color::ToUnitRGBA(glm::vec3(172.0f, 245.0f, 251.0f), color::COLOR_FORMAT::RGB8);

double globals::DELTA_TIME = 0.008;