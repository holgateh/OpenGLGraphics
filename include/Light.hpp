#pragma once
#include "Entity.hpp"
// Include GLM
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

class Light : public Entity
{
    private:
       
    public:
        glm::vec3 ambient, diffuse, specular;
        float power = 15.0f;
    private:
    public:
        Light();
        Light(std::string ID);
        void init();


    
};