#version 330 core
out vec4 FragColor;  
in vec4 ourColor;
uniform float colour; // we set this variable in the OpenGL code.

void main()
{
    //vec2 newTexCoord = vec2(TexCoord.x, TexCoord.y);
    FragColor = ourColor;
}