//
// Created by opot on 06.04.17.
//

#include <iostream>
#include "Model.h"

namespace fjfj {

    Model::Model(GLfloat vertices[], int vert_count) {
        this->vert_count = vert_count;

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr) (sizeof(GLfloat) * 3 * vert_count), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *) 0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindVertexArray(0);
    }

    Model::~Model() {
        glDeleteBuffers(1, &VBO);
        glDeleteVertexArrays(1, &VAO);
    }

    void Model::draw() {
        glBindVertexArray(this->VAO);
        glDrawArrays(GL_TRIANGLES, 0, this->vert_count);
        glBindVertexArray(0);
    }

}