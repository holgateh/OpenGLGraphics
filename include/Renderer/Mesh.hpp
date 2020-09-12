#pragma once
#include <vector>
#include <string>

// Include GLEW. Always include it before gl.h and glfw3.h, since it's a bit magic.
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
#include <GL/gl.h>

class Mesh
{
    private:
        const std::string path;
    public:
        const std::vector<float> vertices;
    private:
    public:
        Mesh(std::string path);
        Mesh(std::vector<float> vertices, std::vector<unsigned int> indices);

};