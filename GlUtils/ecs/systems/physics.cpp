#include "physics.h"

//#include <reactphysics3d/src/reactphysics3d.h>

#include <iostream>
#include <ecs/ECS.h>

//PhysicComponent::PhysicComponent(rp3d::RigidBody* body) : body(body) {}

void PhysicComponent::kill() {
  isAlive = false;
}

void PhysicComponent::setSpeed(glm::vec3 speed) {
  //shape->applyForceToCenterOfMass({ speed.x, speed.y, speed.y });
}

PhysicSystem::PhysicSystem() {
  //world = std::make_unique<rp3d::DynamicsWorld>(rp3d::Vector3{ 0.0, -0.02, 0.0 });
}

void PhysicSystem::update() {
  //auto it = components.begin();
  //while (it != components.end()) {
  //  if (!(*it)->isAlive) {
  //    world->destroyCollisionBody((*it)->body);
  //    it = components.erase(it);
  //  } else {
  //    it++;
  //  }
  //}
  //
  //world->update(TICK_DELTA);
}

PhysicComponent * PhysicSystem::addComponent() {
  //rp3d::Vector3 initPosition(0.0, 0.0, 0.0);
  //rp3d::Quaternion initOrientation = rp3d::Quaternion::identity();
  //rp3d::Transform transform(initPosition, initOrientation);
  //
  //rp3d::RigidBody* body;
  //body = world->createRigidBody(transform);
  //components.emplace_back(new PhysicComponent(body));
  return components.back();
}

