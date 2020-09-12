#include "Renderer/Renderer.hpp"
Renderer::Renderer()
{}

Renderer::Renderer(GLFWwindow* window, float width, float height, std::vector<float>&& vertices) :
    ourShader(Shader("data/shaders/vert.sh", "data/shaders/frag.sh"))
{
    std::cout << "Renderer init\n";
    this->window = window;
    this->vertices = vertices;
    this->width = width;
    this->height = height;
}

void Renderer::init()
{
// This will identify our vertex buffer

    std::cout << "Renderer init\n";
    transformLoc = glGetUniformLocation(ourShader.ID, "transform");

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), (void*)vertices.data(), GL_STATIC_DRAW);

    std::cout << sizeof(float);

    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    //glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    

    Texture texture("data/textures/wall.jpg", 512, 512, 3);
    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

    proj = glm::perspective(glm::radians(45.0f), (float)width/(float)height, 0.1f, 100.0f);
    model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f)); 
    
    mvpLoc = glGetUniformLocation(ourShader.ID, "mvp");

    glEnable(GL_DEPTH_TEST);

}

void Renderer::startNewImGuiFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void Renderer::initImGui()
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

void Renderer::render()
{
    // render
    // clear the colorbuffer
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // feed inputs to dear imgui, start new frame


    // be sure to activate the shader
    float timeValue = glfwGetTime();

    //texture.bind();

    //now render the triangle

    ourShader.use();
    ourShader.setFloat("colour", sin(timeValue));
    glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, glm::value_ptr(proj * view * model));

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());


    // Render dear imgui into screen
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    // swap buffers and poll IO events
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Renderer::cleanup()
{
    ImPlot::DestroyContext();
    ImGui::DestroyContext();
}