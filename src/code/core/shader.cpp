#include "shader.hpp"

#include <string>

#include <glad/glad.h>

// Constructor + Deconstructor

Shader::Shader()
{

}

// All the many uniform set overloads...

void Shader::Set(const std::string &name, int value)
{
    glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::Set(const std::string &name, bool value)
{
    glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}