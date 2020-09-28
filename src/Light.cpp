#include "Light.hpp"

Light::Light(LightType type) : Entity(), type(type)
{
    init();
}

Light::Light( std::string ID, LightType type) : Entity(ID), type(type)
{
    init();
}

void Light::init()
{
    ambient = glm::vec3(0.1, 0.1, 0.1);
    diffuse = glm::vec3(1.0, 1.0, 1.0);
    specular = glm::vec3(1.0, 1.0, 1.0);

    direction = glm::vec3(0.0, -1.0, 0.0);
    angle = 0.5;
}