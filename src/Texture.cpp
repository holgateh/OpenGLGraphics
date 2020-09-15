#include "Texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

Texture::Texture(std::string path)
{

    glGenTextures(1, &ID);  
    glBindTexture(GL_TEXTURE_2D, ID);  

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &numChannels, 0); 
    if (data)
    {
        //Check if the input 
        if(path.substr(path.size() - 4, 4) == ".png")
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        }
        else if (path.substr(path.size() - 4, 4) == ".jpg")
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        }
        else
        {
            throw std::runtime_error("Texture must be of type .png or .jpg.\n");
        }

        glGenerateMipmap(GL_TEXTURE_2D);
        std::cout << "Loaded texture: " << path << ".\n";
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }

    stbi_image_free(data);
}

void Texture::activate()
{
    glActiveTexture(GL_TEXTURE0 + ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    //std::cout << "texture [" << ID << "] has been bound.\n";
}