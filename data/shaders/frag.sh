#version 330 core
struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
}; 

struct Light {
    vec3 pos;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float power;
};

out vec4 FragColor;  
in vec4 ourColor; // output a color to the fragment shader
in vec2 TexCoords;
in vec3 FragPos;
in vec3 Normal;

uniform float colour; // we set this variable in the OpenGL code.
uniform Material material;
uniform Light lights[10];
uniform int lightCount;
uniform vec3 viewPos;

void main()
{
    for (int i = 0; i < lightCount; i++)
    {
        // ambient
        vec3 ambient = lights[i].ambient * vec3(texture(material.diffuse, TexCoords));
        
        // diffuse 
        vec3 norm = normalize(Normal);
        vec3 lightDir = lights[i].pos - FragPos;
        vec3 nlightDir = normalize(lightDir); 
        float diff = max(dot(norm, nlightDir), 0.0);
        vec3 diffuse = lights[i].diffuse * diff * vec3(texture(material.diffuse, TexCoords));  
        
        // specular
        vec3 viewDir = normalize(viewPos - FragPos);
        vec3 reflectDir = reflect(-nlightDir, norm);  
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
        vec3 specular = lights[i].specular * (spec * vec3(texture(material.specular, TexCoords)));  

        //distance between
        float d = length(lightDir);
            
        vec3 result = ambient + lights[i].power * (diffuse + specular) / (d * d);
        FragColor = FragColor + vec4(result, 0.0);
    }
    FragColor = FragColor + vec4(0.0, 0.0, 0.0, 1.0);
}