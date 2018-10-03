//
// Created by opot on 19.04.17.
//

#ifndef GLUTGL_ENGINE_H
#define GLUTGL_ENGINE_H

#include <GLFW/glfw3.h>

namespace fjfj {

    class Engine {
        void (*init)(GLFWwindow*);
        void (*update)(float);
        void (*render)(void);

    public:
        Engine(void (*init)(GLFWwindow*), void (*update)(float), void (*render)(void));

        void start();

    };

    //TODO Mesh concat
}

#endif //GLUTGL_ENGINE_H
