#version 330 core
layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec3 aColor; // the color variable has attribute position 1
layout (location = 2) in vec3 aNormal; // the color variable has attribute position 1
layout (location = 3) in vec2 aTexCoord; // the uv coordinate has attribute position 2
  
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;



out vec4 ourColor; // output a color to the fragment shader
out vec2 TexCoords;
out vec3 FragPos;
out vec3 Normal;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1);
    TexCoords = aTexCoord;
    FragPos = (model * vec4(aPos, 1)).xyz;  
    Normal = mat3(transpose(inverse(model))) * aNormal; 
} 