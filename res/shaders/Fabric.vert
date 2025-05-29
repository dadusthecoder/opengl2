#version 440 core

layout(location = 0) in vec3 a_Position;

uniform mat4 u_matp;  
uniform mat4 u_matv;  
uniform float u_Time;

layout(location = 0) out vec3 v_WorldPos;

void main()
{
    vec3 displaced = a_Position;

    // Ripple displacement on Y axis
   // displaced.y = sin(displaced.x * 4.0 + u_Time) * 0.05
     //           + sin(displaced.z * 4.0 + u_Time) * 0.05;

    v_WorldPos = displaced;

    gl_Position = u_matp * u_matv * vec4(displaced, 1.0);
}
