//
// Created by opot on 19.04.17.
//

#include "Engine.h"
#include "../player/KeyBoardController.h"

#include <GL/glew.h>
#include <SDL2/SDL.h>

extern std::queue<SDL_Event> KeyBoardController::events_t;

namespace fjfj {

    Uint64 LAST = 0;

    Engine::Engine(void (*init)(void), void (*update)(float), void (*render)(void)) :
            init(init), update(update), render(render) {}

    void Engine::start() {
        SDL_Window *window;
        SDL_GLContext context;

        SDL_Init(SDL_INIT_VIDEO);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

        window = SDL_CreateWindow("OpenGl", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
                                  SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
        context = SDL_GL_CreateContext(window);
        SDL_GL_SetSwapInterval(0);
        glewInit();

        this->init();

        SDL_Event event_t;
        bool quit = false;

        while(!quit){

            while(SDL_PollEvent(&event_t)){
                if( event_t.type == SDL_QUIT ) {
                    quit = true;
                }else
                    KeyBoardController::events_t.push(event_t);
            }

            this->update((SDL_GetPerformanceCounter() - LAST) / (float)SDL_GetPerformanceFrequency());
            LAST = SDL_GetPerformanceCounter();
            this->render();

            SDL_GL_SwapWindow(window);
        }

        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

}