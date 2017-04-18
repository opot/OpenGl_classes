//
// Created by opot on 06.04.17.
//

#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>

#include "MainGame.h"
#include "GlUtils/Camera.h"
#include "GlUtils/Shader.h"
#include "GlUtils/Mesh.h"
#include "GlUtils/Texture.h"

namespace fjfj {

    Camera *cam;
    Shader *shader;
    Mesh *cube;
    Texture *texture;

    GLint proj_location;
    GLint tex_location;

    glm::mat4 rot;

    void MainGame::init() {

        glEnable(GL_MULTISAMPLE);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        cam = new Camera(800, 600, glm::vec3(1.0f, 1.0f, -3.0f));
        cam->lookAt(glm::vec3(0, 0, 0));
        shader = new Shader("shader/simple.vert", "shader/simple.frag");
        cube = Mesh::genCube();

        proj_location = glGetUniformLocation(shader->Program, "u_Projection");
        tex_location = glGetUniformLocation(shader->Program, "texture0");

        rot = glm::rotate(glm::mat4(), 0.000001f, glm::vec3(1, 1, 0));
        texture = new Texture("texture/test.png");

    }

    void MainGame::update(float delta) {
        rot = rot * glm::rotate(glm::mat4(), 3.14f * delta, glm::vec3(1, 0, 0));
    }

    void MainGame::render() {

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader->Use();

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture->texture);

        glUniform1i(tex_location, 0);

        glUniformMatrix4fv(proj_location, 1, GL_FALSE, glm::value_ptr(cam->GetCombinedMatrix() * rot));

        cube->draw();
        glBindTexture(GL_TEXTURE_2D, 0);

        glUseProgram(0);

    }

}
