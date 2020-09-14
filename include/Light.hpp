#pragma once
// Include GLM
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

struct Light
{
    glm::vec3 position;
    glm::vec3 color;
    float power;
};