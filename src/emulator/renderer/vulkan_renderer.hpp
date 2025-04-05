#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <vector>
#include <iostream>

class VulkanRenderer {
public:
    VulkanRenderer();
    ~VulkanRenderer();
    
    void init(GLFWwindow* window);
    void drawFrame();
    void cleanup();

private:
    void createInstance();
    void pickPhysicalDevice();
    void createLogicalDevice();
    
    VkInstance instance;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;
};
