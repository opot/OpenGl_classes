//
// Created by opot on 23.04.17.
//

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
    for(int i = 0 ; i < events_t.size(); i++)
        
}