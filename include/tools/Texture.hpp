#pragma once
// Include GLEW. Always include it before gl.h and glfw3.h, since it's a bit magic.
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
#include <GL/gl.h>
  
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>



  

class Texture
{
public:
    //Texture ID
    unsigned int ID;

    Texture(const char* texturePath, int width, int height, int numChannels);
    void bind();
};