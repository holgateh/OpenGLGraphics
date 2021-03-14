cmake_minimum_required(VERSION 3.13)
project(GameEngine)


include_directories(lib include external external/imgui external/implot external/stb)


file(GLOB SOURCES "src/*.cpp" "src/AudioEngine/*.cpp" "src/InputEngine/*.cpp" "src/PhysicsEngine/*.cpp"  "src/RenderingEngine/*.cpp" "external/imgui/*.cpp" "external/implot/*.cpp" )

add_executable(GameEngine ${SOURCES})
IF(WIN32)
    target_link_libraries(GameEngine  ${CMAKE_CURRENT_SOURCE_DIR}/lib/win/glew32.lib ${CMAKE_CURRENT_SOURCE_DIR}/lib/win/glfw3dll.lib -lpthread -lOpenGL32)
ELSE()
    find_package(GLEW 2.0)
    target_link_libraries(GameEngine GLEW::GLEW)
    target_link_libraries(GameEngine -lglfw -lGL -lpthread -lrt)
ENDIF()
