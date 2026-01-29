cmake_minimum_required(VERSION 3.5)

project(Lattice VERSION 0.1.0 LANGUAGES CXX) 

find_package(Vulkan REQUIRED)

# Disable building GLFW examples, tests, and docs
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
# Add the GLFW source directory
add_subdirectory(libs/glfw)

add_executable(LatticeApp main.cpp)
target_link_libraries(LatticeApp PUBLIC Vulkan::Vulkan)
# Link your executable against the glfw target and OpenGL library
target_link_libraries(LatticeApp PRIVATE glfw)