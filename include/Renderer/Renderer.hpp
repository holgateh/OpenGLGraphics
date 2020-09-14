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

#include "Shader.hpp"
#include "Texture.hpp"
#include "Vertex.hpp"
#include "Renderer/Mesh.hpp"
#include "Entity.hpp"



class Renderer
{
    private:
        unsigned int transformLoc = 0;
        unsigned int modelLoc = 0;
        unsigned int viewLoc = 0;
        unsigned int projectionLoc = 0;
        unsigned int lightPosLoc = 0;
        unsigned int materialDiffuseColorLoc = 0;
        unsigned int materialAmbientColorLoc = 0;
        unsigned int materialSpecularColorLoc = 0;
        unsigned int lightColorLoc = 0;
        unsigned int lightPowerLoc = 0;

        glm::vec3 lightPos = {10.0f, 10.0f, 10.0f};
        glm::vec3 lightColor = {1.0f, 1.0f, 1.0f};
        float lightPower = 60.0f;

        glm::vec3 materialDiffuseColor = {0.0, 1.0f, 0.0f};
        glm::vec3 materialAmbientColor = {0.1f, 0.1f, 0.1f};
        glm::vec3 materialSpecularColor = {1.0f, 1.0f, 1.0f};

        std::shared_ptr<std::vector<Entity>> entities;

        Shader ourShader;
        std::string SHADER_PATH = "data/shaders/";

        int width, height;
    
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
        void viewportSizeChanged();
};