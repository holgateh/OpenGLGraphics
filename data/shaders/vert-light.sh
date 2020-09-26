#version 330 core
struct Light {
    vec3 pos;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float power;
};
  


layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec3 aColor; // the color variable has attribute position 1
layout (location = 2) in vec3 aNorm; // the color variable has attribute position 1
layout (location = 3) in vec2 aTexCoord; // the uv coordinate has attribute position 2
  
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform Light light;

out vec4 ourColor; // output a color to the fragment shader

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1);

    ourColor = vec4(light.diffuse, 1.0);
} 