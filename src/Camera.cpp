#include "Camera.hpp"

Camera::Camera(){}
Camera::Camera(std::string ID) : Entity(ID){}


void Camera::update()
{
    glm::quat rotateYaw = glm::angleAxis(yaw, initialUp);
    glm::quat rotatePitch = glm::angleAxis(pitch, initialRight);
    glm::quat rotateTotal = rotateYaw * rotatePitch;
    front = rotateTotal * initialFront;
    right =  rotateTotal * initialRight;
}