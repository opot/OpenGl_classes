//
// Created by opot on 23.04.17.
//

#include <SDL2/SDL.h>
#include "KeyBoardController.h"
#include "PlayerController.h"

Event KeyBoardController::getEvent() {
    if(!events.empty()){
        Event e = events.front();
        events.pop();
        return e;
    }
    Event e;
    e.type  = EventType::Empty;
    return e;
}

void KeyBoardController::update() {
    while(!events_t.empty()){
        SDL_Event e = events_t.front();
        Event res;
        if(e.type == SDL_KEYDOWN) {
            res.type = EventType::KeyDown;
            switch (e.key.keysym.scancode) {
                case SDL_SCANCODE_W :
                    res.data.key = EventKey::UP;
                    break;
                case SDL_SCANCODE_A :
                    res.data.key = EventKey::LEFT;
                    break;
                case SDL_SCANCODE_D :
                    res.data.key = EventKey::RIGHT;
                    break;
                case SDL_SCANCODE_S :
                    res.data.key = EventKey::DOWN;
                    break;
                default:
                    break;
            }
        } else if (e.type == SDL_MOUSEMOTION) {
                res.type = EventType::MouseMove;
                res.data.delta[0] = e.motion.xrel;
                res.data.delta[1] = e.motion.yrel;
        } else if(e.type == SDL_MOUSEBUTTONDOWN){
            res.type = EventType::KeyDown;
            res.data.key = EventKey::MOUSE;
        } else {
            res.type = Empty;
        }
        if(res.type != Empty)
            events.push(res);
        events_t.pop();
    }
}
