cmake_minimum_required(VERSION 3.13)
project(GameEngine)

include_directories(include external external/imgui external/implot external/stb)


file(GLOB SOURCES "src/*.cpp" "src/AudioEngine/*.cpp" "src/InputEngine/*.cpp" "src/PhysicsEngine/*.cpp"  "src/RenderingEngine/*.cpp" "external/imgui/*.cpp" "external/implot/*.cpp" )

add_executable(GameEngine ${SOURCES})

find_package(GLEW 2.0 REQUIRED)
target_link_libraries(GameEngine GLEW::GLEW)
target_link_libraries(GameEngine -lglfw -lGL -lpthread -lrt)
