#include "Renderer/Renderer.hpp"
Renderer::Renderer()
{}

Renderer::Renderer(GLFWwindow* window, float width, float height, std::shared_ptr<std::vector<Entity>>  entities,
                   std::shared_ptr<std::vector<Light>> lights, std::shared_ptr<Camera> camera)
{
    this->window = window;
    this->width = width;
    this->height = height;
    this->entities = entities;
    this->lights = lights;
    this->camera = camera;
}

void Renderer::viewportSizeChanged()
{
    glfwGetFramebufferSize(window, &width, &height);
    proj = glm::perspective(glm::radians(45.0f), (float)width/(float)height, 0.1f, 100.0f);
}

void Renderer::init()
{
    //Texture texture("data/textures/wall.jpg");
    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

    proj = glm::perspective(glm::radians(45.0f), (float)width/(float)height, 0.1f, 100.0f);


    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    
    glCullFace(GL_BACK);

    // Enable blending
    glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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
    // clear the colorbuffer
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // feed inputs to dear imgui, start new frame

    //std::cout << "entites size " << entities.get()->size() << "\n";

    //texture.bind();
    float timeValue = glfwGetTime();
    //now render the triangle

    //Use our default shader.

    for(auto& light : *(lights.get()))
    {
        light.shader.get()->use();
        light.shader.get()->setMat4("model", light.model);
        light.shader.get()->setMat4("view", view);
        light.shader.get()->setMat4("projection", proj);
        light.shader.get()->setVec3("light.color", lights.get()->at(0).color);
        light.shader.get()->setVec3("light.ambient", lights.get()->at(0).material.ambient);
        light.shader.get()->setVec3("light.diffuse", lights.get()->at(0).material.diffuse);
        light.shader.get()->setVec3("light.specular", lights.get()->at(0).material.specular);

        glBindVertexArray(light.mesh->VAO);
        //glDrawArrays(GL_TRIANGLES, 0, mesh.indices.size());

        glDrawElements(GL_TRIANGLES, light.mesh->indices.size(), GL_UNSIGNED_INT, 0);
    }
    
    //Render each entity in the scence.
    for(auto& entity : *(entities.get()))
    {
        entity.shader.get()->use();
        entity.shader.get()->setMat4("model", entity.model);
        entity.shader.get()->setMat4("view", view);
        entity.shader.get()->setMat4("projection", proj);

        entity.shader.get()->setVec3("light.pos", lights.get()->at(0).pos);
        entity.shader.get()->setVec3("light.color", lights.get()->at(0).color);
        entity.shader.get()->setFloat("light.power", lights.get()->at(0).power);
        entity.shader.get()->setVec3("light.diffuse", lights.get()->at(0).material.diffuse);
        entity.shader.get()->setVec3("light.ambient", lights.get()->at(0).material.ambient);
        entity.shader.get()->setVec3("light.specular", lights.get()->at(0).material.specular);
        



        // Material stuff.
        //entity.shader.get()->setVec3("material.diffuse", entity.material.diffuse);
        //entity.shader.get()->setVec3("material.ambient", entity.material.ambient);
        entity.shader.get()->setVec3("material.specular", entity.material.specular);
        entity.shader.get()->setFloat("material.shininess", entity.material.shininess);
        entity.shader.get()->setVec3("viewPos", camera.get()->pos);

        
        entity.shader.get()->setInt("material.diffuse", entity.texture.get()->ID);
        entity.texture.get()->activate();

        glBindVertexArray(entity.mesh->VAO);
        //glDrawArrays(GL_TRIANGLES, 0, mesh.indices.size());

        glDrawElements(GL_TRIANGLES, entity.mesh->indices.size(), GL_UNSIGNED_INT, 0);
    }

    // Render dear imgui into screen
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
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