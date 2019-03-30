#pragma once

#include <glm/glm.hpp>
//#include <reactphysics3d/src/reactphysics3d.h>

#include <vector>
#include <functional>

class PhysicComponent {
  friend class PhysicSystem;
private:
  bool isAlive;
  //PhysicComponent(rp3d::RigidBody* body);

public:
  //rp3d::RigidBody* body;
  //std::unique_ptr<rp3d::CollisionShape> shape;

  void kill();
  void setSpeed(glm::vec3 speed);
};

class PhysicSystem {
public:
  PhysicSystem();
  void update();
  PhysicComponent* addComponent();

private:
  //std::unique_ptr<rp3d::DynamicsWorld> world;
  std::vector<PhysicComponent*> components;

};