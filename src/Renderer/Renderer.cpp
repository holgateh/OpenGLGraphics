#include "Renderer/Renderer.hpp"
Renderer::Renderer()
{}

Renderer::Renderer(GLFWwindow* window, float width, float height, std::shared_ptr<std::vector<Entity>>  entities) :
    ourShader(Shader("data/shaders/vert.sh", "data/shaders/frag.sh"))
{
    this->window = window;
    this->width = width;
    this->height = height;
    this->entities = entities;
    light = glm::normalize(light);
}

void Renderer::init()
{
    // This will identify our vertex buffer
    transformLoc = glGetUniformLocation(ourShader.ID, "transform");
    mvpLoc = glGetUniformLocation(ourShader.ID, "mvp");
    lightLoc = glGetUniformLocation(ourShader.ID, "lightDir");    

    Texture texture("data/textures/wall.jpg");
    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

    proj = glm::perspective(glm::radians(45.0f), (float)width/(float)height, 0.1f, 100.0f);


    glEnable(GL_DEPTH_TEST);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

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

    //std::cout << "entites size " << entities.get()->size() << "\n";

    //texture.bind();
    float timeValue = glfwGetTime();
    //now render the triangle

    //Use our default shader.
    ourShader.use();
    ourShader.setFloat("colour", sin(timeValue));

    //Render each entity in the scence.
    for(auto& entity : *(entities.get()))
    {
        model = glm::mat4(1.0f);
        model = glm::translate(model, entity.pos);
        glm::quat rotation = glm::angleAxis(entity.rotation.x, glm::vec3(0.0, 1.0f, 0.0f)) *
                             glm::angleAxis(entity.rotation.y, glm::vec3(1.0, 0.0f, 0.0f)) *
                             glm::angleAxis(entity.rotation.z, glm::vec3(0.0, 0.0f, 1.0f));
            
        model = model * glm::toMat4(rotation);
        model = glm::scale(model, entity.scale);


        glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, glm::value_ptr(proj * view * model));
        glUniform3fv(lightLoc, 1, glm::value_ptr(light));

        glBindVertexArray(entity.mesh->VAO);
        //glDrawArrays(GL_TRIANGLES, 0, mesh.indices.size());

        glDrawElements(GL_TRIANGLES, entity.mesh->indices.size(), GL_UNSIGNED_INT, 0);
    }

    // Render dear imgui into screen
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    // swap buffers and poll IO events
    glfwSwapBuffers(window);
    glfwPollEvents();
}

uint32_t Renderer::getNumVertices()
{
    unsigned int sum = 0;
    for (auto& entity : *(entities.get()))
    {
        sum += entity.mesh->vertices.size();
    }

    return sum;
}

uint32_t Renderer::getNumTriangles()
{
    unsigned int sum = 0;
    for (auto& entity : *(entities.get()))
    {
        sum += entity.mesh->indices.size();
    }
    return sum / 3;
}

void Renderer::cleanup()
{
    ImPlot::DestroyContext();
    ImGui::DestroyContext();
}