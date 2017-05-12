//
// Created by opot on 12.05.17.
//

#include "World.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include <SDL2/SDL.h>
#include "GlUtils/MeshLoader.h"

World::World(float r, float R): u(0), v(0), r(r), R(R), pitch(0), yaw(0){
    texture = new Texture("texture/tor_texture2.png");
    torus = fjfj::MeshLoader::LoadMesh("models/tor_norm.obj");
}


void World::update(float delta, Camera* camera){
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    float dv = 1;
    float du = r / (R  + r * glm::cos(v)) * dv ;

    if(state[SDL_SCANCODE_W]) {
        u += delta * du * glm::cos(yaw);
        v += delta * dv * glm::sin(yaw);
    }
    if(state[SDL_SCANCODE_S]) {
        u -= delta * du * glm::cos(yaw);
        v -= delta * dv * glm::sin(yaw);
    }

    if(state[SDL_SCANCODE_A]) {
        v -= delta * dv * glm::cos(yaw);
        u += delta * du * glm::sin(yaw);
    }
    if(state[SDL_SCANCODE_D]) {
        v += delta * dv * glm::cos(yaw);
        u -= delta * du * glm::sin(yaw);
    }

    int mx, my;
    SDL_GetMouseState(&mx, &my);
    SDL_WarpMouseInWindow(NULL, 300, 300);

    //if(state[SDL_SCANCODE_A])
    yaw += (mx - 300) / 500.0f;
    pitch -= (my - 300) / 500.0f;
    pitch = glm::clamp(pitch, -1.57f, 1.57f);
    /*if(state[SDL_SCANCODE_D])
        yaw += delta;
    if(state[SDL_SCANCODE_S])
        pitch -= delta;
    if(state[SDL_SCANCODE_W])
        pitch += delta;*/

    glm::vec3 front = glm::normalize(glm::vec3(
            -(R + r * glm::cos(v)) * glm::sin(u),
            0,
            (R + r * glm::cos(v)) * glm::cos(u)
    ));

    glm::vec3 right = glm::normalize(glm::vec3(
            -r * glm::cos(u) * glm::sin(v),
            r * glm::cos(v),
            -r * glm::sin(u) * glm::sin(v)
    ));

    camera->Up = glm::cross(front, right);

    camera->Position = glm::vec3(
            (R + r * glm::cos(v)) * glm::cos(u),
            r * glm::sin(v),
            (R + r * glm::cos(v)) * glm::sin(u)
    );

    camera->Front = glm::cos(yaw) * front + glm::sin(yaw) * right;
    camera->Right = glm::normalize(glm::cross(camera->Up, camera->Front));
    glm::vec4 buf = (glm::rotate(glm::mat4(), pitch, camera->Right) * glm::vec4(camera->Front, 1.0f));
    camera->Front = glm::vec3(buf.x, buf.y, buf.z);
    camera->Up = glm::cross(camera->Front, camera->Right);
}

void World::draw(){
    glBindTexture(GL_TEXTURE_2D, texture->texture);
    torus->draw();
    glBindTexture(GL_TEXTURE_2D, 0);
}