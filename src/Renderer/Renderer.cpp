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
        light.shader.get()->setVec3("light.ambient", light.ambient);
        light.shader.get()->setVec3("light.diffuse", light.diffuse);
        light.shader.get()->setVec3("light.specular", light.specular);

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
        
        // Lights
        int lightCount = lights.get()->size();
        entity.shader.get()->setInt("lightCount", lightCount);
        for (int i = 0; i < lightCount; i++)
        {
            entity.shader.get()->setVec3("lights[" + std::to_string(i) + "].pos", lights.get()->at(i).pos);
            entity.shader.get()->setFloat("lights[" + std::to_string(i) + "].power", lights.get()->at(i).power);
            entity.shader.get()->setVec3("lights[" + std::to_string(i) + "].diffuse", lights.get()->at(i).diffuse);
            entity.shader.get()->setVec3("lights[" + std::to_string(i) + "].ambient", lights.get()->at(i).ambient);
            entity.shader.get()->setVec3("lights[" + std::to_string(i) + "].specular", lights.get()->at(i).specular);
        }


        
        // Material stuff.
        entity.shader.get()->setFloat("material.shininess", entity.material.shininess);
        entity.shader.get()->setVec3("viewPos", camera.get()->pos);


        entity.diffuse.get()->activate();
        entity.diffuse.get()->bind();

        entity.specular.get()->activate();
        entity.specular.get()->bind();

        entity.shader.get()->setInt("material.diffuse", entity.diffuse.get()->ID);
        entity.shader.get()->setInt("material.specular", entity.specular.get()->ID);
        //entity.specular.get()->activate();


        glBindVertexArray(entity.mesh->VAO);
        //glDrawArrays(GL_TRIANGLES, 0, mesh.indices.size());
        
        if (modes[currentMode].name == "NORMAL")
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
        else if (modes[currentMode].name == "WIREFRAME")
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        }
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

    for(auto& light : *(lights.get()))
    {
        sum += light.mesh->vertices.size();
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

    for(auto& light : *(lights.get()))
    {
        sum += light.mesh->vertices.size();
    }

    return sum / 3;
}

void Renderer::cleanup()
{
    ImPlot::DestroyContext();
    ImGui::DestroyContext();
}