cmake_minimum_required(VERSION 3.13)
project(PhysicsEngine)

include_directories(include external external/imgui external/implot external/stb)


file(GLOB SOURCES "src/*.cpp" "src/Renderer/*.cpp" "external/imgui/*.cpp" "external/implot/*.cpp" )

add_executable(PhysicsEngine ${SOURCES})

find_package(GLEW 2.0 REQUIRED)
target_link_libraries(PhysicsEngine GLEW::GLEW)
target_link_libraries(PhysicsEngine  -lglfw -lGL -lpthread -lrt)
