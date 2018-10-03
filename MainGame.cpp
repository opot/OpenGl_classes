//
// Created by opot on 06.04.17.
//

#include <GL/glew.h>

#include "MainGame.h"
#include "Sphere.h"

namespace fjfj {

    Camera *cam;
    Sphere *sph;

    void MainGame::init() {

        glEnable(GL_MULTISAMPLE);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        cam = new Camera(1366, 768, glm::vec3(1.0f, 0.0f, 1.0f));
        cam->lookAt(glm::vec3(0, 0, 1));

        sph = new Sphere(20, 20, 0.5);
    }

    void MainGame::update(float delta) {
        sph->update(*cam, delta);
    }

    void MainGame::render() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        sph->draw(*cam);
    }

}
