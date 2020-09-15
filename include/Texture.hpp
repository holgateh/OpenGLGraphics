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
    public:
        unsigned int ID;
        int width, height, numChannels;

    Texture(std::string path);
    void activate();
};