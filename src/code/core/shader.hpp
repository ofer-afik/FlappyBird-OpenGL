#pragma once

#include <string>

class Shader
{
public:
    Shader();

    unsigned int id;

    void Use();

    void Set(const std::string &name, int value);
    void Set(const std::string &name, bool value);
};