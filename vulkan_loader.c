#include "vulkan_loader.h"

#if defined(__linux__) && !defined(__ANDROID__)
#define VK_LOADER_LINUX
#include <dlfcn.h>
#elif defined(_WIN32)
#define VK_LOADER_WINDOWS
#include <Windows.h>
#else
#error "Platform not supported"
#endif //Platform

VkResult vklInitVulkan(VklMasterTable *table)
{
#ifdef VK_LOADER_LINUX
       void *handler = dlopen("libvulkan.so", RTLD_NOW | RTLD_LOCAL);
       if (handler == NULL)
       {
              handler = dlopen("libvulkan.so.1", RTLD_NOW | RTLD_LOCAL);
       }
       if (handler == NULL)
       {
              return VK_ERROR_INITIALIZATION_FAILED;
       }
       table->vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr)dlsym(handler, "vkGetInstanceProcAddr");
#endif //VK_LOADER_LINUX

#ifdef VK_LOADER_WINDOWS
       HMODULE handler = LoadLibrary("vulkan-1.dll");
       if (handler == NULL)
       {
              return VK_ERROR_INITIALIZATION_FAILED;
       }
       table->vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr)GetProcAddress(handler, "vkGetInstanceProcAddr");
#endif //VK_LOADER_WINDOWS

       if (table->vkGetInstanceProcAddr == NULL)
       {
              return VK_ERROR_INITIALIZATION_FAILED;
       }

#ifdef VK_VERSION_1_0
       table->vkCreateInstance = (PFN_vkCreateInstance)table->vkGetInstanceProcAddr(NULL, "vkCreateInstance");
       table->vkEnumerateInstanceExtensionProperties = (PFN_vkEnumerateInstanceExtensionProperties)table->vkGetInstanceProcAddr(NULL, "vkEnumerateInstanceExtensionProperties");
       table->vkEnumerateInstanceLayerProperties = (PFN_vkEnumerateInstanceLayerProperties)table->vkGetInstanceProcAddr(NULL, "vkEnumerateInstanceLayerProperties");
#endif //VK_VERSION_1_0

#ifdef VK_VERSION_1_1
       table->vkEnumerateInstanceVersion = (PFN_vkEnumerateInstanceVersion)table->vkGetInstanceProcAddr(NULL, "vkEnumerateInstanceVersion");
#endif //VK_VERSION_1_1
       return VK_SUCCESS;
}

void vklLoadInstanceTable(VkInstance instance, VklMasterTable *master_table, VklInstanceTable *instance_table)
{
       PFN_vkGetInstanceProcAddr load = master_table->vkGetInstanceProcAddr;
#ifdef VK_VERSION_1_0
       instance_table->vkGetDeviceProcAddr = (PFN_vkGetDeviceProcAddr)load(instance, "vkGetDeviceProcAddr");
       instance_table->vkDestroyInstance = (PFN_vkDestroyInstance)load(instance, "vkDestroyInstance");
       instance_table->vkEnumeratePhysicalDevices = (PFN_vkEnumeratePhysicalDevices)load(instance, "vkEnumeratePhysicalDevices");
       instance_table->vkGetPhysicalDeviceFeatures = (PFN_vkGetPhysicalDeviceFeatures)load(instance, "vkGetPhysicalDeviceFeatures");
       instance_table->vkGetPhysicalDeviceFormatProperties = (PFN_vkGetPhysicalDeviceFormatProperties)load(instance, "vkGetPhysicalDeviceFormatProperties");
       instance_table->vkGetPhysicalDeviceImageFormatProperties = (PFN_vkGetPhysicalDeviceImageFormatProperties)load(instance, "vkGetPhysicalDeviceImageFormatProperties");
       instance_table->vkGetPhysicalDeviceProperties = (PFN_vkGetPhysicalDeviceProperties)load(instance, "vkGetPhysicalDeviceProperties");
       instance_table->vkGetPhysicalDeviceQueueFamilyProperties = (PFN_vkGetPhysicalDeviceQueueFamilyProperties)load(instance, "vkGetPhysicalDeviceQueueFamilyProperties");
       instance_table->vkGetPhysicalDeviceMemoryProperties = (PFN_vkGetPhysicalDeviceMemoryProperties)load(instance, "vkGetPhysicalDeviceMemoryProperties");
       instance_table->vkCreateDevice = (PFN_vkCreateDevice)load(instance, "vkCreateDevice");
       instance_table->vkEnumerateInstanceExtensionProperties = (PFN_vkEnumerateInstanceExtensionProperties)load(instance, "vkEnumerateInstanceExtensionProperties");
       instance_table->vkEnumerateDeviceExtensionProperties = (PFN_vkEnumerateDeviceExtensionProperties)load(instance, "vkEnumerateDeviceExtensionProperties");
       instance_table->vkEnumerateInstanceLayerProperties = (PFN_vkEnumerateInstanceLayerProperties)load(instance, "vkEnumerateInstanceLayerProperties");
       instance_table->vkEnumerateDeviceLayerProperties = (PFN_vkEnumerateDeviceLayerProperties)load(instance, "vkEnumerateDeviceLayerProperties");
       instance_table->vkGetPhysicalDeviceSparseImageFormatProperties = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties)load(instance, "vkGetPhysicalDeviceSparseImageFormatProperties");
#endif //VK_VERSION_1_0

#ifdef VK_VERSION_1_1
       instance_table->vkEnumerateInstanceVersion = (PFN_vkEnumerateInstanceVersion)load(instance, "vkEnumerateInstanceVersion");
       instance_table->vkEnumeratePhysicalDeviceGroups = (PFN_vkEnumeratePhysicalDeviceGroups)load(instance, "vkEnumeratePhysicalDeviceGroups");
       instance_table->vkGetPhysicalDeviceFeatures2 = (PFN_vkGetPhysicalDeviceFeatures2)load(instance, "vkGetPhysicalDeviceFeatures2");
       instance_table->vkGetPhysicalDeviceProperties2 = (PFN_vkGetPhysicalDeviceProperties2)load(instance, "vkGetPhysicalDeviceProperties2");
       instance_table->vkGetPhysicalDeviceFormatProperties2 = (PFN_vkGetPhysicalDeviceFormatProperties2)load(instance, "vkGetPhysicalDeviceFormatProperties2");
       instance_table->vkGetPhysicalDeviceImageFormatProperties2 = (PFN_vkGetPhysicalDeviceImageFormatProperties2)load(instance, "vkGetPhysicalDeviceImageFormatProperties2");
       instance_table->vkGetPhysicalDeviceQueueFamilyProperties2 = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2)load(instance, "vkGetPhysicalDeviceQueueFamilyProperties2");
       instance_table->vkGetPhysicalDeviceMemoryProperties2 = (PFN_vkGetPhysicalDeviceMemoryProperties2)load(instance, "vkGetPhysicalDeviceMemoryProperties2");
       instance_table->vkGetPhysicalDeviceSparseImageFormatProperties2 = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2)load(instance, "vkGetPhysicalDeviceSparseImageFormatProperties2");
       instance_table->vkGetPhysicalDeviceExternalBufferProperties = (PFN_vkGetPhysicalDeviceExternalBufferProperties)load(instance, "vkGetPhysicalDeviceExternalBufferProperties");
       instance_table->vkGetPhysicalDeviceExternalFenceProperties = (PFN_vkGetPhysicalDeviceExternalFenceProperties)load(instance, "vkGetPhysicalDeviceExternalFenceProperties");
       instance_table->vkGetPhysicalDeviceExternalSemaphoreProperties = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties)load(instance, "vkGetPhysicalDeviceExternalSemaphoreProperties");
#endif //VK_VERSION_1_1

#ifdef VK_KHR_surface
       instance_table->vkDestroySurfaceKHR = (PFN_vkDestroySurfaceKHR)load(instance, "vkDestroySurfaceKHR");
       instance_table->vkGetPhysicalDeviceSurfaceSupportKHR = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR)load(instance, "vkGetPhysicalDeviceSurfaceSupportKHR");
       instance_table->vkGetPhysicalDeviceSurfaceCapabilitiesKHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR)load(instance, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
       instance_table->vkGetPhysicalDeviceSurfaceFormatsKHR = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR)load(instance, "vkGetPhysicalDeviceSurfaceFormatsKHR");
       instance_table->vkGetPhysicalDeviceSurfacePresentModesKHR = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR)load(instance, "vkGetPhysicalDeviceSurfacePresentModesKHR");
#endif //VK_KHR_surface

#ifdef VK_KHR_swapchain
       instance_table->vkGetPhysicalDevicePresentRectanglesKHR = (PFN_vkGetPhysicalDevicePresentRectanglesKHR)load(instance, "vkGetPhysicalDevicePresentRectanglesKHR");
#endif //VK_KHR_swapchain

#ifdef VK_KHR_display
       instance_table->vkGetPhysicalDeviceDisplayPropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPropertiesKHR)load(instance, "vkGetPhysicalDeviceDisplayPropertiesKHR");
       instance_table->vkGetPhysicalDeviceDisplayPlanePropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR)load(instance, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
       instance_table->vkGetDisplayPlaneSupportedDisplaysKHR = (PFN_vkGetDisplayPlaneSupportedDisplaysKHR)load(instance, "vkGetDisplayPlaneSupportedDisplaysKHR");
       instance_table->vkGetDisplayModePropertiesKHR = (PFN_vkGetDisplayModePropertiesKHR)load(instance, "vkGetDisplayModePropertiesKHR");
       instance_table->vkCreateDisplayModeKHR = (PFN_vkCreateDisplayModeKHR)load(instance, "vkCreateDisplayModeKHR");
       instance_table->vkGetDisplayPlaneCapabilitiesKHR = (PFN_vkGetDisplayPlaneCapabilitiesKHR)load(instance, "vkGetDisplayPlaneCapabilitiesKHR");
       instance_table->vkCreateDisplayPlaneSurfaceKHR = (PFN_vkCreateDisplayPlaneSurfaceKHR)load(instance, "vkCreateDisplayPlaneSurfaceKHR");
#endif //VK_KHR_display

#ifdef VK_KHR_get_physical_device_properties2
       instance_table->vkGetPhysicalDeviceFeatures2KHR = (PFN_vkGetPhysicalDeviceFeatures2KHR)load(instance, "vkGetPhysicalDeviceFeatures2KHR");
       instance_table->vkGetPhysicalDeviceProperties2KHR = (PFN_vkGetPhysicalDeviceProperties2KHR)load(instance, "vkGetPhysicalDeviceProperties2KHR");
       instance_table->vkGetPhysicalDeviceFormatProperties2KHR = (PFN_vkGetPhysicalDeviceFormatProperties2KHR)load(instance, "vkGetPhysicalDeviceFormatProperties2KHR");
       instance_table->vkGetPhysicalDeviceImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceImageFormatProperties2KHR)load(instance, "vkGetPhysicalDeviceImageFormatProperties2KHR");
       instance_table->vkGetPhysicalDeviceQueueFamilyProperties2KHR = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR)load(instance, "vkGetPhysicalDeviceQueueFamilyProperties2KHR");
       instance_table->vkGetPhysicalDeviceMemoryProperties2KHR = (PFN_vkGetPhysicalDeviceMemoryProperties2KHR)load(instance, "vkGetPhysicalDeviceMemoryProperties2KHR");
       instance_table->vkGetPhysicalDeviceSparseImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR)load(instance, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
#endif //VK_KHR_get_physical_device_properties2

#ifdef VK_KHR_device_group_creation
       instance_table->vkEnumeratePhysicalDeviceGroupsKHR = (PFN_vkEnumeratePhysicalDeviceGroupsKHR)load(instance, "vkEnumeratePhysicalDeviceGroupsKHR");
#endif //VK_KHR_device_group_creation

#ifdef VK_KHR_external_memory_capabilities
       instance_table->vkGetPhysicalDeviceExternalBufferPropertiesKHR = (PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR)load(instance, "vkGetPhysicalDeviceExternalBufferPropertiesKHR");
#endif //VK_KHR_external_memory_capabilities

#ifdef VK_KHR_external_semaphore_capabilities
       instance_table->vkGetPhysicalDeviceExternalSemaphorePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR)load(instance, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
#endif //VK_KHR_external_semaphore_capabilities

#ifdef VK_KHR_external_fence_capabilities
       instance_table->vkGetPhysicalDeviceExternalFencePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR)load(instance, "vkGetPhysicalDeviceExternalFencePropertiesKHR");
#endif //VK_KHR_external_fence_capabilities

#ifdef VK_KHR_performance_query
       instance_table->vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = (PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR)load(instance, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
       instance_table->vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = (PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR)load(instance, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
#endif //VK_KHR_performance_query

#ifdef VK_KHR_get_surface_capabilities2
       instance_table->vkGetPhysicalDeviceSurfaceCapabilities2KHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR)load(instance, "vkGetPhysicalDeviceSurfaceCapabilities2KHR");
       instance_table->vkGetPhysicalDeviceSurfaceFormats2KHR = (PFN_vkGetPhysicalDeviceSurfaceFormats2KHR)load(instance, "vkGetPhysicalDeviceSurfaceFormats2KHR");
#endif //VK_KHR_get_surface_capabilities2

#ifdef VK_KHR_get_display_properties2
       instance_table->vkGetPhysicalDeviceDisplayProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayProperties2KHR)load(instance, "vkGetPhysicalDeviceDisplayProperties2KHR");
       instance_table->vkGetPhysicalDeviceDisplayPlaneProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR)load(instance, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
       instance_table->vkGetDisplayModeProperties2KHR = (PFN_vkGetDisplayModeProperties2KHR)load(instance, "vkGetDisplayModeProperties2KHR");
       instance_table->vkGetDisplayPlaneCapabilities2KHR = (PFN_vkGetDisplayPlaneCapabilities2KHR)load(instance, "vkGetDisplayPlaneCapabilities2KHR");
#endif //VK_KHR_get_display_properties2

#ifdef VK_EXT_debug_report
       instance_table->vkDebugReportCallbackEXT = (PFN_vkDebugReportCallbackEXT)load(instance, "vkDebugReportCallbackEXT");
       instance_table->vkCreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT)load(instance, "vkCreateDebugReportCallbackEXT");
       instance_table->vkDestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT)load(instance, "vkDestroyDebugReportCallbackEXT");
       instance_table->vkDebugReportMessageEXT = (PFN_vkDebugReportMessageEXT)load(instance, "vkDebugReportMessageEXT");
#endif //VK_EXT_debug_report

#ifdef VK_NV_external_memory_capabilities
       instance_table->vkGetPhysicalDeviceExternalImageFormatPropertiesNV = (PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV)load(instance, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV");
#endif //VK_NV_external_memory_capabilities

#ifdef VK_EXT_direct_mode_display
       instance_table->vkReleaseDisplayEXT = (PFN_vkReleaseDisplayEXT)load(instance, "vkReleaseDisplayEXT");
#endif //VK_EXT_direct_mode_display

#ifdef VK_EXT_display_surface_counter
       instance_table->vkGetPhysicalDeviceSurfaceCapabilities2EXT = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT)load(instance, "vkGetPhysicalDeviceSurfaceCapabilities2EXT");
#endif //VK_EXT_display_surface_counter

#ifdef VK_EXT_debug_utils
       instance_table->vkDebugUtilsMessengerCallbackEXT = (PFN_vkDebugUtilsMessengerCallbackEXT)load(instance, "vkDebugUtilsMessengerCallbackEXT");
       instance_table->vkCreateDebugUtilsMessengerEXT = (PFN_vkCreateDebugUtilsMessengerEXT)load(instance, "vkCreateDebugUtilsMessengerEXT");
       instance_table->vkDestroyDebugUtilsMessengerEXT = (PFN_vkDestroyDebugUtilsMessengerEXT)load(instance, "vkDestroyDebugUtilsMessengerEXT");
       instance_table->vkSubmitDebugUtilsMessageEXT = (PFN_vkSubmitDebugUtilsMessageEXT)load(instance, "vkSubmitDebugUtilsMessageEXT");
#endif //VK_EXT_debug_utils

#ifdef VK_EXT_sample_locations
       instance_table->vkGetPhysicalDeviceMultisamplePropertiesEXT = (PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT)load(instance, "vkGetPhysicalDeviceMultisamplePropertiesEXT");
#endif //VK_EXT_sample_locations

#ifdef VK_EXT_calibrated_timestamps
       instance_table->vkGetPhysicalDeviceCalibrateableTimeDomainsEXT = (PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT)load(instance, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
#endif //VK_EXT_calibrated_timestamps

#ifdef VK_EXT_tooling_info
       instance_table->vkGetPhysicalDeviceToolPropertiesEXT = (PFN_vkGetPhysicalDeviceToolPropertiesEXT)load(instance, "vkGetPhysicalDeviceToolPropertiesEXT");
#endif //VK_EXT_tooling_info

#ifdef VK_NV_cooperative_matrix
       instance_table->vkGetPhysicalDeviceCooperativeMatrixPropertiesNV = (PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV)load(instance, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV");
#endif //VK_NV_cooperative_matrix

#ifdef VK_NV_coverage_reduction_mode
       instance_table->vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = (PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV)load(instance, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV");
#endif //VK_NV_coverage_reduction_mode

#ifdef VK_EXT_headless_surface
       instance_table->vkCreateHeadlessSurfaceEXT = (PFN_vkCreateHeadlessSurfaceEXT)load(instance, "vkCreateHeadlessSurfaceEXT");
#endif //VK_EXT_headless_surface
}

void vklLoadDeviceTable(VkDevice device, VklInstanceTable *instance_table, VklDeviceTable *device_table)
{
       PFN_vkGetDeviceProcAddr load = instance_table->vkGetDeviceProcAddr;
#ifdef VK_VERSION_1_0
       device_table->vkDestroyDevice = (PFN_vkDestroyDevice)load(device, "vkDestroyDevice");
       device_table->vkGetDeviceQueue = (PFN_vkGetDeviceQueue)load(device, "vkGetDeviceQueue");
       device_table->vkQueueSubmit = (PFN_vkQueueSubmit)load(device, "vkQueueSubmit");
       device_table->vkQueueWaitIdle = (PFN_vkQueueWaitIdle)load(device, "vkQueueWaitIdle");
       device_table->vkDeviceWaitIdle = (PFN_vkDeviceWaitIdle)load(device, "vkDeviceWaitIdle");
       device_table->vkAllocateMemory = (PFN_vkAllocateMemory)load(device, "vkAllocateMemory");
       device_table->vkFreeMemory = (PFN_vkFreeMemory)load(device, "vkFreeMemory");
       device_table->vkMapMemory = (PFN_vkMapMemory)load(device, "vkMapMemory");
       device_table->vkUnmapMemory = (PFN_vkUnmapMemory)load(device, "vkUnmapMemory");
       device_table->vkFlushMappedMemoryRanges = (PFN_vkFlushMappedMemoryRanges)load(device, "vkFlushMappedMemoryRanges");
       device_table->vkInvalidateMappedMemoryRanges = (PFN_vkInvalidateMappedMemoryRanges)load(device, "vkInvalidateMappedMemoryRanges");
       device_table->vkGetDeviceMemoryCommitment = (PFN_vkGetDeviceMemoryCommitment)load(device, "vkGetDeviceMemoryCommitment");
       device_table->vkBindBufferMemory = (PFN_vkBindBufferMemory)load(device, "vkBindBufferMemory");
       device_table->vkBindImageMemory = (PFN_vkBindImageMemory)load(device, "vkBindImageMemory");
       device_table->vkGetBufferMemoryRequirements = (PFN_vkGetBufferMemoryRequirements)load(device, "vkGetBufferMemoryRequirements");
       device_table->vkGetImageMemoryRequirements = (PFN_vkGetImageMemoryRequirements)load(device, "vkGetImageMemoryRequirements");
       device_table->vkGetImageSparseMemoryRequirements = (PFN_vkGetImageSparseMemoryRequirements)load(device, "vkGetImageSparseMemoryRequirements");
       device_table->vkQueueBindSparse = (PFN_vkQueueBindSparse)load(device, "vkQueueBindSparse");
       device_table->vkCreateFence = (PFN_vkCreateFence)load(device, "vkCreateFence");
       device_table->vkDestroyFence = (PFN_vkDestroyFence)load(device, "vkDestroyFence");
       device_table->vkResetFences = (PFN_vkResetFences)load(device, "vkResetFences");
       device_table->vkGetFenceStatus = (PFN_vkGetFenceStatus)load(device, "vkGetFenceStatus");
       device_table->vkWaitForFences = (PFN_vkWaitForFences)load(device, "vkWaitForFences");
       device_table->vkCreateSemaphore = (PFN_vkCreateSemaphore)load(device, "vkCreateSemaphore");
       device_table->vkDestroySemaphore = (PFN_vkDestroySemaphore)load(device, "vkDestroySemaphore");
       device_table->vkCreateEvent = (PFN_vkCreateEvent)load(device, "vkCreateEvent");
       device_table->vkDestroyEvent = (PFN_vkDestroyEvent)load(device, "vkDestroyEvent");
       device_table->vkGetEventStatus = (PFN_vkGetEventStatus)load(device, "vkGetEventStatus");
       device_table->vkSetEvent = (PFN_vkSetEvent)load(device, "vkSetEvent");
       device_table->vkResetEvent = (PFN_vkResetEvent)load(device, "vkResetEvent");
       device_table->vkCreateQueryPool = (PFN_vkCreateQueryPool)load(device, "vkCreateQueryPool");
       device_table->vkDestroyQueryPool = (PFN_vkDestroyQueryPool)load(device, "vkDestroyQueryPool");
       device_table->vkGetQueryPoolResults = (PFN_vkGetQueryPoolResults)load(device, "vkGetQueryPoolResults");
       device_table->vkCreateBuffer = (PFN_vkCreateBuffer)load(device, "vkCreateBuffer");
       device_table->vkDestroyBuffer = (PFN_vkDestroyBuffer)load(device, "vkDestroyBuffer");
       device_table->vkCreateBufferView = (PFN_vkCreateBufferView)load(device, "vkCreateBufferView");
       device_table->vkDestroyBufferView = (PFN_vkDestroyBufferView)load(device, "vkDestroyBufferView");
       device_table->vkCreateImage = (PFN_vkCreateImage)load(device, "vkCreateImage");
       device_table->vkDestroyImage = (PFN_vkDestroyImage)load(device, "vkDestroyImage");
       device_table->vkGetImageSubresourceLayout = (PFN_vkGetImageSubresourceLayout)load(device, "vkGetImageSubresourceLayout");
       device_table->vkCreateImageView = (PFN_vkCreateImageView)load(device, "vkCreateImageView");
       device_table->vkDestroyImageView = (PFN_vkDestroyImageView)load(device, "vkDestroyImageView");
       device_table->vkCreateShaderModule = (PFN_vkCreateShaderModule)load(device, "vkCreateShaderModule");
       device_table->vkDestroyShaderModule = (PFN_vkDestroyShaderModule)load(device, "vkDestroyShaderModule");
       device_table->vkCreatePipelineCache = (PFN_vkCreatePipelineCache)load(device, "vkCreatePipelineCache");
       device_table->vkDestroyPipelineCache = (PFN_vkDestroyPipelineCache)load(device, "vkDestroyPipelineCache");
       device_table->vkGetPipelineCacheData = (PFN_vkGetPipelineCacheData)load(device, "vkGetPipelineCacheData");
       device_table->vkMergePipelineCaches = (PFN_vkMergePipelineCaches)load(device, "vkMergePipelineCaches");
       device_table->vkCreateGraphicsPipelines = (PFN_vkCreateGraphicsPipelines)load(device, "vkCreateGraphicsPipelines");
       device_table->vkCreateComputePipelines = (PFN_vkCreateComputePipelines)load(device, "vkCreateComputePipelines");
       device_table->vkDestroyPipeline = (PFN_vkDestroyPipeline)load(device, "vkDestroyPipeline");
       device_table->vkCreatePipelineLayout = (PFN_vkCreatePipelineLayout)load(device, "vkCreatePipelineLayout");
       device_table->vkDestroyPipelineLayout = (PFN_vkDestroyPipelineLayout)load(device, "vkDestroyPipelineLayout");
       device_table->vkCreateSampler = (PFN_vkCreateSampler)load(device, "vkCreateSampler");
       device_table->vkDestroySampler = (PFN_vkDestroySampler)load(device, "vkDestroySampler");
       device_table->vkCreateDescriptorSetLayout = (PFN_vkCreateDescriptorSetLayout)load(device, "vkCreateDescriptorSetLayout");
       device_table->vkDestroyDescriptorSetLayout = (PFN_vkDestroyDescriptorSetLayout)load(device, "vkDestroyDescriptorSetLayout");
       device_table->vkCreateDescriptorPool = (PFN_vkCreateDescriptorPool)load(device, "vkCreateDescriptorPool");
       device_table->vkDestroyDescriptorPool = (PFN_vkDestroyDescriptorPool)load(device, "vkDestroyDescriptorPool");
       device_table->vkResetDescriptorPool = (PFN_vkResetDescriptorPool)load(device, "vkResetDescriptorPool");
       device_table->vkAllocateDescriptorSets = (PFN_vkAllocateDescriptorSets)load(device, "vkAllocateDescriptorSets");
       device_table->vkFreeDescriptorSets = (PFN_vkFreeDescriptorSets)load(device, "vkFreeDescriptorSets");
       device_table->vkUpdateDescriptorSets = (PFN_vkUpdateDescriptorSets)load(device, "vkUpdateDescriptorSets");
       device_table->vkCreateFramebuffer = (PFN_vkCreateFramebuffer)load(device, "vkCreateFramebuffer");
       device_table->vkDestroyFramebuffer = (PFN_vkDestroyFramebuffer)load(device, "vkDestroyFramebuffer");
       device_table->vkCreateRenderPass = (PFN_vkCreateRenderPass)load(device, "vkCreateRenderPass");
       device_table->vkDestroyRenderPass = (PFN_vkDestroyRenderPass)load(device, "vkDestroyRenderPass");
       device_table->vkGetRenderAreaGranularity = (PFN_vkGetRenderAreaGranularity)load(device, "vkGetRenderAreaGranularity");
       device_table->vkCreateCommandPool = (PFN_vkCreateCommandPool)load(device, "vkCreateCommandPool");
       device_table->vkDestroyCommandPool = (PFN_vkDestroyCommandPool)load(device, "vkDestroyCommandPool");
       device_table->vkResetCommandPool = (PFN_vkResetCommandPool)load(device, "vkResetCommandPool");
       device_table->vkAllocateCommandBuffers = (PFN_vkAllocateCommandBuffers)load(device, "vkAllocateCommandBuffers");
       device_table->vkFreeCommandBuffers = (PFN_vkFreeCommandBuffers)load(device, "vkFreeCommandBuffers");
       device_table->vkBeginCommandBuffer = (PFN_vkBeginCommandBuffer)load(device, "vkBeginCommandBuffer");
       device_table->vkEndCommandBuffer = (PFN_vkEndCommandBuffer)load(device, "vkEndCommandBuffer");
       device_table->vkResetCommandBuffer = (PFN_vkResetCommandBuffer)load(device, "vkResetCommandBuffer");
       device_table->vkCmdBindPipeline = (PFN_vkCmdBindPipeline)load(device, "vkCmdBindPipeline");
       device_table->vkCmdSetViewport = (PFN_vkCmdSetViewport)load(device, "vkCmdSetViewport");
       device_table->vkCmdSetScissor = (PFN_vkCmdSetScissor)load(device, "vkCmdSetScissor");
       device_table->vkCmdSetLineWidth = (PFN_vkCmdSetLineWidth)load(device, "vkCmdSetLineWidth");
       device_table->vkCmdSetDepthBias = (PFN_vkCmdSetDepthBias)load(device, "vkCmdSetDepthBias");
       device_table->vkCmdSetBlendConstants = (PFN_vkCmdSetBlendConstants)load(device, "vkCmdSetBlendConstants");
       device_table->vkCmdSetDepthBounds = (PFN_vkCmdSetDepthBounds)load(device, "vkCmdSetDepthBounds");
       device_table->vkCmdSetStencilCompareMask = (PFN_vkCmdSetStencilCompareMask)load(device, "vkCmdSetStencilCompareMask");
       device_table->vkCmdSetStencilWriteMask = (PFN_vkCmdSetStencilWriteMask)load(device, "vkCmdSetStencilWriteMask");
       device_table->vkCmdSetStencilReference = (PFN_vkCmdSetStencilReference)load(device, "vkCmdSetStencilReference");
       device_table->vkCmdBindDescriptorSets = (PFN_vkCmdBindDescriptorSets)load(device, "vkCmdBindDescriptorSets");
       device_table->vkCmdBindIndexBuffer = (PFN_vkCmdBindIndexBuffer)load(device, "vkCmdBindIndexBuffer");
       device_table->vkCmdBindVertexBuffers = (PFN_vkCmdBindVertexBuffers)load(device, "vkCmdBindVertexBuffers");
       device_table->vkCmdDraw = (PFN_vkCmdDraw)load(device, "vkCmdDraw");
       device_table->vkCmdDrawIndexed = (PFN_vkCmdDrawIndexed)load(device, "vkCmdDrawIndexed");
       device_table->vkCmdDrawIndirect = (PFN_vkCmdDrawIndirect)load(device, "vkCmdDrawIndirect");
       device_table->vkCmdDrawIndexedIndirect = (PFN_vkCmdDrawIndexedIndirect)load(device, "vkCmdDrawIndexedIndirect");
       device_table->vkCmdDispatch = (PFN_vkCmdDispatch)load(device, "vkCmdDispatch");
       device_table->vkCmdDispatchIndirect = (PFN_vkCmdDispatchIndirect)load(device, "vkCmdDispatchIndirect");
       device_table->vkCmdCopyBuffer = (PFN_vkCmdCopyBuffer)load(device, "vkCmdCopyBuffer");
       device_table->vkCmdCopyImage = (PFN_vkCmdCopyImage)load(device, "vkCmdCopyImage");
       device_table->vkCmdBlitImage = (PFN_vkCmdBlitImage)load(device, "vkCmdBlitImage");
       device_table->vkCmdCopyBufferToImage = (PFN_vkCmdCopyBufferToImage)load(device, "vkCmdCopyBufferToImage");
       device_table->vkCmdCopyImageToBuffer = (PFN_vkCmdCopyImageToBuffer)load(device, "vkCmdCopyImageToBuffer");
       device_table->vkCmdUpdateBuffer = (PFN_vkCmdUpdateBuffer)load(device, "vkCmdUpdateBuffer");
       device_table->vkCmdFillBuffer = (PFN_vkCmdFillBuffer)load(device, "vkCmdFillBuffer");
       device_table->vkCmdClearColorImage = (PFN_vkCmdClearColorImage)load(device, "vkCmdClearColorImage");
       device_table->vkCmdClearDepthStencilImage = (PFN_vkCmdClearDepthStencilImage)load(device, "vkCmdClearDepthStencilImage");
       device_table->vkCmdClearAttachments = (PFN_vkCmdClearAttachments)load(device, "vkCmdClearAttachments");
       device_table->vkCmdResolveImage = (PFN_vkCmdResolveImage)load(device, "vkCmdResolveImage");
       device_table->vkCmdSetEvent = (PFN_vkCmdSetEvent)load(device, "vkCmdSetEvent");
       device_table->vkCmdResetEvent = (PFN_vkCmdResetEvent)load(device, "vkCmdResetEvent");
       device_table->vkCmdWaitEvents = (PFN_vkCmdWaitEvents)load(device, "vkCmdWaitEvents");
       device_table->vkCmdPipelineBarrier = (PFN_vkCmdPipelineBarrier)load(device, "vkCmdPipelineBarrier");
       device_table->vkCmdBeginQuery = (PFN_vkCmdBeginQuery)load(device, "vkCmdBeginQuery");
       device_table->vkCmdEndQuery = (PFN_vkCmdEndQuery)load(device, "vkCmdEndQuery");
       device_table->vkCmdResetQueryPool = (PFN_vkCmdResetQueryPool)load(device, "vkCmdResetQueryPool");
       device_table->vkCmdWriteTimestamp = (PFN_vkCmdWriteTimestamp)load(device, "vkCmdWriteTimestamp");
       device_table->vkCmdCopyQueryPoolResults = (PFN_vkCmdCopyQueryPoolResults)load(device, "vkCmdCopyQueryPoolResults");
       device_table->vkCmdPushConstants = (PFN_vkCmdPushConstants)load(device, "vkCmdPushConstants");
       device_table->vkCmdBeginRenderPass = (PFN_vkCmdBeginRenderPass)load(device, "vkCmdBeginRenderPass");
       device_table->vkCmdNextSubpass = (PFN_vkCmdNextSubpass)load(device, "vkCmdNextSubpass");
       device_table->vkCmdEndRenderPass = (PFN_vkCmdEndRenderPass)load(device, "vkCmdEndRenderPass");
       device_table->vkCmdExecuteCommands = (PFN_vkCmdExecuteCommands)load(device, "vkCmdExecuteCommands");
#endif //VK_VERSION_1_0

#ifdef VK_VERSION_1_1
       device_table->vkBindBufferMemory2 = (PFN_vkBindBufferMemory2)load(device, "vkBindBufferMemory2");
       device_table->vkBindImageMemory2 = (PFN_vkBindImageMemory2)load(device, "vkBindImageMemory2");
       device_table->vkGetDeviceGroupPeerMemoryFeatures = (PFN_vkGetDeviceGroupPeerMemoryFeatures)load(device, "vkGetDeviceGroupPeerMemoryFeatures");
       device_table->vkCmdSetDeviceMask = (PFN_vkCmdSetDeviceMask)load(device, "vkCmdSetDeviceMask");
       device_table->vkCmdDispatchBase = (PFN_vkCmdDispatchBase)load(device, "vkCmdDispatchBase");
       device_table->vkGetImageMemoryRequirements2 = (PFN_vkGetImageMemoryRequirements2)load(device, "vkGetImageMemoryRequirements2");
       device_table->vkGetBufferMemoryRequirements2 = (PFN_vkGetBufferMemoryRequirements2)load(device, "vkGetBufferMemoryRequirements2");
       device_table->vkGetImageSparseMemoryRequirements2 = (PFN_vkGetImageSparseMemoryRequirements2)load(device, "vkGetImageSparseMemoryRequirements2");
       device_table->vkTrimCommandPool = (PFN_vkTrimCommandPool)load(device, "vkTrimCommandPool");
       device_table->vkGetDeviceQueue2 = (PFN_vkGetDeviceQueue2)load(device, "vkGetDeviceQueue2");
       device_table->vkCreateSamplerYcbcrConversion = (PFN_vkCreateSamplerYcbcrConversion)load(device, "vkCreateSamplerYcbcrConversion");
       device_table->vkDestroySamplerYcbcrConversion = (PFN_vkDestroySamplerYcbcrConversion)load(device, "vkDestroySamplerYcbcrConversion");
       device_table->vkCreateDescriptorUpdateTemplate = (PFN_vkCreateDescriptorUpdateTemplate)load(device, "vkCreateDescriptorUpdateTemplate");
       device_table->vkDestroyDescriptorUpdateTemplate = (PFN_vkDestroyDescriptorUpdateTemplate)load(device, "vkDestroyDescriptorUpdateTemplate");
       device_table->vkUpdateDescriptorSetWithTemplate = (PFN_vkUpdateDescriptorSetWithTemplate)load(device, "vkUpdateDescriptorSetWithTemplate");
       device_table->vkGetDescriptorSetLayoutSupport = (PFN_vkGetDescriptorSetLayoutSupport)load(device, "vkGetDescriptorSetLayoutSupport");
#endif //VK_VERSION_1_1

#ifdef VK_VERSION_1_2
       device_table->vkCmdDrawIndirectCount = (PFN_vkCmdDrawIndirectCount)load(device, "vkCmdDrawIndirectCount");
       device_table->vkCmdDrawIndexedIndirectCount = (PFN_vkCmdDrawIndexedIndirectCount)load(device, "vkCmdDrawIndexedIndirectCount");
       device_table->vkCreateRenderPass2 = (PFN_vkCreateRenderPass2)load(device, "vkCreateRenderPass2");
       device_table->vkCmdBeginRenderPass2 = (PFN_vkCmdBeginRenderPass2)load(device, "vkCmdBeginRenderPass2");
       device_table->vkCmdNextSubpass2 = (PFN_vkCmdNextSubpass2)load(device, "vkCmdNextSubpass2");
       device_table->vkCmdEndRenderPass2 = (PFN_vkCmdEndRenderPass2)load(device, "vkCmdEndRenderPass2");
       device_table->vkResetQueryPool = (PFN_vkResetQueryPool)load(device, "vkResetQueryPool");
       device_table->vkGetSemaphoreCounterValue = (PFN_vkGetSemaphoreCounterValue)load(device, "vkGetSemaphoreCounterValue");
       device_table->vkWaitSemaphores = (PFN_vkWaitSemaphores)load(device, "vkWaitSemaphores");
       device_table->vkSignalSemaphore = (PFN_vkSignalSemaphore)load(device, "vkSignalSemaphore");
       device_table->vkGetBufferDeviceAddress = (PFN_vkGetBufferDeviceAddress)load(device, "vkGetBufferDeviceAddress");
       device_table->vkGetBufferOpaqueCaptureAddress = (PFN_vkGetBufferOpaqueCaptureAddress)load(device, "vkGetBufferOpaqueCaptureAddress");
       device_table->vkGetDeviceMemoryOpaqueCaptureAddress = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress)load(device, "vkGetDeviceMemoryOpaqueCaptureAddress");
#endif //VK_VERSION_1_2

#ifdef VK_KHR_swapchain
       device_table->vkCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR)load(device, "vkCreateSwapchainKHR");
       device_table->vkDestroySwapchainKHR = (PFN_vkDestroySwapchainKHR)load(device, "vkDestroySwapchainKHR");
       device_table->vkGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)load(device, "vkGetSwapchainImagesKHR");
       device_table->vkAcquireNextImageKHR = (PFN_vkAcquireNextImageKHR)load(device, "vkAcquireNextImageKHR");
       device_table->vkQueuePresentKHR = (PFN_vkQueuePresentKHR)load(device, "vkQueuePresentKHR");
       device_table->vkGetDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR)load(device, "vkGetDeviceGroupPresentCapabilitiesKHR");
       device_table->vkGetDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR)load(device, "vkGetDeviceGroupSurfacePresentModesKHR");
       device_table->vkAcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR)load(device, "vkAcquireNextImage2KHR");
#endif //VK_KHR_swapchain

#ifdef VK_KHR_display_swapchain
       device_table->vkCreateSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR)load(device, "vkCreateSharedSwapchainsKHR");
#endif //VK_KHR_display_swapchain

#ifdef VK_KHR_get_physical_device_properties2
#endif //VK_KHR_get_physical_device_properties2

#ifdef VK_KHR_device_group
       device_table->vkGetDeviceGroupPeerMemoryFeaturesKHR = (PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR)load(device, "vkGetDeviceGroupPeerMemoryFeaturesKHR");
       device_table->vkCmdSetDeviceMaskKHR = (PFN_vkCmdSetDeviceMaskKHR)load(device, "vkCmdSetDeviceMaskKHR");
       device_table->vkCmdDispatchBaseKHR = (PFN_vkCmdDispatchBaseKHR)load(device, "vkCmdDispatchBaseKHR");
#endif //VK_KHR_device_group

#ifdef VK_KHR_maintenance1
       device_table->vkTrimCommandPoolKHR = (PFN_vkTrimCommandPoolKHR)load(device, "vkTrimCommandPoolKHR");
#endif //VK_KHR_maintenance1

#ifdef VK_KHR_external_memory_fd
       device_table->vkGetMemoryFdKHR = (PFN_vkGetMemoryFdKHR)load(device, "vkGetMemoryFdKHR");
       device_table->vkGetMemoryFdPropertiesKHR = (PFN_vkGetMemoryFdPropertiesKHR)load(device, "vkGetMemoryFdPropertiesKHR");
#endif //VK_KHR_external_memory_fd

#ifdef VK_KHR_external_semaphore_fd
       device_table->vkImportSemaphoreFdKHR = (PFN_vkImportSemaphoreFdKHR)load(device, "vkImportSemaphoreFdKHR");
       device_table->vkGetSemaphoreFdKHR = (PFN_vkGetSemaphoreFdKHR)load(device, "vkGetSemaphoreFdKHR");
#endif //VK_KHR_external_semaphore_fd

#ifdef VK_KHR_push_descriptor
       device_table->vkCmdPushDescriptorSetKHR = (PFN_vkCmdPushDescriptorSetKHR)load(device, "vkCmdPushDescriptorSetKHR");
       device_table->vkCmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR)load(device, "vkCmdPushDescriptorSetWithTemplateKHR");
#endif //VK_KHR_push_descriptor

#ifdef VK_KHR_descriptor_update_template
       device_table->vkCreateDescriptorUpdateTemplateKHR = (PFN_vkCreateDescriptorUpdateTemplateKHR)load(device, "vkCreateDescriptorUpdateTemplateKHR");
       device_table->vkDestroyDescriptorUpdateTemplateKHR = (PFN_vkDestroyDescriptorUpdateTemplateKHR)load(device, "vkDestroyDescriptorUpdateTemplateKHR");
       device_table->vkUpdateDescriptorSetWithTemplateKHR = (PFN_vkUpdateDescriptorSetWithTemplateKHR)load(device, "vkUpdateDescriptorSetWithTemplateKHR");
#endif //VK_KHR_descriptor_update_template

#ifdef VK_KHR_create_renderpass2
       device_table->vkCreateRenderPass2KHR = (PFN_vkCreateRenderPass2KHR)load(device, "vkCreateRenderPass2KHR");
       device_table->vkCmdBeginRenderPass2KHR = (PFN_vkCmdBeginRenderPass2KHR)load(device, "vkCmdBeginRenderPass2KHR");
       device_table->vkCmdNextSubpass2KHR = (PFN_vkCmdNextSubpass2KHR)load(device, "vkCmdNextSubpass2KHR");
       device_table->vkCmdEndRenderPass2KHR = (PFN_vkCmdEndRenderPass2KHR)load(device, "vkCmdEndRenderPass2KHR");
#endif //VK_KHR_create_renderpass2

#ifdef VK_KHR_shared_presentable_image
       device_table->vkGetSwapchainStatusKHR = (PFN_vkGetSwapchainStatusKHR)load(device, "vkGetSwapchainStatusKHR");
#endif //VK_KHR_shared_presentable_image

#ifdef VK_KHR_external_fence_fd
       device_table->vkImportFenceFdKHR = (PFN_vkImportFenceFdKHR)load(device, "vkImportFenceFdKHR");
       device_table->vkGetFenceFdKHR = (PFN_vkGetFenceFdKHR)load(device, "vkGetFenceFdKHR");
#endif //VK_KHR_external_fence_fd

#ifdef VK_KHR_performance_query
       device_table->vkAcquireProfilingLockKHR = (PFN_vkAcquireProfilingLockKHR)load(device, "vkAcquireProfilingLockKHR");
       device_table->vkReleaseProfilingLockKHR = (PFN_vkReleaseProfilingLockKHR)load(device, "vkReleaseProfilingLockKHR");
#endif //VK_KHR_performance_query

#ifdef VK_KHR_get_memory_requirements2
       device_table->vkGetImageMemoryRequirements2KHR = (PFN_vkGetImageMemoryRequirements2KHR)load(device, "vkGetImageMemoryRequirements2KHR");
       device_table->vkGetBufferMemoryRequirements2KHR = (PFN_vkGetBufferMemoryRequirements2KHR)load(device, "vkGetBufferMemoryRequirements2KHR");
       device_table->vkGetImageSparseMemoryRequirements2KHR = (PFN_vkGetImageSparseMemoryRequirements2KHR)load(device, "vkGetImageSparseMemoryRequirements2KHR");
#endif //VK_KHR_get_memory_requirements2

#ifdef VK_KHR_sampler_ycbcr_conversion
       device_table->vkCreateSamplerYcbcrConversionKHR = (PFN_vkCreateSamplerYcbcrConversionKHR)load(device, "vkCreateSamplerYcbcrConversionKHR");
       device_table->vkDestroySamplerYcbcrConversionKHR = (PFN_vkDestroySamplerYcbcrConversionKHR)load(device, "vkDestroySamplerYcbcrConversionKHR");
#endif //VK_KHR_sampler_ycbcr_conversion

#ifdef VK_KHR_bind_memory2
       device_table->vkBindBufferMemory2KHR = (PFN_vkBindBufferMemory2KHR)load(device, "vkBindBufferMemory2KHR");
       device_table->vkBindImageMemory2KHR = (PFN_vkBindImageMemory2KHR)load(device, "vkBindImageMemory2KHR");
#endif //VK_KHR_bind_memory2

#ifdef VK_KHR_maintenance3
       device_table->vkGetDescriptorSetLayoutSupportKHR = (PFN_vkGetDescriptorSetLayoutSupportKHR)load(device, "vkGetDescriptorSetLayoutSupportKHR");
#endif //VK_KHR_maintenance3

#ifdef VK_KHR_draw_indirect_count
       device_table->vkCmdDrawIndirectCountKHR = (PFN_vkCmdDrawIndirectCountKHR)load(device, "vkCmdDrawIndirectCountKHR");
       device_table->vkCmdDrawIndexedIndirectCountKHR = (PFN_vkCmdDrawIndexedIndirectCountKHR)load(device, "vkCmdDrawIndexedIndirectCountKHR");
#endif //VK_KHR_draw_indirect_count

#ifdef VK_KHR_timeline_semaphore
       device_table->vkGetSemaphoreCounterValueKHR = (PFN_vkGetSemaphoreCounterValueKHR)load(device, "vkGetSemaphoreCounterValueKHR");
       device_table->vkWaitSemaphoresKHR = (PFN_vkWaitSemaphoresKHR)load(device, "vkWaitSemaphoresKHR");
       device_table->vkSignalSemaphoreKHR = (PFN_vkSignalSemaphoreKHR)load(device, "vkSignalSemaphoreKHR");
#endif //VK_KHR_timeline_semaphore

#ifdef VK_KHR_buffer_device_address
       device_table->vkGetBufferDeviceAddressKHR = (PFN_vkGetBufferDeviceAddressKHR)load(device, "vkGetBufferDeviceAddressKHR");
       device_table->vkGetBufferOpaqueCaptureAddressKHR = (PFN_vkGetBufferOpaqueCaptureAddressKHR)load(device, "vkGetBufferOpaqueCaptureAddressKHR");
       device_table->vkGetDeviceMemoryOpaqueCaptureAddressKHR = (PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR)load(device, "vkGetDeviceMemoryOpaqueCaptureAddressKHR");
#endif //VK_KHR_buffer_device_address

#ifdef VK_KHR_pipeline_executable_properties
       device_table->vkGetPipelineExecutablePropertiesKHR = (PFN_vkGetPipelineExecutablePropertiesKHR)load(device, "vkGetPipelineExecutablePropertiesKHR");
       device_table->vkGetPipelineExecutableStatisticsKHR = (PFN_vkGetPipelineExecutableStatisticsKHR)load(device, "vkGetPipelineExecutableStatisticsKHR");
       device_table->vkGetPipelineExecutableInternalRepresentationsKHR = (PFN_vkGetPipelineExecutableInternalRepresentationsKHR)load(device, "vkGetPipelineExecutableInternalRepresentationsKHR");
#endif //VK_KHR_pipeline_executable_properties

#ifdef VK_EXT_debug_marker
       device_table->vkDebugMarkerSetObjectTagEXT = (PFN_vkDebugMarkerSetObjectTagEXT)load(device, "vkDebugMarkerSetObjectTagEXT");
       device_table->vkDebugMarkerSetObjectNameEXT = (PFN_vkDebugMarkerSetObjectNameEXT)load(device, "vkDebugMarkerSetObjectNameEXT");
       device_table->vkCmdDebugMarkerBeginEXT = (PFN_vkCmdDebugMarkerBeginEXT)load(device, "vkCmdDebugMarkerBeginEXT");
       device_table->vkCmdDebugMarkerEndEXT = (PFN_vkCmdDebugMarkerEndEXT)load(device, "vkCmdDebugMarkerEndEXT");
       device_table->vkCmdDebugMarkerInsertEXT = (PFN_vkCmdDebugMarkerInsertEXT)load(device, "vkCmdDebugMarkerInsertEXT");
#endif //VK_EXT_debug_marker

#ifdef VK_EXT_transform_feedback
       device_table->vkCmdBindTransformFeedbackBuffersEXT = (PFN_vkCmdBindTransformFeedbackBuffersEXT)load(device, "vkCmdBindTransformFeedbackBuffersEXT");
       device_table->vkCmdBeginTransformFeedbackEXT = (PFN_vkCmdBeginTransformFeedbackEXT)load(device, "vkCmdBeginTransformFeedbackEXT");
       device_table->vkCmdEndTransformFeedbackEXT = (PFN_vkCmdEndTransformFeedbackEXT)load(device, "vkCmdEndTransformFeedbackEXT");
       device_table->vkCmdBeginQueryIndexedEXT = (PFN_vkCmdBeginQueryIndexedEXT)load(device, "vkCmdBeginQueryIndexedEXT");
       device_table->vkCmdEndQueryIndexedEXT = (PFN_vkCmdEndQueryIndexedEXT)load(device, "vkCmdEndQueryIndexedEXT");
       device_table->vkCmdDrawIndirectByteCountEXT = (PFN_vkCmdDrawIndirectByteCountEXT)load(device, "vkCmdDrawIndirectByteCountEXT");
#endif //VK_EXT_transform_feedback

#ifdef VK_NVX_image_view_handle
       device_table->vkGetImageViewHandleNVX = (PFN_vkGetImageViewHandleNVX)load(device, "vkGetImageViewHandleNVX");
#endif //VK_NVX_image_view_handle

#ifdef VK_AMD_draw_indirect_count
       device_table->vkCmdDrawIndirectCountAMD = (PFN_vkCmdDrawIndirectCountAMD)load(device, "vkCmdDrawIndirectCountAMD");
       device_table->vkCmdDrawIndexedIndirectCountAMD = (PFN_vkCmdDrawIndexedIndirectCountAMD)load(device, "vkCmdDrawIndexedIndirectCountAMD");
#endif //VK_AMD_draw_indirect_count

#ifdef VK_AMD_shader_info
       device_table->vkGetShaderInfoAMD = (PFN_vkGetShaderInfoAMD)load(device, "vkGetShaderInfoAMD");
#endif //VK_AMD_shader_info

#ifdef VK_EXT_conditional_rendering
       device_table->vkCmdBeginConditionalRenderingEXT = (PFN_vkCmdBeginConditionalRenderingEXT)load(device, "vkCmdBeginConditionalRenderingEXT");
       device_table->vkCmdEndConditionalRenderingEXT = (PFN_vkCmdEndConditionalRenderingEXT)load(device, "vkCmdEndConditionalRenderingEXT");
#endif //VK_EXT_conditional_rendering

#ifdef VK_NV_clip_space_w_scaling
       device_table->vkCmdSetViewportWScalingNV = (PFN_vkCmdSetViewportWScalingNV)load(device, "vkCmdSetViewportWScalingNV");
#endif //VK_NV_clip_space_w_scaling

#ifdef VK_EXT_display_control
       device_table->vkDisplayPowerControlEXT = (PFN_vkDisplayPowerControlEXT)load(device, "vkDisplayPowerControlEXT");
       device_table->vkRegisterDeviceEventEXT = (PFN_vkRegisterDeviceEventEXT)load(device, "vkRegisterDeviceEventEXT");
       device_table->vkRegisterDisplayEventEXT = (PFN_vkRegisterDisplayEventEXT)load(device, "vkRegisterDisplayEventEXT");
       device_table->vkGetSwapchainCounterEXT = (PFN_vkGetSwapchainCounterEXT)load(device, "vkGetSwapchainCounterEXT");
#endif //VK_EXT_display_control

#ifdef VK_GOOGLE_display_timing
       device_table->vkGetRefreshCycleDurationGOOGLE = (PFN_vkGetRefreshCycleDurationGOOGLE)load(device, "vkGetRefreshCycleDurationGOOGLE");
       device_table->vkGetPastPresentationTimingGOOGLE = (PFN_vkGetPastPresentationTimingGOOGLE)load(device, "vkGetPastPresentationTimingGOOGLE");
#endif //VK_GOOGLE_display_timing

#ifdef VK_EXT_discard_rectangles
       device_table->vkCmdSetDiscardRectangleEXT = (PFN_vkCmdSetDiscardRectangleEXT)load(device, "vkCmdSetDiscardRectangleEXT");
#endif //VK_EXT_discard_rectangles

#ifdef VK_EXT_hdr_metadata
       device_table->vkSetHdrMetadataEXT = (PFN_vkSetHdrMetadataEXT)load(device, "vkSetHdrMetadataEXT");
#endif //VK_EXT_hdr_metadata

#ifdef VK_EXT_debug_utils
       device_table->vkSetDebugUtilsObjectNameEXT = (PFN_vkSetDebugUtilsObjectNameEXT)load(device, "vkSetDebugUtilsObjectNameEXT");
       device_table->vkSetDebugUtilsObjectTagEXT = (PFN_vkSetDebugUtilsObjectTagEXT)load(device, "vkSetDebugUtilsObjectTagEXT");
       device_table->vkQueueBeginDebugUtilsLabelEXT = (PFN_vkQueueBeginDebugUtilsLabelEXT)load(device, "vkQueueBeginDebugUtilsLabelEXT");
       device_table->vkQueueEndDebugUtilsLabelEXT = (PFN_vkQueueEndDebugUtilsLabelEXT)load(device, "vkQueueEndDebugUtilsLabelEXT");
       device_table->vkQueueInsertDebugUtilsLabelEXT = (PFN_vkQueueInsertDebugUtilsLabelEXT)load(device, "vkQueueInsertDebugUtilsLabelEXT");
       device_table->vkCmdBeginDebugUtilsLabelEXT = (PFN_vkCmdBeginDebugUtilsLabelEXT)load(device, "vkCmdBeginDebugUtilsLabelEXT");
       device_table->vkCmdEndDebugUtilsLabelEXT = (PFN_vkCmdEndDebugUtilsLabelEXT)load(device, "vkCmdEndDebugUtilsLabelEXT");
       device_table->vkCmdInsertDebugUtilsLabelEXT = (PFN_vkCmdInsertDebugUtilsLabelEXT)load(device, "vkCmdInsertDebugUtilsLabelEXT");
#endif //VK_EXT_debug_utils

#ifdef VK_EXT_sample_locations
       device_table->vkCmdSetSampleLocationsEXT = (PFN_vkCmdSetSampleLocationsEXT)load(device, "vkCmdSetSampleLocationsEXT");
#endif //VK_EXT_sample_locations

#ifdef VK_EXT_image_drm_format_modifier
       device_table->vkGetImageDrmFormatModifierPropertiesEXT = (PFN_vkGetImageDrmFormatModifierPropertiesEXT)load(device, "vkGetImageDrmFormatModifierPropertiesEXT");
#endif //VK_EXT_image_drm_format_modifier

#ifdef VK_EXT_validation_cache
       device_table->vkCreateValidationCacheEXT = (PFN_vkCreateValidationCacheEXT)load(device, "vkCreateValidationCacheEXT");
       device_table->vkDestroyValidationCacheEXT = (PFN_vkDestroyValidationCacheEXT)load(device, "vkDestroyValidationCacheEXT");
       device_table->vkMergeValidationCachesEXT = (PFN_vkMergeValidationCachesEXT)load(device, "vkMergeValidationCachesEXT");
       device_table->vkGetValidationCacheDataEXT = (PFN_vkGetValidationCacheDataEXT)load(device, "vkGetValidationCacheDataEXT");
#endif //VK_EXT_validation_cache

#ifdef VK_NV_shading_rate_image
       device_table->vkCmdBindShadingRateImageNV = (PFN_vkCmdBindShadingRateImageNV)load(device, "vkCmdBindShadingRateImageNV");
       device_table->vkCmdSetViewportShadingRatePaletteNV = (PFN_vkCmdSetViewportShadingRatePaletteNV)load(device, "vkCmdSetViewportShadingRatePaletteNV");
       device_table->vkCmdSetCoarseSampleOrderNV = (PFN_vkCmdSetCoarseSampleOrderNV)load(device, "vkCmdSetCoarseSampleOrderNV");
#endif //VK_NV_shading_rate_image

#ifdef VK_NV_ray_tracing
       device_table->vkCreateAccelerationStructureNV = (PFN_vkCreateAccelerationStructureNV)load(device, "vkCreateAccelerationStructureNV");
       device_table->vkDestroyAccelerationStructureKHR = (PFN_vkDestroyAccelerationStructureKHR)load(device, "vkDestroyAccelerationStructureKHR");
       device_table->vkDestroyAccelerationStructureNV = (PFN_vkDestroyAccelerationStructureNV)load(device, "vkDestroyAccelerationStructureNV");
       device_table->vkGetAccelerationStructureMemoryRequirementsNV = (PFN_vkGetAccelerationStructureMemoryRequirementsNV)load(device, "vkGetAccelerationStructureMemoryRequirementsNV");
       device_table->vkBindAccelerationStructureMemoryKHR = (PFN_vkBindAccelerationStructureMemoryKHR)load(device, "vkBindAccelerationStructureMemoryKHR");
       device_table->vkBindAccelerationStructureMemoryNV = (PFN_vkBindAccelerationStructureMemoryNV)load(device, "vkBindAccelerationStructureMemoryNV");
       device_table->vkCmdBuildAccelerationStructureNV = (PFN_vkCmdBuildAccelerationStructureNV)load(device, "vkCmdBuildAccelerationStructureNV");
       device_table->vkCmdCopyAccelerationStructureNV = (PFN_vkCmdCopyAccelerationStructureNV)load(device, "vkCmdCopyAccelerationStructureNV");
       device_table->vkCmdTraceRaysNV = (PFN_vkCmdTraceRaysNV)load(device, "vkCmdTraceRaysNV");
       device_table->vkCreateRayTracingPipelinesNV = (PFN_vkCreateRayTracingPipelinesNV)load(device, "vkCreateRayTracingPipelinesNV");
       device_table->vkGetRayTracingShaderGroupHandlesKHR = (PFN_vkGetRayTracingShaderGroupHandlesKHR)load(device, "vkGetRayTracingShaderGroupHandlesKHR");
       device_table->vkGetRayTracingShaderGroupHandlesNV = (PFN_vkGetRayTracingShaderGroupHandlesNV)load(device, "vkGetRayTracingShaderGroupHandlesNV");
       device_table->vkGetAccelerationStructureHandleNV = (PFN_vkGetAccelerationStructureHandleNV)load(device, "vkGetAccelerationStructureHandleNV");
       device_table->vkCmdWriteAccelerationStructuresPropertiesKHR = (PFN_vkCmdWriteAccelerationStructuresPropertiesKHR)load(device, "vkCmdWriteAccelerationStructuresPropertiesKHR");
       device_table->vkCmdWriteAccelerationStructuresPropertiesNV = (PFN_vkCmdWriteAccelerationStructuresPropertiesNV)load(device, "vkCmdWriteAccelerationStructuresPropertiesNV");
       device_table->vkCompileDeferredNV = (PFN_vkCompileDeferredNV)load(device, "vkCompileDeferredNV");
#endif //VK_NV_ray_tracing

#ifdef VK_EXT_external_memory_host
       device_table->vkGetMemoryHostPointerPropertiesEXT = (PFN_vkGetMemoryHostPointerPropertiesEXT)load(device, "vkGetMemoryHostPointerPropertiesEXT");
#endif //VK_EXT_external_memory_host

#ifdef VK_AMD_buffer_marker
       device_table->vkCmdWriteBufferMarkerAMD = (PFN_vkCmdWriteBufferMarkerAMD)load(device, "vkCmdWriteBufferMarkerAMD");
#endif //VK_AMD_buffer_marker

#ifdef VK_EXT_calibrated_timestamps
       device_table->vkGetCalibratedTimestampsEXT = (PFN_vkGetCalibratedTimestampsEXT)load(device, "vkGetCalibratedTimestampsEXT");
#endif //VK_EXT_calibrated_timestamps

#ifdef VK_NV_mesh_shader
       device_table->vkCmdDrawMeshTasksNV = (PFN_vkCmdDrawMeshTasksNV)load(device, "vkCmdDrawMeshTasksNV");
       device_table->vkCmdDrawMeshTasksIndirectNV = (PFN_vkCmdDrawMeshTasksIndirectNV)load(device, "vkCmdDrawMeshTasksIndirectNV");
       device_table->vkCmdDrawMeshTasksIndirectCountNV = (PFN_vkCmdDrawMeshTasksIndirectCountNV)load(device, "vkCmdDrawMeshTasksIndirectCountNV");
#endif //VK_NV_mesh_shader

#ifdef VK_NV_scissor_exclusive
       device_table->vkCmdSetExclusiveScissorNV = (PFN_vkCmdSetExclusiveScissorNV)load(device, "vkCmdSetExclusiveScissorNV");
#endif //VK_NV_scissor_exclusive

#ifdef VK_NV_device_diagnostic_checkpoints
       device_table->vkCmdSetCheckpointNV = (PFN_vkCmdSetCheckpointNV)load(device, "vkCmdSetCheckpointNV");
       device_table->vkGetQueueCheckpointDataNV = (PFN_vkGetQueueCheckpointDataNV)load(device, "vkGetQueueCheckpointDataNV");
#endif //VK_NV_device_diagnostic_checkpoints

#ifdef VK_INTEL_performance_query
       device_table->vkInitializePerformanceApiINTEL = (PFN_vkInitializePerformanceApiINTEL)load(device, "vkInitializePerformanceApiINTEL");
       device_table->vkUninitializePerformanceApiINTEL = (PFN_vkUninitializePerformanceApiINTEL)load(device, "vkUninitializePerformanceApiINTEL");
       device_table->vkCmdSetPerformanceMarkerINTEL = (PFN_vkCmdSetPerformanceMarkerINTEL)load(device, "vkCmdSetPerformanceMarkerINTEL");
       device_table->vkCmdSetPerformanceStreamMarkerINTEL = (PFN_vkCmdSetPerformanceStreamMarkerINTEL)load(device, "vkCmdSetPerformanceStreamMarkerINTEL");
       device_table->vkCmdSetPerformanceOverrideINTEL = (PFN_vkCmdSetPerformanceOverrideINTEL)load(device, "vkCmdSetPerformanceOverrideINTEL");
       device_table->vkAcquirePerformanceConfigurationINTEL = (PFN_vkAcquirePerformanceConfigurationINTEL)load(device, "vkAcquirePerformanceConfigurationINTEL");
       device_table->vkReleasePerformanceConfigurationINTEL = (PFN_vkReleasePerformanceConfigurationINTEL)load(device, "vkReleasePerformanceConfigurationINTEL");
       device_table->vkQueueSetPerformanceConfigurationINTEL = (PFN_vkQueueSetPerformanceConfigurationINTEL)load(device, "vkQueueSetPerformanceConfigurationINTEL");
       device_table->vkGetPerformanceParameterINTEL = (PFN_vkGetPerformanceParameterINTEL)load(device, "vkGetPerformanceParameterINTEL");
#endif //VK_INTEL_performance_query

#ifdef VK_AMD_display_native_hdr
       device_table->vkSetLocalDimmingAMD = (PFN_vkSetLocalDimmingAMD)load(device, "vkSetLocalDimmingAMD");
#endif //VK_AMD_display_native_hdr

#ifdef VK_EXT_buffer_device_address
       device_table->vkGetBufferDeviceAddressEXT = (PFN_vkGetBufferDeviceAddressEXT)load(device, "vkGetBufferDeviceAddressEXT");
#endif //VK_EXT_buffer_device_address

#ifdef VK_EXT_line_rasterization
       device_table->vkCmdSetLineStippleEXT = (PFN_vkCmdSetLineStippleEXT)load(device, "vkCmdSetLineStippleEXT");
#endif //VK_EXT_line_rasterization

#ifdef VK_EXT_host_query_reset
       device_table->vkResetQueryPoolEXT = (PFN_vkResetQueryPoolEXT)load(device, "vkResetQueryPoolEXT");
#endif //VK_EXT_host_query_reset

#ifdef VK_NV_device_generated_commands
       device_table->vkGetGeneratedCommandsMemoryRequirementsNV = (PFN_vkGetGeneratedCommandsMemoryRequirementsNV)load(device, "vkGetGeneratedCommandsMemoryRequirementsNV");
       device_table->vkCmdPreprocessGeneratedCommandsNV = (PFN_vkCmdPreprocessGeneratedCommandsNV)load(device, "vkCmdPreprocessGeneratedCommandsNV");
       device_table->vkCmdExecuteGeneratedCommandsNV = (PFN_vkCmdExecuteGeneratedCommandsNV)load(device, "vkCmdExecuteGeneratedCommandsNV");
       device_table->vkCmdBindPipelineShaderGroupNV = (PFN_vkCmdBindPipelineShaderGroupNV)load(device, "vkCmdBindPipelineShaderGroupNV");
       device_table->vkCreateIndirectCommandsLayoutNV = (PFN_vkCreateIndirectCommandsLayoutNV)load(device, "vkCreateIndirectCommandsLayoutNV");
       device_table->vkDestroyIndirectCommandsLayoutNV = (PFN_vkDestroyIndirectCommandsLayoutNV)load(device, "vkDestroyIndirectCommandsLayoutNV");
#endif //VK_NV_device_generated_commands
}
