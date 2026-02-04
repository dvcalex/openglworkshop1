#version 410 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uv;

uniform mat4 u_mvp;

out vec2 v_uv;

void main()
{
    v_uv = uv;
    vec4 point = vec4(position, 1.0); // set w component to 1.0 since we are treating as a point
    gl_Position = u_mvp * point;
}
