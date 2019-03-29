#pragma once

#include <GL/glew.h>

namespace fjfj {

  class Mesh {

    GLuint VBO, VAO;
    int vert_count;

  public:
    Mesh() = default;
    Mesh(GLfloat vertices[], int vert_count);
    ~Mesh();

    void draw();
    static Mesh* genCube();
  };

}
