#pragma once
#include <vector>
#include <memory>
// Include GLM
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Renderer/Mesh.hpp"
#include "tools/Shader.hpp"
#include "tools/Texture.hpp"



struct Entity
{
    std::string ID;
    glm::vec3 pos, rotation, scale;
    std::shared_ptr<Mesh> mesh;
    Shader* shader;
    Texture* texture;
};