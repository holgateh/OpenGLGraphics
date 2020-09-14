#version 330 core
layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec3 aColor; // the color variable has attribute position 1
layout (location = 2) in vec3 aNorm; // the color variable has attribute position 1
layout (location = 3) in vec2 aTexCoord; // the uv coordinate has attribute position 2
  
out vec3 ourColor; // output a color to the fragment shader
out vec2 TexCoord;

uniform float colour;
uniform mat4 mvp;
uniform vec3 lightDir;
uniform vec3 lightPos;
uniform vec3 cameraDir;
uniform vec3 cameraPos;

void main()
{
    
    gl_Position = mvp * vec4(aPos, 1);
    float nColor = -1.0f * dot(aNorm , lightDir); // set ourColor to the input color we got from the vertex data
    ourColor = vec3(nColor, nColor, nColor);
    TexCoord = aTexCoord;
} 