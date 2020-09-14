#pragma once
// Include GLEW. Always include it before gl.h and glfw3.h, since it's a bit magic.
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
#include <GL/gl.h>
  
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

// Include GLM
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>
  

class Shader
{
public:
    // the program ID
    unsigned int ID;
  
    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);
    Shader();
    // use/activate the shader
    void use();
    // utility uniform functions
    void setBool(const std::string &name, bool value) const;  
    void setInt(const std::string &name, int value) const;   
    void setFloat(const std::string &name, float value) const;
    void setVec2(const std::string &name, glm::vec2& value) const;
    void setVec3(const std::string &name, glm::vec3& value) const;
    void setVec4(const std::string &name, glm::vec4& value) const;
    void setMat4(const std::string &name, glm::mat4& value) const;
    
};