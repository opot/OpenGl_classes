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

    Engine::Engine(GameBody& body) : game(body) {}

    void Engine::start(int width, int height, bool fullscreen) {
        GLFWwindow *window;

        if (!glfwInit()) {
            exit(EXIT_FAILURE);
        }

        //window = glfwCreateWindow(1920, 1080, "Simple example",, nullptr);
        window = glfwCreateWindow(width, height, "Simple example", fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);


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

        game.init(window);

        while (!glfwWindowShouldClose(window)) {
            auto NOW = std::chrono::system_clock::now();
            float delta = std::chrono::duration_cast<std::chrono::duration<float>>(NOW - LAST).count();

            game.update(delta);
            LAST = NOW;

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glfwDestroyWindow(window);
        glfwTerminate();

        exit(EXIT_SUCCESS);
    }

}
