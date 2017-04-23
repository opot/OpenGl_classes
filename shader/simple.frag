#version 330 core

uniform sampler2D texture0;

in vec2 v_TexCoord;
in vec3 v_Normal;
in vec3 v_World_Coord;

out vec4 frag_color;

const vec3 light = vec3(0.0, 0.0, 1.0);

void main() {
    //vec4 color = texture(texture0, v_TexCoord);
    //color.rgb = color.rgb * abs(dot(normalize(v_Noraml), light));
    frag_color = vec4(normalize(abs(v_Normal)), 1.0);//color;
}
