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
    const float cameraSpeed = 2.5f * deltaTime;
    const float cameraRotateSpeed = 2.0f * deltaTime; // adjust accordingly
    if(!mouseEnabled)
    {
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
            camera.get()->pos += cameraSpeed * camera.get()->front;
        }

        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
            camera.get()->pos -= cameraSpeed * camera.get()->front;
        }

        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            camera.get()->pos -= glm::normalize(glm::cross(camera.get()->front, camera.get()->up)) * cameraSpeed;
        }

        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            camera.get()->pos += glm::normalize(glm::cross(camera.get()->front, camera.get()->up)) * cameraSpeed;
        }

        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
        {
            camera.get()->pos += glm::normalize(camera.get()->up) * cameraSpeed;
        }

        if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
        {
            camera.get()->pos -= glm::normalize(camera.get()->up) * cameraSpeed;
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
            camera.get()->yaw -= deltaYaw;
        }
        if (deltaY != 0.0)
        {
            float deltaPitch = deltaY * cameraRotateSpeed;
            camera.get()->pitch += deltaPitch;
            float boundry = 0.1;
            if(camera.get()->pitch > glm::pi<double>()/2.0 - boundry)
            {
                deltaPitch = deltaPitch - (camera.get()->pitch - glm::pi<double>()/2.0 + boundry);
                camera.get()->pitch = glm::pi<double>()/2.0 - boundry;
            }
            else if (camera.get()->pitch < -glm::pi<double>()/2.0 + boundry)
            {
                deltaPitch = deltaPitch + (-glm::pi<double>()/2.0 + boundry - camera.get()->pitch);
                camera.get()->pitch = -glm::pi<double>()/2.0 + boundry;
            }
        }    

    }
    
   
}

void Engine::updateUI()
{
    // render your GUI
    ImGui::Begin("Performance Statistics");
    ImGui::Text(("Vertices: " + std::to_string(renderer.getNumVertices())).c_str());
    ImGui::Text(("Triangles: " + std::to_string(renderer.getNumTriangles())).c_str());
    ImGui::Text(("Frame: " + std::to_string(frame)).c_str());
    ImGui::Text(("Total time: " + std::to_string(totalTime) + "s" ).c_str());
    ImGui::Text(("FPS: " + std::to_string(framesPerSecond)).c_str());
    ImGui::Text(("Frame time: " + std::to_string(frameTime* 1000.0) + "ms" ).c_str());
    ImGui::Text(("Mean frame time: " + std::to_string(frameTimeMean * 1000.0) + "ms" ).c_str());
    ImGui::Text(("Min frame time: " + std::to_string(frameTimeMin * 1000.0) + "ms" ).c_str());
    ImGui::Text(("Max frame time: " + std::to_string(frameTimeMax * 1000.0) + "ms" ).c_str());
    static ScrollingBuffer sdata1;
    sdata1.AddPoint(totalTime, frameTime*1000.0);

    static float history = 1.0f;
    ImGui::SliderFloat("History",&history,0.1,5,"%.1f s");
    ImPlot::SetNextPlotLimitsX(glfwGetTime() - history, totalTime, ImGuiCond_Always);
    ImPlot::SetNextPlotLimitsY(0, frameTimeMean * 3 * 1000, ImGuiCond_Always);
    if (ImPlot::BeginPlot("##Scrolling", NULL, NULL, ImVec2(200,75), 0, ImPlotAxisFlags_NoTickLabels, ImPlotAxisFlags_NoTickLabels | ImPlotAxisFlags_LockMin)) {
        ImPlot::PlotLine("", &sdata1.Data[0], sdata1.Data.size(), sdata1.Offset);
        ImPlot::EndPlot();
    }
    
    ImGui::End();

    ImGui::Begin("Camera Control");
    ImGui::Text("Position: ");
    ImGui::InputFloat("x", &camera.get()->pos.x, 0.0f, 0.0f, "%f");
    ImGui::InputFloat("y", &camera.get()->pos.y, 0.0f, 0.0f, "%f");
    ImGui::InputFloat("z", &camera.get()->pos.z, 0.0f, 0.0f, "%f");
    ImGui::Text("Rotation: ");
    ImGui::SliderFloat("pitch: ",&camera.get()->pitch, -glm::pi<float>()/2, glm::pi<float>()/2,"%.1f");
    ImGui::SliderFloat("yaw: ",&camera.get()->yaw ,0.0f ,2*glm::pi<float>(), "%.1f");
    ImGui::End();




    for(auto& entity : *(entities.get()))
    {
        ImGui::Begin(("Material Control: " + entity.ID).c_str());
        ImGui::InputFloat("shininess", &entity.material.shininess, 0.0f, 100.0f, "%f");
        ImGui::End();

        ImGui::Begin(("Model Control: " + entity.ID).c_str());
        ImGui::Text("Position: ");
        ImGui::InputFloat("x", &entity.pos.x, 0.0f, 0.0f, "%f");
        ImGui::InputFloat("y", &entity.pos.y, 0.0f, 0.0f, "%f");
        ImGui::InputFloat("z", &entity.pos.z, 0.0f, 0.0f, "%f");
        ImGui::Text("Rotation: ");
        ImGui::InputFloat("yaw", &entity.rotation.x, 0.0f, 0.0f, "%f");
        ImGui::InputFloat("pitch", &entity.rotation.y, 0.0f, 0.0f, "%f");
        ImGui::InputFloat("roll", &entity.rotation.z, 0.0f, 0.0f, "%f");
        ImGui::End();
    }


    for(auto& light: *(lights.get()))
    {
        // light control
        ImGui::Begin(("Light Control: " + light.ID).c_str());
        ImGui::Text("Light Position: ");
        ImGui::InputFloat("x", &light.pos.x, 0.0f, 0.0f, "%f");
        ImGui::InputFloat("y", &light.pos.y, 0.0f, 0.0f, "%f");
        ImGui::InputFloat("z", &light.pos.z, 0.0f, 0.0f, "%f");
        ImGui::Separator();
        ImGui::Text("Light Ambient Color: ");
        ImGui::SliderFloat("r##2", &light.ambient.x, 0.0f, 1.0f, "%.1f");
        ImGui::SliderFloat("g##2", &light.ambient.y, 0.0f, 1.0f, "%.1f");
        ImGui::SliderFloat("b##2", &light.ambient.z, 0.0f, 1.0f, "%.1f");
        ImGui::Text("Light Diffuse Color: ");
        ImGui::SliderFloat("r##3", &light.diffuse.x, 0.0f, 1.0f, "%.1f");
        ImGui::SliderFloat("g##3", &light.diffuse.y, 0.0f, 1.0f, "%.1f");
        ImGui::SliderFloat("b##3", &light.diffuse.z, 0.0f, 1.0f, "%.1f");
        ImGui::Separator();
        ImGui::Text("Light Specular Color: ");
        ImGui::SliderFloat("r##4", &light.specular.x, 0.0f, 1.0f, "%.1f");
        ImGui::SliderFloat("g##4", &light.specular.y, 0.0f, 1.0f, "%.1f");
        ImGui::SliderFloat("b##4", &light.specular.z, 0.0f, 1.0f, "%.1f");
        ImGui::Separator();
        ImGui::InputFloat("Power ", &light.power, 0.0f, 0.0f, "%f");
        ImGui::Separator();
        ImGui::End();
    }


        ImGui::Begin("Renderer Control");
        ImGui::Text(("Current mode: " + renderer.modes[renderer.currentMode].name).c_str());
        ImGui::Separator();
        ImGui::ListBoxHeader("Modes:");
        for (int i = 0; i < renderer.modes.size(); i++)
        {
            std::string& itemName = renderer.modes[i].name;
            if (ImGui::Selectable(itemName.c_str(), renderer.modes[i].isSelected))
            {
                if(renderer.currentMode != i)
                {
                    renderer.currentMode = i;
                    std::cout << i << "\n";
                }
            }
        }
        ImGui::ListBoxFooter();
        ImGui::Separator();
        ImGui::End();
    
}







void Engine::update()
{
    // update 
    camera.get()->update();
    renderer.view = glm::lookAt(camera.get()->pos, camera.get()->pos + camera.get()->front, camera.get()->up);

    for(auto& entity : *(entities.get()))
    {
        entity.update();
    }

    for(auto& light : *(lights.get()))
    {
        if(light.ID == "light")
        {        
            light.pos = glm::vec3(10*sin(totalTime), 10, 10*cos(totalTime));
            light.update();
        }

        if(light.ID == "light2")
        {        
            light.pos = glm::vec3(-10*sin(totalTime), 10, -10*cos(totalTime));
            light.update();
        }
    }

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



        //recalculate deltatime
        float currentTime = glfwGetTime();
        deltaTime = currentTime - lastFrame;



        //Deal with frame cap (if there is one)
        if(deltaTime < targetFrametime)
        {
            std::this_thread::sleep_for(std::chrono::duration<double>(targetFrametime - deltaTime) );
        }

        currentTime = glfwGetTime();
        deltaTime = currentTime - lastFrame;
        lastFrame = currentTime;


        frameTime = deltaTime;
        frameTimeMean = frame > 1 ? (frameTimeMean*(frame - 1) + frameTime)/frame : frameTime;
        frameTimeMin = frameTime < frameTimeMin ? frameTime : frameTimeMin;
        frameTimeMax = frameTime > frameTimeMax ? frameTime : frameTimeMax;
        
        // Increment the sample time by delta time.
        sampleTime += deltaTime;

        //FPS calculation:
        if(frame % sampleCount == 0)
        {
            framesPerSecond = 1.0 / (sampleTime / sampleCount);
            sampleTime = 0;
            
        }

        totalTime = currentTime - startTime;


    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );

    renderer.cleanup();
}



Engine::Engine() : entities(std::make_shared<std::vector<Entity>>()),
                   lights(std::make_shared<std::vector<Light>>()),
                   camera(std::make_shared<Camera>())
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

    renderer = Renderer(window, width, height, entities, lights, camera);



    std::cout << "Renderer constructed.\n";

    // ImGui
    renderer.initImGui();

    // This will identify our vertex buffer

    renderer.init();

    auto model1 = Entity("model1");
    auto model2 = Entity("model2");
    auto model3 = Entity("model3");
    
    auto shaderModel = std::make_shared<Shader>("data/shaders/vert.sh", "data/shaders/frag.sh");

    // Load textures:
    auto texture1 = std::make_shared<Texture>("data/textures/default-diffuse.png");
    auto texture2 = std::make_shared<Texture>("data/textures/diffuse.png");
    auto textureSpecular1 = std::make_shared<Texture>("data/textures/specular.png");
    auto textureSpecular2 = std::make_shared<Texture>("data/texture/default-specular.png");
    // Load meshes:
    model1.mesh = std::make_shared<Mesh>("data/meshes/cube-smooth.obj");
    model2.mesh = std::make_shared<Mesh>("data/meshes/platform.obj");
    model3.mesh = std::make_shared<Mesh>("data/meshes/torus.obj");
    
    // Buffer meshes:
    model1.mesh->bufferMesh();
    model2.mesh->bufferMesh();
    model3.mesh->bufferMesh();
    
    // Set Initial Positions:
    model1.pos = glm::vec3(0.0f, 5.0f, 0.0f);
    model2.pos = glm::vec3(0.0f, -3.0f, 0.0f);
    model3 .pos = glm::vec3(-5.0f, 5.0f, 0.0f);
    
    // Set Shader:
    model1.shader = shaderModel;
    model2.shader = shaderModel;
    model3.shader = shaderModel;
    
    // Set Speculars:
    model1.specular = textureSpecular1;
    model2.specular = textureSpecular2;
    model3.specular = textureSpecular2;
    
    // Set diffuse:
    model1.diffuse = texture2;
    model2.diffuse = texture1;
    model3.diffuse = texture1;


    // setup light
    auto light = Light("light");
    auto shaderLight = std::make_shared<Shader>("data/shaders/vert-light.sh", "data/shaders/frag-light.sh");
    light.mesh = std::make_shared<Mesh>("data/meshes/sphere.obj");
    light.mesh->bufferMesh();
    light.pos = glm::vec3(10.0f, 10.0f, 10.0f);
    light.shader = shaderLight;

    auto light2 = Light("light2", LightType::DIRECTIONAL);
    light2.mesh = light.mesh;
    light2.pos = glm::vec3(10.0f, 15.0f, 10.0f);
    light2.shader = shaderLight;

    //Set camera position.
    camera.get()->pos = glm::vec3(0.0f, 10.0f, 0.0f);

    


    lights->push_back(std::move(light));
    lights->push_back(std::move(light2));

    entities->push_back(std::move(model1));
    entities->push_back(std::move(model2));
    entities->push_back(std::move(model3));



    startTime = glfwGetTime();


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

