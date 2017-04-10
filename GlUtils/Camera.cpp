//
// Created by opot on 10.04.17.
//

#include "Camera.h"

namespace fjfj {

    Camera::Camera(int width, int height, glm::vec3 position, glm::vec3 up, GLfloat yaw, GLfloat pitch) : Front(
            glm::vec3(0.0f, 0.0f, -1.0f)) {
        this->Position = position;
        this->WorldUp = up;
        this->Yaw = yaw;
        this->Pitch = pitch;
        this->aspect = (float) width / height;
        this->update();
    }

    glm::mat4 Camera::GetViewMatrix() {
        return glm::lookAt(this->Position, this->Position + this->Front, this->Up);
    }

    glm::mat4 Camera::GetCombinedMatrix() {
        return glm::perspective(this->fov, this->aspect, this->near, this->far) * this->GetViewMatrix();
    }

    void Camera::lookAt(glm::vec3 target) {
        this->Front = glm::normalize(target - this->Position);
        this->Right = glm::normalize(glm::cross(this->Front, this->WorldUp));
        this->Up = glm::normalize(glm::cross(this->Right, this->Front));

        this->Pitch = asin(this->Front.y);
        this->Yaw = acos(this->Front.x / cos(this->Front.y));
    }

    void Camera::update() {
        // Calculate the new Front vector
        glm::vec3 front;
        front.x = cos(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
        front.y = sin(glm::radians(this->Pitch));
        front.z = sin(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
        this->Front = glm::normalize(front);
        // Also re-calculate the Right and Up vector
        this->Right = glm::normalize(glm::cross(this->Front,
                                                this->WorldUp));
        this->Up = glm::normalize(glm::cross(this->Right, this->Front));
    }

}