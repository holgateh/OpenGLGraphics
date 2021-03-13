#pragma once
#include <vector>
#include <memory>
#include <string>

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

#include "RenderingEngine/Mesh.hpp"

#include "Shader.hpp"
#include "Texture.hpp"
#include "Vertex.hpp"
#include "Entity.hpp"
#include "Light.hpp"
#include "Camera.hpp"
#include "ListItem.hpp"

class Renderer
{
    private:
        std::shared_ptr<std::vector<Entity>> entities;
        std::shared_ptr<std::vector<Light>> lights;
        std::shared_ptr<Camera> camera;
        

        int width, height;
    
    public:
        GLFWwindow* window;
        glm::mat4 proj, model, view;

        // Renderer mode stuff:
        std::vector<ListItem> modes = {{"NORMAL", false} , {"WIREFRAME", false}};
        int currentMode = 0;
        
    private:
    public:
        Renderer(GLFWwindow* window, float width, float height, std::shared_ptr<std::vector<Entity>>  entities,
                 std::shared_ptr<std::vector<Light>> lights, std::shared_ptr<Camera> camera);
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
