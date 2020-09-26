#pragma once
// Include GLM
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>


struct Material
{
    float shininess;

    Material() : shininess(5.0f) {}
}; 