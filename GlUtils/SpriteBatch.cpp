//
// Created by opot on 20.04.17.
//

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "SpriteBatch.h"

namespace fjfj {

SpriteBatch::SpriteBatch() {
  GLfloat vert[] = {
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
    0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
    0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,

    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
    -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
  };

  this->square = new Mesh(vert, 6);
}

void SpriteBatch::draw(const Texture &tex, GLint model_location, float x, float y, float width, float height) {

  glBindTexture(GL_TEXTURE_2D, tex.texture);
  glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(
    glm::scale(glm::translate(glm::mat4(1.0), glm::vec3(x, y, 0)), glm::vec3(width, height, 1))));

  this->square->draw();
  glBindTexture(GL_TEXTURE_2D, 0);

}

void SpriteBatch::draw(const Texture &tex, GLint model_location, glm::vec2 coords, float width, float height) {

  glBindTexture(GL_TEXTURE_2D, tex.texture);
  glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(
    glm::scale(glm::translate(glm::mat4(1.0), glm::vec3(coords, 0)), glm::vec3(width, height, 1))));

  this->square->draw();
  glBindTexture(GL_TEXTURE_2D, 0);

}

void SpriteBatch::draw(const Texture &tex, GLint model_location, float x, float y, float width, float height, float angle) {

  glBindTexture(GL_TEXTURE_2D, tex.texture);
  glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(
    glm::scale(glm::rotate(glm::translate(glm::mat4(1.0), glm::vec3(x, y, 0)), angle, glm::vec3(0, 0, 1)), glm::vec3(width, height, 1))));

  this->square->draw();
  glBindTexture(GL_TEXTURE_2D, 0);

}

void SpriteBatch::draw(const Texture &tex, GLint model_location, glm::vec2 coords, float width, float height, float angle) {

  glBindTexture(GL_TEXTURE_2D, tex.texture);
  auto mat = glm::mat4(1.0);
  mat = glm::translate(mat, glm::vec3(coords, 0));
  mat = glm::rotate(mat, angle, glm::vec3(0, 0, 1));
  mat = glm::translate(mat, { height / 4, 0, 0 });
  mat = glm::scale(mat, glm::vec3(width, height, 1));
  glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(mat));

  this->square->draw();
  glBindTexture(GL_TEXTURE_2D, 0);

}

}
