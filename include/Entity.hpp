#pragma once
#include <vector>
#include <memory>
// Include GLM
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Renderer/Mesh.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "Material.hpp"



class Entity
{
    private:
    public:
        std::string ID;
        glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f), rotation = glm::vec3(0.0f, 0.0f, 0.0f), scale = glm::vec3(1.0f, 1.0f, 1.0f);
        std::shared_ptr<Mesh> mesh;
        std::shared_ptr<Shader> shader;
        std::shared_ptr<Texture> texture;
        Material material;
        
    private:
    public:
        Entity();
        Entity(std::string ID);
    
};