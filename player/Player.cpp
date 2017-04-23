//
// Created by opot on 23.04.17.
//

#include "../GlUtils/MeshLoader.h"

#include "Player.h"

Player::Player(PlayerController *controller, GLuint model_location) :
        u(0), v(0), controller(controller), model_location(model_location) {
    mesh = MeshLoader::LoadMesh("models/player.obj");
    tex = new Texture("texture/player.png");
}

void Player::update(float delta) {

}

void Player::render() {

    mesh->draw();
}