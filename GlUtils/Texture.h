//
// Created by opot on 10.04.17.
//

#ifndef GLUTGL_TEXTURE_H
#define GLUTGL_TEXTURE_H

#include <GL/glew.h>
#include <string>

namespace fjfj {

    class Texture {

    private:
        int width, height;

    public:
        GLuint texture;

        Texture(std::string path);

        Texture() {};

    };

}

#endif //GLUTGL_TEXTURE_H
