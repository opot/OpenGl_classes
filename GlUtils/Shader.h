//
// Created by opot on 06.04.17.
//

#ifndef GLUTGL_SHADER_H
#define GLUTGL_SHADER_H

#include <GL/glew.h>

namespace fjfj {

    class Shader {
    public:
        GLuint Program;

        // Constructor generates the shader on the fly
        Shader(const GLchar *vertexPath, const GLchar *fragmentPath);

        ~Shader();

        // Uses the current shader
        void Use();
    };
}

#endif //GLUTGL_SHADER_H
