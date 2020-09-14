#pragma once
// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <thread>
#include <chrono>
#include <memory>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

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

// Include Imgui
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
// Implot
#include "implot.h"


#include "Shader.hpp"
#include "Texture.hpp"
#include "Timer.hpp"
#include "CircularQueue.hpp"
#include "Entity.hpp"

#include "Renderer/Renderer.hpp"

class Engine
{
    private:
        Renderer renderer;
        GLFWwindow* window;

        Timer frameTimer, totalTimer;
        double frameTime, totalTime, frameTimeMean, frameTimeMin = 100000.0, frameTimeMax;
        uint32_t frame = 0;
        unsigned int frameCap = 0;

        float deltaTime = 0.0f, lastFrame = 0.0f;

        unsigned int width = 1500, height = 1000;

        bool mouseEnabled = true;

        const glm::vec3 initialFront = glm::vec3(0.0f, 0.0f, 1.0f);
        const glm::vec3 initialUp = glm::vec3(0.0f, 1.0f, 0.0f);
        const glm::vec3 initialRight = glm::vec3(1.0f, 0.0f, 0.0f);
        float anglePitch = 0.0f, angleYaw = 0.0f;
        //Camera stuff
        glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
        glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 cameraFront = initialFront;
        glm::vec3 cameraRight = initialRight;
        glm::vec3 cameraUp = initialUp;

        // mouse pos
        double lastMouseX = 0.0, lastMouseY = 0.0;

        std::shared_ptr<std::vector<Entity>> entities;

    public:
    private:

        void initWindow();
        void render();
        void update();
        void updateUI();
        void processInput();
        void toggleMouse();
        void updateCamera();
        void cleanup();
        //callbacks:
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

    public:
        Engine();
        void run();

};

// Utility (position temporary)
struct ScrollingBuffer {
    int MaxSize;
    int Offset;
    ImVector<ImVec2> Data;
    ScrollingBuffer() {
        MaxSize = 2000;
        Offset  = 0;
        Data.reserve(MaxSize);
    }
    void AddPoint(float x, float y) {
        if (Data.size() < MaxSize)
            Data.push_back(ImVec2(x,y));
        else {
            Data[Offset] = ImVec2(x,y);
            Offset =  (Offset + 1) % MaxSize;
        }
    }
    void Erase() {
        if (Data.size() > 0) {
            Data.shrink(0);
            Offset  = 0;
        }
    }
};