#version 330 core
struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
}; 

struct Light {
    vec3 position;
    vec3 color;
    float power;
};
  
uniform Material material;
uniform Light light;

layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec3 aColor; // the color variable has attribute position 1
layout (location = 2) in vec3 aNorm; // the color variable has attribute position 1
layout (location = 3) in vec2 aTexCoord; // the uv coordinate has attribute position 2
  


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 lightPos;
uniform vec3 materialDiffuseColor;
uniform vec3 materialAmbientColor;
uniform vec3 materialSpecularColor;

uniform vec3 lightColor;
uniform float lightPower;


out vec3 ourColor; // output a color to the fragment shader
out vec2 TexCoord;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1);

    // Worldspace position of the vertex.
    vec3 positionWorldspace = (model * vec4(aPos,1)).xyz;

    vec3 positionCameraspace = (view * model * vec4(aPos,1)).xyz;
    vec3 eyeDirectionCameraspace = vec3(0,0,0) - positionCameraspace;

    vec3 lightPositionCameraspace = (view * vec4(lightPos, 1)).xyz;

    // Vector from the vertex to the light source (in cameraspace).
    vec3 lightDirCameraspace = lightPositionCameraspace + eyeDirectionCameraspace;

    // Normal vector of the vertex (in cameraspace).
    vec3 normalCameraspace = (view * model * vec4(aNorm, 0)).xyz;

    // Normalized normal of the vertex (in cameraspace).
    vec3 n = normalize(normalCameraspace);
    // Normalized vector from the vertex to the light source (in cameraspace).
    vec3 l = normalize(lightDirCameraspace);

    // Normalized eye direction (in cameraspace)
    vec3 E = normalize(eyeDirectionCameraspace);
    // Direction in which the vertex reflects the light
    vec3 R = reflect(-l,n);
    
    float cosAlpha = clamp( dot( E,R ), 0,1 );
    float cosTheta = clamp( dot( n,l ), 0,1 );
    float distance = length(lightDirCameraspace);


    vec3 color = materialAmbientColor
                 + (materialDiffuseColor *  lightColor * lightPower * cosTheta 
                 +  materialSpecularColor * lightColor * lightPower * pow(cosAlpha, 5))  / (distance * distance);

    ourColor = color;
    TexCoord = aTexCoord;
    
} 