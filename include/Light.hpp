#pragma once
#include "Entity.hpp"
// Include GLM
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

class Light : public Entity
{
    private:

    public:
        glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
        float power = 1.0f;

    private:
    public:
    Light();
    Light(std::string ID);

    
};