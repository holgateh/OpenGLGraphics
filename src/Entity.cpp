#include "Entity.hpp"

Entity::Entity(){}

Entity::Entity(std::string ID)
{
    this->ID = ID;
}

void Entity::update()
{
    //Calculate new 
        model = glm::mat4(1.0f);
        model = glm::translate(model, pos);
        glm::quat rotationQuat = glm::angleAxis(rotation.x, glm::vec3(0.0, 1.0f, 0.0f)) *
                                 glm::angleAxis(rotation.y, glm::vec3(1.0, 0.0f, 0.0f)) *
                                 glm::angleAxis(rotation.z, glm::vec3(0.0, 0.0f, 1.0f));
            
        model = model * glm::toMat4(rotationQuat);
        model = glm::scale(model, scale);
}