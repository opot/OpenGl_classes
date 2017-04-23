//
// Created by opot on 23.04.17.
//

#ifndef GLUTGL_PLAYERCONTROLLER_H
#define GLUTGL_PLAYERCONTROLLER_H


#include <queue>

enum EventType{
    KeyDown, KeyUp, MouseMove, Empty
};

enum EventKey{
    UP, DOWN, LEFT, RIGHT, MOUSE
};

struct Event {
    EventType type;

    union {
        EventKey key;
        float delta[2];
    };
};

class PlayerController {

protected:
    std::queue<Event> events;

public:
    virtual Event getEvent() = 0;
    virtual void update() = 0;
};


#endif //GLUTGL_PLAYERCONTROLLER_H
