#include "Light.hpp"

Light::Light() : Entity()
{
    material.ambient = glm::vec3(0.1f, 0.1f, 0.1f);
    material.specular = glm::vec3(1.0f, 1.0f, 1.0f);
}
Light::Light(std::string ID) : Entity(ID)
{
    material.ambient = glm::vec3(0.1f, 0.1f, 0.1f);
    material.specular = glm::vec3(1.0f, 1.0f, 1.0f);
}