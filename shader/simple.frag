#version 330 core

uniform sampler2D texture0;

in vec2 v_TexCoord;
in vec3 v_Normal;
in vec3 v_World_Coord;

out vec4 frag_color;

const vec3 light = vec3(0.0, 0.0, 0.0);

void main() {
    vec4 color = texture(texture0, v_TexCoord);
    vec3 buf = color.rgb * (abs(dot(normalize(v_Normal), normalize(light + v_World_Coord))));

    float gamma = 1.0;// / pow(length(light - v_World_Coord), 1);

    color.r = pow(buf.r, gamma);
    color.g = pow(buf.g, gamma);
    color.b = pow(buf.b, gamma);
    frag_color = color;//vec4(normalize(abs(v_Normal)), 1.0);
}
