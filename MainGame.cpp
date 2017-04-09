//
// Created by opot on 06.04.17.
//

#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>

#include "MainGame.h"
#include "Shader.h"
#include "Model.h"

using fjfj::Shader;

Shader* shader;
Model* cube;

GLfloat cube_vert[] = {
        -0.5f, -0.5f, 0.0,
        0.5f, -0.5f, 0.0,
        0.5f,  0.5f, 0.0,

        -0.5f, -0.5f, 0.0,
        -0.5f, 0.5f, 0.0,
        0.5f,  0.5f, 0.0
};

bool first = true;
void fjfj::MainGame::init() {
    shader = new Shader("shader/simple.vert", "shader/simple.frag");
    cube = new Model(cube_vert, 6);
}

void fjfj::MainGame::update() {
    glutPostRedisplay();
}

void fjfj::MainGame::render() {

    if(first){
        first = false;
        init();
    }

    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    shader->Use();

    cube->draw();

    glUseProgram(0);

    glutSwapBuffers();
}
