//
// Created by opot on 20.04.17.
//

#include "OrthographicCamera.h"

namespace fjfj{

    OrthographicCamera::OrthographicCamera(float width, float height) : width(width), height(height), position(0, 0) {
        this->update();
    }

    void OrthographicCamera::update() {
        this->proj = glm::ortho(position.x - width / 2, position.x + width / 2,
                                position.y - height / 2, position.y + height / 2);
    }

    float OrthographicCamera::getHeight() {
        return height;
    }

    float OrthographicCamera::getWidth() {
        return width;
    }

    glm::vec2 OrthographicCamera::getPosition() {
        return position;
    }

}