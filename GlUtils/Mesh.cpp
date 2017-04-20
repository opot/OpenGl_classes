//
// Created by opot on 06.04.17.
//

#include <iostream>
#include "Mesh.h"

namespace fjfj {

    Mesh::Mesh(GLfloat vertices[], int vert_count) {
        this->vert_count = vert_count;

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr) (sizeof(GLfloat) * 8 * vert_count), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *) 0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *) (3 * sizeof(GL_FLOAT)));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *) (6 * sizeof(GL_FLOAT)));
        glEnableVertexAttribArray(2);

        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindVertexArray(0);
    }

    Mesh::~Mesh() {
        //glDeleteBuffers(1, &VBO);
        //glDeleteVertexArrays(1, &VAO);
    }

    void Mesh::draw() {
        glBindVertexArray(this->VAO);
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawArrays(GL_TRIANGLES, 0, this->vert_count);
        glBindVertexArray(0);
    }

    Mesh* Mesh::genCube() {
        GLfloat cube_vert[] = {
                -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.33f, 0.5f,//FRONT
                0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.66f, 0.5f,
                0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.66f, 0.0f,

                -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.33f, 0.5f,
                -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.33f, 0.0f,
                0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.66f, 0.0f,

                -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.5f,//BACK
                0.5f, -0.5f, 0.5f, 0.0f, 0.0f, -1.0f, 0.33f, 0.5f,
                0.5f, 0.5f, 0.5f, 0.0f, 0.0f, -1.0f, 0.33f, 0.0f,

                -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.5f,
                -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
                0.5f, 0.5f, 0.5f, 0.0f, 0.0f, -1.0f, 0.33f, 0.0f,

                -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.66f, 0.5f,//TOP
                0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.5f,
                0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,

                -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.66f, 0.5f,
                -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.66f, 0.0f,
                0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,

                -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,//BOTTOM
                0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.33f, 1.0f,
                0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.33f, 0.5f,

                -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
                -0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.5f,
                0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.33f, 0.5f,

                -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.33f, 1.0f,//LEFT
                -0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.66f, 1.0f,
                -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.66f, 0.5f,

                -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.33f, 1.0f,
                -0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.33f, 0.5f,
                -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.66f, 0.5f,

                0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.66f, 1.0f,//RIGHT
                0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
                0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.5f,

                0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.66f, 1.0f,
                0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.66f, 0.5f,
                0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.5f
        };

        return new Mesh(cube_vert, 36);

    }

}