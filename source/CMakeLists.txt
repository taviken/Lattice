cmake_minimum_required(VERSION 3.5)

project(Lattice VERSION 0.1.0 LANGUAGES CXX) 



set(CMAKE_CXX_STANDARD 20)
# Require the specified standard, preventing fallback to older versions
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
if(Python3_FOUND)
    message(STATUS "Found Python 3: ${Python3_EXECUTABLE}")
    message(STATUS "Python 3 Libraries: ${Python3_LIBRARIES}")
    include_directories(${Python3_INCLUDE_DIRS})
endif()
add_subdirectory(libs/pybind11)



file(GLOB SOURCES src/*.cpp )
file(GLOB HEADERS header/*.h )


# spit out exes in bin dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../bin)

# add_executable(${PROJECT_NAME} WIN32 ${SOURCES} ${HEADERS}) # use this for conslole app, figure out cmake presets later
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE "header")

# # Disable building GLFW examples, tests, and docs
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
# Add the GLFW source directory
add_subdirectory(libs/glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

# add pybind11
target_link_libraries(${PROJECT_NAME} PUBLIC pybind11::embed)
target_link_libraries(${PROJECT_NAME} PUBLIC "C:/Program Files/Python314/libs/python314_d.lib")
target_link_libraries(${PROJECT_NAME} PUBLIC "C:/Program Files/Python314/libs/python314.lib")
# target_link_libraries(${PROJECT_NAME} PUBLIC ${Python3_LIBRARIES}) # this needs work, debug build can't find debug library


# add glad stuff
add_subdirectory(libs/glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)