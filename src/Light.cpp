#include "Light.hpp"

Light::Light() : Entity()
{
    init();
}

Light::Light(std::string ID) : Entity(ID)
{
    init();
}

void Light::init()
{
    ambient = glm::vec3(0.1f, 0.1f, 0.1f);
    diffuse = glm::vec3(1.0f, 1.0f, 1.0f);
    specular = glm::vec3(1.0f, 1.0f, 1.0f);
}

