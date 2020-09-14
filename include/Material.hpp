#pragma once
// Include GLM
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>


struct Material
{
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float shininess;

    Material() : ambient(glm::vec3(0.1f, 0.1f, 0.1f)),
                 diffuse(glm::vec3(1.0f, 1.0f, 1.0f)),
                 specular(glm::vec3(0.5f, 0.5f, 0.5f)),
                 shininess(0.1f)
    {
        
    }
}; 