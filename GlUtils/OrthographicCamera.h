//
// Created by opot on 20.04.17.
//

#ifndef GLUTGL_ORTHOGRAPHICCAMERA_H
#define GLUTGL_ORTHOGRAPHICCAMERA_H

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace fjfj {

    class OrthographicCamera {

    public:
        float width, height;
        glm::vec2 position;
        glm::mat4 proj;

        OrthographicCamera(float width, float height);
        void update();
        float getWidth();
        float getHeight();
        glm::vec2 getPosition();
    };

}

#endif //GLUTGL_ORTHOGRAPHICCAMERA_H
