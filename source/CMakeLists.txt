cmake_minimum_required(VERSION 3.3)
project(Lattice)

add_subdirectory(glfw)
add_subdirectory(glm)



add_executable(LatticeApp main.cpp)
target_link_libraries(LatticeApp PRIVATE glfw)
