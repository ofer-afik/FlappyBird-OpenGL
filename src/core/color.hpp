#include <glm/glm.hpp>

#include "core/log.hpp"

namespace color
{
    enum class COLOR_FORMAT {
        // Standard 0 - 255 int, with 3 values
        RGB8,
        // Standard 0 - 255 int, with 4 values
        RGBA8,
        // 1.0f - 0.0f float values, with 3 values
        RGB_U,
        // 1.0f - 0.0f float values, with 4 values
        RGBA_U
    };

    constexpr glm::vec4 ToUnitRGBA(glm::vec4 color, COLOR_FORMAT format)
    {
        switch (format)
        {
            case COLOR_FORMAT::RGBA_U:
                return glm::vec4(color);
            case COLOR_FORMAT::RGBA8:
                return glm::vec4(color / 255.0f);
            case COLOR_FORMAT::RGB8:
                Log("Attempting to convert incompatible color formats, returning 0 vector!", LOG_TYPE::WARNING);
                return glm::vec4(0.0f);
            case COLOR_FORMAT::RGB_U:
                Log("Attempting to convert incompatible color formats, returning 0 vector!", LOG_TYPE::WARNING);
                return glm::vec4(0.0f);
        };
    }

    constexpr glm::vec4 ToUnitRGBA(glm::vec3 color, COLOR_FORMAT format)
    {
        switch (format)
        {
            case COLOR_FORMAT::RGB_U:
                return glm::vec4(color, 1.0f);
            case COLOR_FORMAT::RGB8:
                return glm::vec4(color / 255.0f, 1.0f);
            case COLOR_FORMAT::RGBA8:
                Log("Attempting to convert incompatible color formats, returning 0 vector!", LOG_TYPE::WARNING);
                return glm::vec4(0.0f);
            case COLOR_FORMAT::RGBA_U:
                Log("Attempting to convert incompatible color formats, returning 0 vector!", LOG_TYPE::WARNING);
                return glm::vec4(0.0f);
        }
    }

    constexpr glm::vec3 ToUnitRGB(glm::vec4 color, COLOR_FORMAT format)
    {
        switch (format)
        {
            case COLOR_FORMAT::RGB_U:
                return glm::vec3(color);
            case COLOR_FORMAT::RGB8:
                return glm::vec3(color / 255.0f);
            case COLOR_FORMAT::RGBA8:
                Log("Attempting to convert incompatible color formats, returning 0 vector!", LOG_TYPE::WARNING);
                return glm::vec3(0.0f);
            case COLOR_FORMAT::RGBA_U:
                Log("Attempting to convert incompatible color formats, returning 0 vector!", LOG_TYPE::WARNING);
                return glm::vec3(0.0f);
        }
    }

    constexpr glm::vec3 ToUnitRGB(glm::vec3 color, COLOR_FORMAT format)
    {
        switch (format)
        {
            case COLOR_FORMAT::RGB_U:
                return glm::vec3(color);
            case COLOR_FORMAT::RGB8:
                return glm::vec3(color / 255.0f);
            case COLOR_FORMAT::RGBA8:
                Log("Attempting to convert incompatible color formats, returning 0 vector!", LOG_TYPE::WARNING);
                return glm::vec3(0.0f);
            case COLOR_FORMAT::RGBA_U:
                Log("Attempting to convert incompatible color formats, returning 0 vector!", LOG_TYPE::WARNING);
                return glm::vec3(0.0f);
        }
    }
}