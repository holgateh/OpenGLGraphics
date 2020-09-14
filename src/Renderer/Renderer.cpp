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
    // This will identify our vertex buffer
    transformLoc = glGetUniformLocation(ourShader.ID, "transform");
    modelLoc = glGetUniformLocation(ourShader.ID, "model");
    viewLoc = glGetUniformLocation(ourShader.ID, "view");
    projectionLoc = glGetUniformLocation(ourShader.ID, "projection");  
    lightPosLoc = glGetUniformLocation(ourShader.ID, "lightPos");
    materialDiffuseColorLoc = glGetUniformLocation(ourShader.ID, "materialDiffuseColor");
    materialAmbientColorLoc = glGetUniformLocation(ourShader.ID, "materialAmbientColor");
    materialSpecularColorLoc = glGetUniformLocation(ourShader.ID, "materialSpecularColor");

    lightColorLoc = glGetUniformLocation(ourShader.ID, "lightColor");    
    lightPowerLoc = glGetUniformLocation(ourShader.ID, "lightPower");         
   

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

    ImGui::Begin("Material Control");
    ImGui::Text("Material Diffuse Color: ");
    ImGui::SliderFloat("r##1", &materialDiffuseColor.x, 0.0f, 1.0f, "%.1f");
    ImGui::SliderFloat("g##1", &materialDiffuseColor.y, 0.0f, 1.0f, "%.1f");
    ImGui::SliderFloat("b##1", &materialDiffuseColor.z, 0.0f, 1.0f, "%.1f");;
    ImGui::Separator();
    ImGui::Text("Material Ambient Color: ");
    ImGui::SliderFloat("r##2", &materialAmbientColor.x, 0.0f, 1.0f, "%.1f");
    ImGui::SliderFloat("g##2", &materialAmbientColor.y, 0.0f, 1.0f, "%.1f");
    ImGui::SliderFloat("b##2", &materialAmbientColor.z, 0.0f, 1.0f, "%.1f");
    ImGui::Separator();
    ImGui::Text("Material Specular Color: ");
    ImGui::SliderFloat("r##3", &materialSpecularColor.x, 0.0f, 1.0f, "%.1f");
    ImGui::SliderFloat("g##3", &materialSpecularColor.y, 0.0f, 1.0f, "%.1f");
    ImGui::SliderFloat("b##3", &materialSpecularColor.z, 0.0f, 1.0f, "%.1f");
    ImGui::End();

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


        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(proj));

        glUniform3fv(lightPosLoc, 1, glm::value_ptr(lightPos));
        glUniform3fv(lightColorLoc, 1, glm::value_ptr(lightColor));

        // Material stuff.
        glUniform3fv(materialDiffuseColorLoc, 1, glm::value_ptr(materialDiffuseColor));
        glUniform3fv(materialAmbientColorLoc, 1, glm::value_ptr(materialAmbientColor));
        glUniform3fv(materialSpecularColorLoc, 1, glm::value_ptr(materialSpecularColor));

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