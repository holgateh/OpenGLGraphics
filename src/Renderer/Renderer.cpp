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
}

void Renderer::viewportSizeChanged()
{
    glfwGetFramebufferSize(window, &width, &height);
    proj = glm::perspective(glm::radians(45.0f), (float)width/(float)height, 0.1f, 100.0f);
}

void Renderer::init()
{
    Texture texture("data/textures/wall.jpg");
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
    // ui stuff
    ImGui::Begin("Light Control");
    ImGui::Text("Light Position: ");
    ImGui::InputFloat("x", &lightPos.x, 0.0f, 0.0f, "%f");
    ImGui::InputFloat("y", &lightPos.y, 0.0f, 0.0f, "%f");
    ImGui::InputFloat("z", &lightPos.z, 0.0f, 0.0f, "%f");
    ImGui::Separator();
    ImGui::Text("Light Color: ");
    ImGui::SliderFloat("r", &lightColor.x, 0.0f, 1.0f, "%.1f");
    ImGui::SliderFloat("g", &lightColor.y, 0.0f, 1.0f, "%.1f");
    ImGui::SliderFloat("b", &lightColor.z, 0.0f, 1.0f, "%.1f");
    ImGui::Separator();
    ImGui::InputFloat("Power ", &lightPower, 0.0f, 0.0f, "%f");
    ImGui::Separator();
    ImGui::End();

    for(auto& entity : *(entities.get()))
    {
        ImGui::Begin(("Material Control: " + entity.ID).c_str());
        ImGui::Text("Material Diffuse Color: ");
        ImGui::SliderFloat("r##1", &entity.material.diffuse.x, 0.0f, 1.0f, "%.1f");
        ImGui::SliderFloat("g##1", &entity.material.diffuse.y, 0.0f, 1.0f, "%.1f");
        ImGui::SliderFloat("b##1", &entity.material.diffuse.z, 0.0f, 1.0f, "%.1f");;
        ImGui::Separator();
        ImGui::Text("Material Ambient Color: ");
        ImGui::SliderFloat("r##2", &entity.material.ambient.x, 0.0f, 1.0f, "%.1f");
        ImGui::SliderFloat("g##2", &entity.material.ambient.y, 0.0f, 1.0f, "%.1f");
        ImGui::SliderFloat("b##2", &entity.material.ambient.z, 0.0f, 1.0f, "%.1f");
        ImGui::Separator();
        ImGui::Text("Material Specular Color: ");
        ImGui::SliderFloat("r##3", &entity.material.specular.x, 0.0f, 1.0f, "%.1f");
        ImGui::SliderFloat("g##3", &entity.material.specular.y, 0.0f, 1.0f, "%.1f");
        ImGui::SliderFloat("b##3", &entity.material.specular.z, 0.0f, 1.0f, "%.1f");
        ImGui::End();
    }

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
    //Render each entity in the scence.
    for(auto& entity : *(entities.get()))
    {
        //Calculate new 
        model = glm::mat4(1.0f);
        model = glm::translate(model, entity.pos);
        glm::quat rotation = glm::angleAxis(entity.rotation.x, glm::vec3(0.0, 1.0f, 0.0f)) *
                             glm::angleAxis(entity.rotation.y, glm::vec3(1.0, 0.0f, 0.0f)) *
                             glm::angleAxis(entity.rotation.z, glm::vec3(0.0, 0.0f, 1.0f));
            
        model = model * glm::toMat4(rotation);
        model = glm::scale(model, entity.scale);

        ourShader.setMat4("model", model);
        ourShader.setMat4("view", view);
        ourShader.setMat4("projection", proj);
        ourShader.setVec3("lightPos", lightPos);
        ourShader.setVec3("lightColor", lightColor);

        // Material stuff.
        ourShader.setVec3("materialDiffuseColor", entity.material.diffuse);
        ourShader.setVec3("materialAmbientColor", entity.material.ambient);
        ourShader.setVec3("materialSpecularColor", entity.material.specular);
        ourShader.setFloat("lightPower", lightPower);

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