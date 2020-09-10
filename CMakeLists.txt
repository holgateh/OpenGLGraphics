cmake_minimum_required(VERSION 3.13)
project(PhysicsEngine)

include_directories(include include/imgui include/implot include/stb )


file(GLOB SOURCES "src/*.cpp" "src/tools/*.cpp" "src/imgui/*.cpp" "src/implot/*.cpp")

add_executable(PhysicsEngine ${SOURCES})

find_package(GLEW 2.0 REQUIRED)
target_link_libraries(PhysicsEngine GLEW::GLEW)
target_link_libraries(PhysicsEngine  -lglfw -lGL -lX11 -lpthread -lrt)
