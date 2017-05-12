//
// Created by opot on 06.04.17.
//

#include <GL/glew.h>
#include <iostream>

#include "World.h"
#include "MainGame.h"
#include "GlUtils/Camera.h"
#include "GlUtils/Shader.h"
#include "GlUtils/Mesh.h"
#include "GlUtils/Texture.h"
#include "GlUtils/MeshLoader.h"
#include "player/Player.h"
#include "player/KeyBoardController.h"

namespace fjfj {

    Camera *cam;
    Shader *shader;
    World *world;

    GLint proj_location;
    GLint view_location;
    GLint model_location;


    void MainGame::init() {

        glEnable(GL_MULTISAMPLE);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        cam = new Camera(1366, 768, glm::vec3(0.0f, 0.0f, 5.0f));
        cam->lookAt(glm::vec3(0, 0, 0));
        shader = new Shader("shader/simple.vert", "shader/simple.frag");

        proj_location = glGetUniformLocation(shader->Program, "u_ProjTrans");
        view_location = glGetUniformLocation(shader->Program, "u_ViewTrans");
        model_location = glGetUniformLocation(shader->Program, "u_ModelTrans");

        world = new World(0.25f, 0.8f);
    }

    void MainGame::update(float delta) {
        world->update(delta, cam);
    }

    void MainGame::render() {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader->Use();

        glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(cam->GetViewMatrix()));
        glUniformMatrix4fv(proj_location, 1, GL_FALSE, glm::value_ptr(cam->perspective));
        glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(glm::mat4()));

        world->draw();

        glUseProgram(0);
    }

}
