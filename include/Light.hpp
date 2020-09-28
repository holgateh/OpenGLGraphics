#pragma once
#include "Entity.hpp"
// Include GLM
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

enum class LightType
{
    POINT, DIRECTIONAL
};

class Light : public Entity
{
    private:
       
    public:
        const LightType type;
        glm::vec3 ambient, diffuse, specular;

        float power = 15.0f;

        glm::vec3 direction;
        float angle;
    private:
    public:
        Light(LightType type = LightType::POINT);
        Light(std::string ID, LightType type = LightType::POINT);
        void init();


    
};