#version 330 core

layout (location = 0) in vec3 a_Position;
layout (location = 1) in vec3 a_Normal;
layout (location = 2) in vec2 a_TexCoord;

out vec2 v_TexCoord;
out vec3 v_Normal;
out vec3 v_World_Coord;

uniform mat4 u_ModelTrans;
uniform mat4 u_ViewTrans;
uniform mat4 u_ProjTrans;

void main() {
    v_TexCoord = a_TexCoord;
    v_Normal = (u_ModelTrans * vec4(a_Normal, 1.0)).xyz;

    vec4 vert = u_ViewTrans * u_ModelTrans * vec4(a_Position, 1.0);
    v_World_Coord = (u_ModelTrans * vec4(a_Position, 1.0)).xyz;
	gl_Position = u_ProjTrans * vert;
}
