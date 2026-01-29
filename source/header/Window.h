// #pragma once
#ifndef __Window_H
#define __Window_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <stdexcept>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class Window {
public:
    void run();
    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();
    void createInstance();


private:
    GLFWwindow* window;
    VkInstance instance;

    
};
#endif