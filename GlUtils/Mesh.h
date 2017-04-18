//
// Created by opot on 06.04.17.
//

#ifndef GLUTGL_RENDERABLE_H
#define GLUTGL_RENDERABLE_H

#include <GL/glew.h>

namespace fjfj {

    class Mesh {

        GLuint VBO, VAO;
        int vert_count;

    public:
        Mesh(GLfloat vertices[], int vert_count);

        ~Mesh();

        void draw();

        static Mesh* genCube();
    };

}

#endif //GLUTGL_RENDERABLE_H
