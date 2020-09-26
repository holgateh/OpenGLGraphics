#pragma once
#include "Entity.hpp"

class Camera : public Entity
{
    private:
    public:
        const glm::vec3 initialFront = glm::vec3(0.0f, 0.0f, 1.0f);
        const glm::vec3 initialUp = glm::vec3(0.0f, 1.0f, 0.0f);
        const glm::vec3 initialRight = glm::vec3(1.0f, 0.0f, 0.0f);
        float pitch = 0.0f, yaw = 0.0f;
        glm::vec3 front = initialFront;
        glm::vec3 right = initialRight;
        glm::vec3 up = initialUp;
    private:
    public:
        Camera();
        Camera(std::string ID);
        void update();
};