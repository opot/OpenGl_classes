//
// Created by opot on 06.04.17.
//

#ifndef GLUTGL_RENDERABLE_H
#define GLUTGL_RENDERABLE_H

#include <GL/glew.h>

namespace fjfj {

    class Model {

        GLuint VBO, VAO;
        int vert_count;

    public:
        Model(GLfloat vertices[], int vert_count);

        ~Model();

        void draw();
    };

}

#endif //GLUTGL_RENDERABLE_H
