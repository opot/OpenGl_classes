//
// Created by opot on 23.04.17.
//

#ifndef GLUTGL_PLAYER_H
#define GLUTGL_PLAYER_H

#include <GL/glew.h>

#include "../GlUtils/Mesh.h"
#include "../GlUtils/Texture.h"
#include "PlayerController.h"

using namespace fjfj;

class Player {

    float u, v;

    Mesh* mesh;
    Texture* tex;
    GLuint model_location;

    PlayerController *controller;

public:
    Player(PlayerController *controller, GLuint model_location);

    void update(float delta);
    void render();

};


#endif //GLUTGL_PLAYER_H
