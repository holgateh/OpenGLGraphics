#include "Engine.hpp"


// An array of 3 vectors which represents 3 vertices
float vertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

unsigned int indices[] = {  
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

void Engine::toggleMouse()
{
    if(mouseEnabled)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        mouseEnabled = false;
        glfwGetCursorPos(window, &lastMouseX, &lastMouseY);
    }
    else
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        mouseEnabled = true;
    }
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
            angleYaw += deltaYaw;

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

            glm::quat rotatePitch = glm::angleAxis(deltaPitch, cameraRight);
            cameraFront =  rotatePitch * cameraFront;
        }    

    }
    
   
}

void Engine::renderUI()
{
    // render your GUI
    ImGui::Begin("Performance Statistics");
    ImGui::Text(("Frame: " + std::to_string(frame)).c_str());
    ImGui::Text(("Frame time: " + std::to_string(frameTime* 1000.0) + "ms" ).c_str());
    frameTimeMean = frame > 1 ? (frameTimeMean*(frame - 1) + frameTime)/frame : frameTime;
    ImGui::Text(("Mean frame time: " + std::to_string(frameTimeMean * 1000.0) + "ms" ).c_str());
    frameTimeMin = frameTime < frameTimeMin ? frameTime : frameTimeMin;
    frameTimeMax = frameTime > frameTimeMax ? frameTime : frameTimeMax;
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

    // Render dear imgui into screen
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    
}

void Engine::initUI()
{
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImPlot::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(NULL);
    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
}

void Engine::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_M && action == GLFW_PRESS)
    {
        static_cast<Engine*>(glfwGetWindowUserPointer(window))->toggleMouse();
    }
}






void Engine::run()
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
    glfwSetKeyCallback(window, key_callback);
    glfwSetWindowUserPointer(window, this);

    // ImGui
    initUI();


    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);



    // This will identify our vertex buffer

    Shader ourShader((SHADER_PATH + "vert.sh").c_str(), (SHADER_PATH + "frag.sh").c_str());
  
    unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");


    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    //glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    
    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

    Texture texture("data/textures/wall.jpg", 512, 512, 3);
    float angle = 0.0f;

    glm::mat4 proj = glm::perspective(glm::radians(45.0f), (float)width/(float)height, 0.1f, 100.0f);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f)); 
    
    int mvpLoc = glGetUniformLocation(ourShader.ID, "mvp");

    glEnable(GL_DEPTH_TEST);


 
    glm::mat4 view;

    do{
        frame++;

        // input
        processInput();

        // update 
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::rotate(model, glm::radians((float)glfwGetTime()*0), glm::vec3(1.0f, 1.0f, 0.0f)); 
        const float radius = 10.0f;
        float camX = sin(glfwGetTime()) * radius;
        float camZ = cos(glfwGetTime()) * radius;
       
        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        
        // render
        // clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // feed inputs to dear imgui, start new frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();


        // be sure to activate the shader
        float timeValue = glfwGetTime();


        //texture.bind();

        // now render the triangle

        ourShader.use();
        ourShader.setFloat("colour", sin(timeValue));
        glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, glm::value_ptr(proj * view * model));

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices)/sizeof(float));

        renderUI();
    
        // swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
        if(frameTimer.elapsedTime() < 1.0/ frameCap)
        {
            std::this_thread::sleep_for(std::chrono::duration<double>(1.0 /frameCap - frameTimer.elapsedTime()) );
        }
        float currentTime = glfwGetTime();
        deltaTime = currentTime - lastFrame;
        lastFrame = currentTime;

        frameTime = deltaTime;
        frameTimer.reset();
        totalTime = totalTimer.elapsedTime();

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );

    ImPlot::DestroyContext();
    ImGui::DestroyContext();
}




Engine::Engine()
{

}
