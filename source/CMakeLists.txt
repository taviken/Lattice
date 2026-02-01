cmake_minimum_required(VERSION 3.5)

project(Lattice VERSION 0.1.0 LANGUAGES CXX) 



set(CMAKE_CXX_STANDARD 20)
# Require the specified standard, preventing fallback to older versions
set(CMAKE_CXX_STANDARD_REQUIRED ON)



file(GLOB SOURCES src/*.cpp )
file(GLOB HEADERS header/*.h )


# spit out exes in bin dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../bin)

add_executable(${PROJECT_NAME} WIN32 ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE "header")

# # Disable building GLFW examples, tests, and docs
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
# Add the GLFW source directory
add_subdirectory(libs/glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

# add glad stuff
add_subdirectory(libs/glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)