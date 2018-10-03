//
// Created by opot on 10.04.17.
//

#include "Texture.h"
#include <SOIL/SOIL.h>
#include <iostream>


namespace fjfj {

    Texture::Texture(std::string path) {
        unsigned char* tex = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_RGBA);
        glGenTextures(1, &this->texture);
        glBindTexture(GL_TEXTURE_2D,this->texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            // Set texture filtering
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, tex);

        SOIL_free_image_data(tex);

        glBindTexture(GL_TEXTURE_2D, 0);
    }

}