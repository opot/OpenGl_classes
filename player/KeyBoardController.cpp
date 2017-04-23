//
// Created by opot on 23.04.17.
//

#include <SDL2/SDL.h>
#include "KeyBoardController.h"

Event KeyBoardController::getEvent() {
    if(!events.empty()){
        Event e = events.front();
        events.pop();
        return e;
    }

    return {EventType::Empty, EventKey::LEFT};
}

void KeyBoardController::update() {
    /*while(!events_t.empty()){
        SDL_Event e = events_t.front();

        if(e.type == SDL_KEYDOWN) {
            Event res;

            switch (e.key) {
                case SDL_SCANCODE_W:
                    res.key = EventKey::UP; return;
            }
        }

        events_t.pop();
    }*/

void KeyBoardController::update() {
    for(int i = 0 ; i < events_t.size(); i++);

}