//
// Created by opot on 12.05.17.
//

#include "World.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <SDL2/SDL.h>
#include "GlUtils/MeshLoader.h"

World::World(float r, float R): u(0), v(0), r(r), R(R), pitch(0), yaw(0){
    texture = new Texture("texture/tor.png");
    torus = fjfj::MeshLoader::LoadMesh("models/tor_norm.obj");
}


void World::update(float delta, Camera* camera){
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if(state[SDL_SCANCODE_UP])
        u += delta;
    if(state[SDL_SCANCODE_DOWN])
        u -= delta;
    if(state[SDL_SCANCODE_LEFT])
        v -= delta;
    if(state[SDL_SCANCODE_RIGHT])
        v += delta;
    if(state[SDL_SCANCODE_A])
        yaw -= delta;
    if(state[SDL_SCANCODE_D])
        yaw += delta;
    if(state[SDL_SCANCODE_S])
        pitch -= delta;
    if(state[SDL_SCANCODE_W])
        pitch += delta;

    camera->Up = glm::normalize(glm::vec3( -(R + r * glm::cos(v)) * glm::cos(u) * glm::cos(v) * r,
                                -(R + r * glm::cos(v)) *  glm::sin(v) * (glm::sin(u) * glm::sin(u) + r * glm::cos(u) * glm::cos(u)),
                                -(R + r * glm::cos(v)) * glm::sin(u) * glm::cos(v) * r));

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