//
// Created by opot on 23.04.17.
//

#ifndef GLUTGL_KEYBOARDCONTROLLER_H
#define GLUTGL_KEYBOARDCONTROLLER_H

#include <SDL2/SDL_events.h>
#include "PlayerController.h"

class KeyBoardController : public PlayerController {
public:

    static std::queue<SDL_Event> events_t;

    virtual Event getEvent();
    virtual void update();
};


#endif //GLUTGL_KEYBOARDCONTROLLER_H
