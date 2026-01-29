cmake_minimum_required(VERSION 3.5)

project(Lattice VERSION 0.1.0 LANGUAGES CXX) 

find_package(Vulkan REQUIRED)

# add_subdirectory("glfw")

add_executable(LatticeApp main.cpp)
# target_link_libraries(LatticeApp PRIVATE glfw)
