#version 330 core
out vec4 FragColor;  
in vec3 ourColor;
in vec2 TexCoord;
uniform float colour; // we set this variable in the OpenGL code.
uniform sampler2D ourTexture;

void main()
{
    vec2 newTexCoord = vec2(TexCoord.x * colour, TexCoord.y);
    FragColor = texture(ourTexture, newTexCoord);
}