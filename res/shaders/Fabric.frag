#version 440 core

layout(location = 0) in vec3 v_WorldPos;

layout(location = 0) out vec4 FragColor;

uniform vec3 u_viewp;  // camera/view position

void main()
{
    vec3 baseColor = vec3(0.10, 0.10, 0.10);

    // Distance from camera to fragment position
    float dist = distance(u_viewp, v_WorldPos);

    // Fade from 1 to 0 over a distance of 20 units
    float fade = clamp(1.0 - dist / 50.0, 0.0, 1.0);

    FragColor = vec4(baseColor,fade);
}
