//
// Created by opot on 12.05.17.
//

#ifndef GLUTGL_WORLD_H
#define GLUTGL_WORLD_H

#include "GlUtils/Mesh.h"
#include "GlUtils/Texture.h"
#include "GlUtils/Camera.h"

#include <glm/glm.hpp>

using fjfj::Mesh;
using fjfj::Texture;
using fjfj::Camera;

class World {

    Mesh *torus;
    Texture *texture;

    float r, R;
    float u, v;

    float yaw;
    float pitch;

public:
    World(float r, float R);

    void update(float delta, Camera* camera);
    void draw();
};


#endif //GLUTGL_WORLD_H