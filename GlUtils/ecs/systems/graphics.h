#pragma once

#include <set>
#include <glm/glm.hpp>

#include <Mesh.h>
#include <Shader.h>
#include <Texture.h>
#include <Camera.h>

class GraphicComponent {
  friend class GraphicSystem;
  friend struct GraphicComponentComparator;

private:
  bool isAlive;
  int zOrder;
  glm::mat4 actualMatrix;
  glm::mat4 prevMatrix;
  glm::mat4 curMatrix;

  fjfj::Mesh& mesh;
  fjfj::Shader& shader;
  fjfj::Texture& texture;

  GLint projLoc, viewLoc, objLoc;

  void updateMatrix(float completion);
  const GLfloat* getPosition();

public:
  GraphicComponent(int zOrder, fjfj::Mesh& mesh, fjfj::Shader& shader, fjfj::Texture& texture);
  void kill();
  void setPosition(glm::mat4& newPos);
  void updatePosition(glm::mat4& newPos);

};

struct GraphicComponentComparator {
  bool operator() (const GraphicComponent* a, const GraphicComponent* b) {
    return a->zOrder < b->zOrder;
  }
};

class GraphicSystem {
public:
  GraphicSystem(int width, int height);

  void draw();
  void update(float completion);

  void addInstance(GraphicComponent* component);
  fjfj::Camera camera;

private:
  std::multiset<GraphicComponent*, GraphicComponentComparator> components;

};