//
// Created by opot on 06.04.17.
//

#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>

#include "MainGame.h"
#include "GlUtils/Camera.h"
#include "GlUtils/Shader.h"
#include "GlUtils/Model.h"

using fjfj::Shader;
using fjfj::Camera;
using fjfj::Model;

Camera *cam;
Shader* shader;
Model* cube;

GLint proj_location;

GLfloat cube_vert[] = {
        -0.5f, -0.5f, 0.0,
        0.5f, -0.5f, 0.0,
        0.5f,  0.5f, 0.0,

        -0.5f, -0.5f, 0.0,
        -0.5f, 0.5f, 0.0,
        0.5f,  0.5f, 0.0
};

bool first = true;
glm::mat4 rot;

void fjfj::MainGame::init() {
    cam = new Camera(800, 600, glm::vec3(0.0f, 0.0f, 2.0f));
    cam->lookAt(glm::vec3(0,0,0));
    shader = new Shader("shader/simple.vert", "shader/simple.frag");
    cube = new Model(cube_vert, 6);
    proj_location = glGetUniformLocation(shader->Program, "u_Projection");
    rot = glm::rotate(glm::mat4(), 0.001f, glm::vec3(1, 0 ,0));
}

void fjfj::MainGame::update() {

    glm::vec4 buf = glm::vec4(cam->Front, 1.0f);
    buf = rot * buf;
    cam->Front.x = buf.x;
    cam->Front.y = buf.y;
    cam->Front.z = buf.z;
}

void fjfj::MainGame::render() {

    if(first){
        first = false;
        init();
    }

    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    shader->Use();

    glUniformMatrix4fv(proj_location, 1, GL_FALSE, glm::value_ptr(cam->GetCombinedMatrix()));

    cube->draw();

    glUseProgram(0);

}
