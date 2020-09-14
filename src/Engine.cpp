#include "Engine.hpp"

void Engine::toggleMouse()
{
    if(mouseEnabled)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        glfwGetCursorPos(window, &lastMouseX, &lastMouseY);
    }
    else
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
    mouseEnabled = !mouseEnabled;
}

void Engine::processInput()
{
    const float cameraSpeed = 2.5f * frameTime;
    const float cameraRotateSpeed = 2.0f * frameTime; // adjust accordingly
    if(!mouseEnabled)
    {
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
            cameraPos += cameraSpeed * cameraFront;
        }

        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
            cameraPos -= cameraSpeed * cameraFront;
        }

        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
        }

        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
        }

        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
        {
            cameraPos += glm::normalize(cameraUp) * cameraSpeed;
        }

        if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
        {
            cameraPos -= glm::normalize(cameraUp) * cameraSpeed;
        }

        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        double deltaX = xpos - lastMouseX;
        double deltaY = ypos - lastMouseY;
        lastMouseX = xpos;
        lastMouseY = ypos;
        
        if (deltaX != 0.0)
        {
            float deltaYaw = deltaX * cameraRotateSpeed;
            angleYaw -= deltaYaw;
            glm::quat rotateYaw = glm::angleAxis(-deltaYaw, cameraUp);
            cameraFront = rotateYaw * cameraFront;
            cameraRight = rotateYaw * cameraRight;
        }
        if (deltaY != 0.0)
        {
            float deltaPitch = deltaY * cameraRotateSpeed;
            anglePitch += deltaPitch;
            float boundry = 0.1;
            if(anglePitch > glm::pi<double>()/2.0 - boundry)
            {
                deltaPitch = deltaPitch - (anglePitch - glm::pi<double>()/2.0 + boundry);
                anglePitch = glm::pi<double>()/2.0 - boundry;
            }
            else if (anglePitch < -glm::pi<double>()/2.0 + boundry)
            {
                deltaPitch = deltaPitch + (-glm::pi<double>()/2.0 + boundry - anglePitch);
                anglePitch = -glm::pi<double>()/2.0 + boundry;
            }
        }    

    }
    
   
}


void Engine::updateCamera()
{
    glm::quat rotateYaw = glm::angleAxis(angleYaw, initialUp);
    glm::quat rotatePitch = glm::angleAxis(anglePitch, initialRight);
    glm::quat rotateTotal = rotateYaw * rotatePitch;
    cameraFront = rotateTotal * initialFront;
    cameraRight =  rotateTotal* initialRight;
}

void Engine::updateUI()
{
    // render your GUI
    ImGui::Begin("Performance Statistics");
    ImGui::Text(("Vertices: " + std::to_string(renderer.getNumVertices())).c_str());
    ImGui::Text(("Triangles: " + std::to_string(renderer.getNumTriangles())).c_str());
    ImGui::Text(("Frame: " + std::to_string(frame)).c_str());
    ImGui::Text(("Frame time: " + std::to_string(frameTime* 1000.0) + "ms" ).c_str());
    ImGui::Text(("Mean frame time: " + std::to_string(frameTimeMean * 1000.0) + "ms" ).c_str());
    ImGui::Text(("Min frame time: " + std::to_string(frameTimeMin * 1000.0) + "ms" ).c_str());
    ImGui::Text(("Max frame time: " + std::to_string(frameTimeMax * 1000.0) + "ms" ).c_str());
    static ScrollingBuffer sdata1;
    sdata1.AddPoint(totalTime, frameTime*1000.0);

    static float history = 1.0f;
    ImGui::SliderFloat("History",&history,0.1,5,"%.1f s");
    ImPlot::SetNextPlotLimitsX(totalTime - history, totalTime, ImGuiCond_Always);
    ImPlot::SetNextPlotLimitsY(0, frameTimeMean * 3 * 1000, ImGuiCond_Always);
    if (ImPlot::BeginPlot("##Scrolling", NULL, NULL, ImVec2(200,75), 0, ImPlotAxisFlags_NoTickLabels, ImPlotAxisFlags_NoTickLabels | ImPlotAxisFlags_LockMin)) {
        ImPlot::PlotLine("", &sdata1.Data[0], sdata1.Data.size(), sdata1.Offset);
        ImPlot::EndPlot();
    }
    
    ImGui::End();

    ImGui::Begin("Camera Control");
    ImGui::Text("Position: ");
    ImGui::InputFloat("x", &cameraPos.x, 0.0f, 0.0f, "%f");
    ImGui::InputFloat("y", &cameraPos.y, 0.0f, 0.0f, "%f");
    ImGui::InputFloat("z", &cameraPos.z, 0.0f, 0.0f, "%f");
    ImGui::Text("Rotation: ");
    ImGui::SliderFloat("pitch: ",&anglePitch, -glm::pi<float>()/2, glm::pi<float>()/2,"%.1f");
    ImGui::SliderFloat("yaw: ",&angleYaw ,0.0f ,2*glm::pi<float>(), "%.1f");
    ImGui::End();


    ImGui::Begin("Model Control");
    ImGui::Text("Position: ");
    ImGui::InputFloat("x", &entities->at(0).pos.x, 0.0f, 0.0f, "%f");
    ImGui::InputFloat("y", &entities->at(0).pos.y, 0.0f, 0.0f, "%f");
    ImGui::InputFloat("z", &entities->at(0).pos.z, 0.0f, 0.0f, "%f");
    ImGui::Text("Rotation: ");
    ImGui::InputFloat("yaw", &entities->at(0).rotation.x, 0.0f, 0.0f, "%f");
    ImGui::InputFloat("pitch", &entities->at(0).rotation.y, 0.0f, 0.0f, "%f");
    ImGui::InputFloat("roll", &entities->at(0).rotation.z, 0.0f, 0.0f, "%f");
    ImGui::End();
    
}







void Engine::update()
{
        // update 
        updateCamera();
        glm::mat4 model = glm::mat4(1.0f);
        renderer.model = glm::rotate(model, glm::radians((float)glfwGetTime()*0), glm::vec3(1.0f, 1.0f, 0.0f)); 
        const float radius = 10.0f;
        float camX = sin(glfwGetTime()) * radius;
        float camZ = cos(glfwGetTime()) * radius;
        renderer.view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

}

void Engine::run()
{ 
    do{

        renderer.startNewImGuiFrame();
        frame++;

        // input
        processInput();

        //Update objects, camera and stuff;
        update();
        

        updateUI();
        renderer.render();

        // swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();

        //Deal with frame cap (if there is one)
        if(frameTimer.elapsedTime() < 1.0/ frameCap)
        {
            std::this_thread::sleep_for(std::chrono::duration<double>(1.0 /frameCap - frameTimer.elapsedTime()) );
        }

        //recalculate deltatime
        float currentTime = glfwGetTime();
        deltaTime = currentTime - lastFrame;
        lastFrame = currentTime;

        frameTime = deltaTime;
        frameTimeMean = frame > 1 ? (frameTimeMean*(frame - 1) + frameTime)/frame : frameTime;
        frameTimeMin = frameTime < frameTimeMin ? frameTime : frameTimeMin;
        frameTimeMax = frameTime > frameTimeMax ? frameTime : frameTimeMax;

        frameTimer.reset();
        totalTime = totalTimer.elapsedTime();

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );

    renderer.cleanup();
}



Engine::Engine() : entities(std::make_shared<std::vector<Entity>>())
{
    printf("Program started.\n");

    glewExperimental = true; // Needed for core profile
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );

    }

    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL

    // Open a window and create its OpenGL context
    // (In the accompanying source code, this variable is global for simplicity)
    window = glfwCreateWindow( width, height, "PhysicsEngine", NULL, NULL);
    if( window == NULL ){
        fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
        glfwTerminate();

    }
    glfwMakeContextCurrent(window); // Initialize GLEW
    glewExperimental=true; // Needed in core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");

    }
    glfwSwapInterval(0);

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    
    // Set callbacks:
    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glfwSetWindowUserPointer(window, this);

    std::cout << "Testing\n";

    renderer = Renderer(window, width, height, entities);



    std::cout << "Renderer constructed.\n";

    // ImGui
    renderer.initImGui();

    // This will identify our vertex buffer

    renderer.init();

    auto model1 = Entity();
    auto model2 = Entity();
    model1.mesh = std::make_shared<Mesh>("data/meshes/test.obj");
    model2.mesh = std::make_shared<Mesh>("data/meshes/platform.obj");
    model1.mesh->bufferMesh();
    model2.mesh->bufferMesh();
    model1.pos = glm::vec3(0.0f, 5.0f, 0.0f);
    model2.pos = glm::vec3(0.0f, -3.0f, 0.0f);
    entities->push_back(std::move(model1));
    entities->push_back(std::move(model2));


    //std::cout << "Entities size: " << entities.size() << "\n";

}


void Engine::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_M && action == GLFW_PRESS)
    {
        static_cast<Engine*>(glfwGetWindowUserPointer(window))->toggleMouse();
    }
}
void Engine::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    Engine* engine = static_cast<Engine*>(glfwGetWindowUserPointer(window));
    engine->width = width;
    engine->height = height;
    engine->renderer.viewportSizeChanged();
}

