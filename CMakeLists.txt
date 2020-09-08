cmake_minimum_required(VERSION 3.13)
project(PhysicsEngine)

include_directories(include)
 
file(GLOB SOURCES "src/*.cpp")
 
add_executable(PhysicsEngine ${SOURCES})