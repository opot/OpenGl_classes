//
// Created by opot on 19.04.17.
//

#ifndef GLUTGL_ENGINE_H
#define GLUTGL_ENGINE_H

#include <gl/glew.h>
#include <GLFW/glfw3.h>

namespace fjfj {

  class GameBody {
  public:
    virtual void init(GLFWwindow*) = 0;
    virtual void update(float delta) = 0;
    virtual void render() = 0;
    virtual ~GameBody() = default;
  };

  class Engine {
    GameBody& game;

  public:
    Engine(GameBody& body);
    void start(int width, int height, bool fullscreen);

  };
}

#endif //GLUTGL_ENGINE_H
