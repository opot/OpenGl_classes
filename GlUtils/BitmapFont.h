//
// Created by opot on 01.04.18.
//

#ifndef GLUTGL_BITMAPFONT_H
#define GLUTGL_BITMAPFONT_H

#include <string>
#include "Texture.h"
#include "OrthographicCamera.h"
#include "SpriteBatch.h"
#include "Shader.h"

namespace fjfj {

    class BitmapFont {
        std::string bitmaps;
        Texture *tex;
        Shader *shader;

        GLint model_loc;
        GLint proj_loc;
        GLint data_loc;
        GLint size_loc;
    public:

        BitmapFont(std::string bitmaps, Texture *tex);

        void
        draw(SpriteBatch *batch, OrthographicCamera *cam, std::string str, float x, float y, float width, float height);

    };
}

#endif //GLUTGL_BITMAPFONT_H
