#include "updater.h"

#include <glm/gtc/type_ptr.hpp>

UpdatingComponent::UpdatingComponent(int zOrder, std::function<void(GLFWwindow*)> updateFunc) :
  zOrder(zOrder), updateFunc(updateFunc) {
  isAlive = true;
}

void UpdatingComponent::kill() {
  isAlive = false;
}

void UpdatingSystem::update() {
  auto it = components.begin();
  while (it != components.end()) {
    if (!(*it)->isAlive) {
      it = components.erase(it);
    } else {
      (*it)->updateFunc(window);
      it++;
    }
  }
}

void UpdatingSystem::setWindow(GLFWwindow * window) {
  this->window = window;
}

void UpdatingSystem::addInstance(UpdatingComponent* component) {
  components.insert(component);
}
