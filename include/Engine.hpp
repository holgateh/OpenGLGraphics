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


#include "RenderingEngine/Renderer.hpp"

#include "Shader.hpp"
#include "Texture.hpp"
#include "CircularQueue.hpp"
#include "Entity.hpp"
#include "Camera.hpp"


class Engine
{
    private:
        Renderer renderer;
        GLFWwindow* window;

        double frameTime, totalTime, startTime, frameTimeMean, frameTimeMin = 100000.0, frameTimeMax;
        uint32_t frame = 0;

        uint32_t sampleCount = 100;
        double sampleTime = 0;
        double framesPerSecond = 0;
        unsigned int frameCap = 0;
        double targetFrametime = 1.0 / frameCap;

        float deltaTime = 0.0f, lastFrame = 0.0f;

        unsigned int width = 1500, height = 1000;

        bool mouseEnabled = true;



        // mouse pos
        double lastMouseX = 0.0, lastMouseY = 0.0;

        std::shared_ptr<std::vector<Entity>> entities;
        std::shared_ptr<std::vector<Light>> lights;
        std::shared_ptr<Camera> camera;


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
