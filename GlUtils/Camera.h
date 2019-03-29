//
// Created by opot on 10.04.17.
//

#ifndef GLUTGL_CAMERA_H
#define GLUTGL_CAMERA_H

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <math.h>

namespace fjfj {

    class Camera {
    public:
        // Camera Attributes
        glm::vec3 Position;
        glm::vec3 Front;
        glm::vec3 Up;
        glm::vec3 Right;
        glm::vec3 WorldUp;
        // Perspective options
        float fov = 45.0f;
        float aspect;
        float near = 0.01f;
        float far = 100.0f;
        float width;
        float height;
        glm::mat4 projection;
        glm::mat4 view;

        Camera(int width, int height, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
               glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f));

        glm::mat4 GetViewMatrix();

        void lookAt(glm::vec3 target);
        void update();
        void updateProjection();

    };

}
#endif //GLUTGL_CAMERA_H
