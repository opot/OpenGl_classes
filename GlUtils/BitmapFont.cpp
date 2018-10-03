//
// Created by opot on 01.04.18.
//

#include "BitmapFont.h"

fjfj::BitmapFont::BitmapFont(std::string bitmaps, fjfj::Texture *tex) : bitmaps(std::move(bitmaps)), tex(tex) {
    shader = new Shader("shader/font.vert", "shader/font.frag");
    model_loc = glGetUniformLocation(shader->Program, "u_ModelTrans");
    proj_loc = glGetUniformLocation(shader->Program, "u_ProjTrans");
    data_loc = glGetUniformLocation(shader->Program, "u_Data");
    size_loc = glGetUniformLocation(shader->Program, "u_Size");
}

void fjfj::BitmapFont::draw(fjfj::SpriteBatch *batch, fjfj::OrthographicCamera *cam, std::string str, float x, float y,
                            float width, float height) {
    shader->Use();
    glUniformMatrix4fv(proj_loc, 1, GL_FALSE, glm::value_ptr(cam->proj));
    glUniform1i(size_loc, (int)bitmaps.size());
    for (int i = 0; i < str.size(); i++) {
        auto pos = bitmaps.find(str[i]);
        if(pos != bitmaps.npos) {
            glUniform1i(data_loc, (int)pos);
            batch->draw(*tex, model_loc, x + width * i, y, width, height);
        }
    }
    glUseProgram(0);
}
