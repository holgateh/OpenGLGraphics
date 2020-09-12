#include "Renderer/Renderer.hpp"
Renderer::Renderer()
{}

Renderer::Renderer(GLFWwindow* window, float width, float height) :
    ourShader(Shader("data/shaders/vert.sh", "data/shaders/frag.sh"))
{
    this->window = window;
    this->width = width;
    this->height = height;
    mesh = Mesh("data/meshes/test.obj");
    light = glm::normalize(light);
}

void Renderer::init()
{
    // This will identify our vertex buffer
    transformLoc = glGetUniformLocation(ourShader.ID, "transform");
    mvpLoc = glGetUniformLocation(ourShader.ID, "mvp");
    lightLoc = glGetUniformLocation(ourShader.ID, "lightDir");

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)* mesh.vertices.size(), (void*)mesh.vertices.data(), GL_STATIC_DRAW);

    std::cout << "vertex size" << sizeof(Vertex) << "\n";

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * mesh.indices.size(), mesh.indices.data(), GL_STATIC_DRAW);


    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // norm attribute
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    // texture attribute
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(9 * sizeof(float)));
    glEnableVertexAttribArray(3);
    

    Texture texture("data/textures/wall.jpg");
    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

    proj = glm::perspective(glm::radians(45.0f), (float)width/(float)height, 0.1f, 100.0f);
    model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f)); 

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

    ImGui::Begin("Light Control");
    ImGui::Text("Light: ");
    ImGui::SliderFloat("x: ",&light.x,-1,1,"%.1f");
    ImGui::SliderFloat("y: ",&light.y,-1,1,"%.1f");
    ImGui::SliderFloat("z: ",&light.z,-1,1,"%.1f");
    ImGui::End();
    light = glm::normalize(light);

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
    glUniform3fv(lightLoc, 1, glm::value_ptr(light));
    glBindVertexArray(VAO);
    //glDrawArrays(GL_TRIANGLES, 0, mesh.indices.size());

    glDrawElements(GL_TRIANGLES, mesh.indices.size(), GL_UNSIGNED_INT, 0);


    // Render dear imgui into screen
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    // swap buffers and poll IO events
    glfwSwapBuffers(window);
    glfwPollEvents();
}

uint32_t Renderer::getNumVertices()
{
    return mesh.vertices.size();
}

uint32_t Renderer::getNumTriangles()
{
    return mesh.indices.size() / 3;
}

void Renderer::cleanup()
{
    ImPlot::DestroyContext();
    ImGui::DestroyContext();
}