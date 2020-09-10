#include <tools/Texture.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

Texture::Texture(const char* texturePath, int width, int height, int numChannels)
{
    unsigned char *data = stbi_load(texturePath, &width, &height, &numChannels, 0); 
    glGenTextures(1, &ID);  
    glBindTexture(GL_TEXTURE_2D, ID);  

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if (data)
    {
        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        std::cout << "Texture loaded.\n";
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }

    stbi_image_free(data);
}

void Texture::bind()
{
    glBindTexture(GL_TEXTURE_2D, ID);
}