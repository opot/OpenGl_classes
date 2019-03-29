#pragma once

#include <set>
#include <functional>

struct GLFWwindow;

class UpdatingComponent {
  friend class UpdatingSystem;
  friend struct UpdatingComponentComparator;
private:
  bool isAlive;
  int zOrder;
  std::function<void(GLFWwindow*)> updateFunc;

public:
  UpdatingComponent(int zOrder, std::function<void(GLFWwindow*)> updateFunc);
  void kill();

};

struct UpdatingComponentComparator {
  bool operator() (const UpdatingComponent* a, const UpdatingComponent* b) {
    return a->zOrder < b->zOrder;
  }
};

class UpdatingSystem {
public:
  void update();
  void setWindow(GLFWwindow* window);
  void addInstance(UpdatingComponent* component);

private:
  GLFWwindow* window;
  std::multiset<UpdatingComponent*, UpdatingComponentComparator> components;

};