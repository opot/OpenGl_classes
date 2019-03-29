#pragma once

#include <GL/glew.h>

namespace fjfj {

    class Shader {
    public:
        GLuint Program;

        Shader() = default;
        Shader(const GLchar *vertexPath, const GLchar *fragmentPath);
        ~Shader();

        void Use();
    };
}
