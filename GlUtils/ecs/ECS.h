#pragma once

#include <map>
#include <vector>

#include "systems/graphics.h"
#include "systems/updater.h"
#include "systems/physics.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int TICKS_PER_SECOND = 20;
const float TICK_DELTA = 1.0f / TICKS_PER_SECOND;

struct GLFWwindow;

class Ecs {
public:
  Ecs();
  void init(GLFWwindow* window);
  void draw();
  void update(float delta);

  GraphicSystem graphics;
  UpdatingSystem updater;
  PhysicSystem physics;

private:
  float timeSinceTick;
};
