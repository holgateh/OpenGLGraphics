#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

// Include GLEW. Always include it before gl.h and glfw3.h, since it's a bit magic.
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
#include <GL/gl.h>

#include "tools/Vertex.hpp"


class Mesh
{
    private:
        std::string path;
    public:
        std::vector<Vertex> vertices;
        std::vector<uint32_t> indices;
    private:
        void loadModel();
    public:
        Mesh();
        Mesh(std::string path);
        Mesh(std::vector<float> vertices, std::vector<unsigned int> indices);
        

};