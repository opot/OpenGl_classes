#include "ECS.h"

#include <iostream>

Ecs::Ecs() : graphics(SCREEN_WIDTH, SCREEN_HEIGHT), timeSinceTick(0) {}

void Ecs::init(GLFWwindow* window) {
  updater.setWindow(window);
}

void Ecs::draw() {
  graphics.draw();
}

void Ecs::update(float delta) {
  //std::cout << "INFO::FPS " << 1 / delta << std::endl;
  timeSinceTick += delta;

  while (timeSinceTick > TICK_DELTA) {
    timeSinceTick -= TICK_DELTA;
    updater.update();
    physics.update();
  }

  float completion = timeSinceTick / TICK_DELTA;

  graphics.update(completion);
}
