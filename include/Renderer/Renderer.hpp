#pragma once
#include "Renderer/Mesh.hpp"

#include <vector>
#include <memory>

// Include GLEW. Always include it before gl.h and glfw3.h, since it's a bit magic.
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
#include <GL/gl.h>


// Include GLM
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>



// Include Imgui
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
// Implot
#include "implot.h"

#include "tools/Shader.hpp"
#include "tools/Texture.hpp"
#include "tools/Vertex.hpp"
#include "Renderer/Mesh.hpp"
#include "Entity.hpp"



class Renderer
{
    private:
        unsigned int transformLoc = 0;
        unsigned int mvpLoc = 0;
        unsigned int lightLoc = 0;

        glm::vec3 light = {0.0f, -1.0f, 0.0f};
        std::shared_ptr<std::vector<Entity>> entities;

        Shader ourShader;
        std::string SHADER_PATH = "data/shaders/";

        float width, height;
    
    public:
        GLFWwindow* window;
        glm::mat4 proj, model, view;
    private:
    public:
        Renderer(GLFWwindow* window, float width, float height, std::shared_ptr<std::vector<Entity>>  entities);
        Renderer();
        void init();
        void startNewImGuiFrame();
        void initImGui();
        void render();
        void renderUI();
        void cleanup();
        uint32_t getNumVertices();
        uint32_t getNumTriangles();
};