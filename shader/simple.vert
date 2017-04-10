#version 330 core

layout (location = 0) in vec3 a_Position;
layout (location = 1) in vec2 a_TexCoord;

out vec2 v_TexCoord;

uniform mat4 u_Projection;

void main() {
    v_TexCoord = vec2(a_TexCoord.x, a_TexCoord.y);
	gl_Position = u_Projection * vec4(a_Position, 1.0);
}
