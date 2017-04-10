#include <GL/glew.h>
#include <SDL2/SDL.h>

#include "MainGame.h"

using fjfj::MainGame;

int main(int argc, char** argv) {

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

    MainGame::init();

    SDL_Event event_t;
    bool quit = false;

    while(!quit){

        while(SDL_PollEvent(&event_t)){
            if( event_t.type == SDL_QUIT ) { quit = true; }
        }

        MainGame::update();
        MainGame::render();

        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}