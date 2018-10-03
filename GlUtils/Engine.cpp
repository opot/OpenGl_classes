//
// Created by opot on 19.04.17.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Engine.h"

#include <iostream>
#include <chrono>

namespace fjfj {

    auto LAST = std::chrono::system_clock::now();

    Engine::Engine(void (*init)(GLFWwindow *), void (*update)(float), void (*render)(void)) :
            init(init), update(update), render(render) {}

    void Engine::start() {
        GLFWwindow *window;

        if (!glfwInit()) {
            exit(EXIT_FAILURE);
        }

        //window = glfwCreateWindow(1920, 1080, "Simple example", glfwGetPrimaryMonitor(), nullptr);
        window = glfwCreateWindow(1280, 720, "Simple example", nullptr, nullptr);


        if (!window) {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(window);

        glewExperimental = GL_TRUE;
        GLenum err = glewInit();
        if (err != GLEW_OK) {
            std::cout << "glewInit failed, aborting." << std::endl;
        }

        this->init(window);

        while (!glfwWindowShouldClose(window)) {
            auto NOW = std::chrono::system_clock::now();
            float delta = std::chrono::duration_cast<std::chrono::duration<float>>(NOW - LAST).count();

            this->update(delta);
            LAST = NOW;
            this->render();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glfwDestroyWindow(window);
        glfwTerminate();

        exit(EXIT_SUCCESS);
    }

}
