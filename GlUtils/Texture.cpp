//
// Created by opot on 10.04.17.
//

#include "Texture.h"
#include <SOIL/SOIL.h>
#include <iostream>


namespace fjfj {

  Texture::Texture(std::string path) {
   texture = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, 0);
  }

}