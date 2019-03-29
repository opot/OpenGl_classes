#include "graphics.h"

#include <glm/gtc/type_ptr.hpp>

GraphicComponent::GraphicComponent(int zOrder, fjfj::Mesh& mesh, fjfj::Shader& shader, fjfj::Texture& texture) :
  zOrder(zOrder), mesh(mesh), shader(shader), texture(texture) {
  isAlive = true;
  actualMatrix = glm::mat4(1.0);
  prevMatrix = glm::mat4(1.0);
  curMatrix = glm::mat4(1.0);
  projLoc = glGetUniformLocation(shader.Program, "u_ProjTrans");
  viewLoc = glGetUniformLocation(shader.Program, "u_ViewTrans");
  objLoc = glGetUniformLocation(shader.Program, "u_ModelTrans");
}

void GraphicComponent::kill() {
  isAlive = false;
}

void GraphicComponent::setPosition(glm::mat4 & newPos) {
  prevMatrix = std::move(newPos);
  curMatrix = prevMatrix;
}

void GraphicComponent::updatePosition(glm::mat4 & newPos) {
  prevMatrix = std::move(curMatrix);
  curMatrix = std::move(newPos);
}

void GraphicComponent::updateMatrix(float completion) {
  actualMatrix = (prevMatrix * (1 - completion)) + (curMatrix * completion);
}

const GLfloat* GraphicComponent::getPosition() {
  return glm::value_ptr(actualMatrix);
}

GraphicSystem::GraphicSystem(int width, int height) : camera(width, height) {}

void GraphicSystem::draw() {
  for (auto& comp : components) {
    comp->shader.Use();
    glBindTexture(GL_TEXTURE_2D, comp->texture.texture);
    glUniformMatrix4fv(comp->projLoc, 1, false, glm::value_ptr(camera.projection));
    glUniformMatrix4fv(comp->viewLoc, 1, false, glm::value_ptr(camera.GetViewMatrix()));
    glUniformMatrix4fv(comp->objLoc, 1, false, comp->getPosition());
    comp->mesh.draw();
  }
}

void GraphicSystem::update(float completion) {
  auto it = components.begin();
  while (it != components.end()) {
    if (!(*it)->isAlive) {
      it = components.erase(it);
    } else {
      (*it)->updateMatrix(completion);
      it++;
    }
  }

  camera.update();
}

void GraphicSystem::addInstance(GraphicComponent* component) {
  components.insert(component);
}
