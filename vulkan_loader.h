#ifndef __VULKAN_LOADER_H__
#define __VULKAN_LOADER_H__

#ifdef VULKAN_H_
#ifndef VK_NO_PROTOTYPES
#error "To use a dynamic loader, yout must define VK_NO_PROTOTYPES before include the main vulkan header"
#endif //!VK_NO_PROTOTYPES
#else
#define VK_NO_PROTOTYPES
#include <vulkan/vulkan.h>
#endif //VULKAN_H_

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

       typedef struct VklMasterTable
       {
#ifdef VK_VERSION_1_0
              PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
              PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties;
              PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
              PFN_vkCreateInstance vkCreateInstance;
#endif //VK_VERSION_1_0

#ifdef VK_VERSION_1_1
              PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion;
#endif //VK_VERSION_1_1
       } VklMasterTable;

       typedef struct VklInstanceTable
       {
#ifdef VK_VERSION_1_0
              PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;
              PFN_vkDestroyInstance vkDestroyInstance;
              PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices;
              PFN_vkGetPhysicalDeviceFeatures vkGetPhysicalDeviceFeatures;
              PFN_vkGetPhysicalDeviceFormatProperties vkGetPhysicalDeviceFormatProperties;
              PFN_vkGetPhysicalDeviceImageFormatProperties vkGetPhysicalDeviceImageFormatProperties;
              PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties;
              PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties;
              PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties;
              PFN_vkCreateDevice vkCreateDevice;
              PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties;
              PFN_vkEnumerateDeviceExtensionProperties vkEnumerateDeviceExtensionProperties;
              PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
              PFN_vkEnumerateDeviceLayerProperties vkEnumerateDeviceLayerProperties;
              PFN_vkGetPhysicalDeviceSparseImageFormatProperties vkGetPhysicalDeviceSparseImageFormatProperties;
#endif //VK_VERSION_1_0

#ifdef VK_VERSION_1_1
              PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion;
              PFN_vkEnumeratePhysicalDeviceGroups vkEnumeratePhysicalDeviceGroups;
              PFN_vkGetPhysicalDeviceFeatures2 vkGetPhysicalDeviceFeatures2;
              PFN_vkGetPhysicalDeviceProperties2 vkGetPhysicalDeviceProperties2;
              PFN_vkGetPhysicalDeviceFormatProperties2 vkGetPhysicalDeviceFormatProperties2;
              PFN_vkGetPhysicalDeviceImageFormatProperties2 vkGetPhysicalDeviceImageFormatProperties2;
              PFN_vkGetPhysicalDeviceQueueFamilyProperties2 vkGetPhysicalDeviceQueueFamilyProperties2;
              PFN_vkGetPhysicalDeviceMemoryProperties2 vkGetPhysicalDeviceMemoryProperties2;
              PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 vkGetPhysicalDeviceSparseImageFormatProperties2;
              PFN_vkGetPhysicalDeviceExternalBufferProperties vkGetPhysicalDeviceExternalBufferProperties;
              PFN_vkGetPhysicalDeviceExternalFenceProperties vkGetPhysicalDeviceExternalFenceProperties;
              PFN_vkGetPhysicalDeviceExternalSemaphoreProperties vkGetPhysicalDeviceExternalSemaphoreProperties;
#endif //VK_VERSION_1_1

#ifdef VK_KHR_surface
              PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR;
              PFN_vkGetPhysicalDeviceSurfaceSupportKHR vkGetPhysicalDeviceSurfaceSupportKHR;
              PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
              PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vkGetPhysicalDeviceSurfaceFormatsKHR;
              PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vkGetPhysicalDeviceSurfacePresentModesKHR;
#endif //VK_KHR_surface

#ifdef VK_KHR_swapchain
              PFN_vkGetPhysicalDevicePresentRectanglesKHR vkGetPhysicalDevicePresentRectanglesKHR;
#endif //VK_KHR_swapchain

#ifdef VK_KHR_display
              PFN_vkGetPhysicalDeviceDisplayPropertiesKHR vkGetPhysicalDeviceDisplayPropertiesKHR;
              PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
              PFN_vkGetDisplayPlaneSupportedDisplaysKHR vkGetDisplayPlaneSupportedDisplaysKHR;
              PFN_vkGetDisplayModePropertiesKHR vkGetDisplayModePropertiesKHR;
              PFN_vkCreateDisplayModeKHR vkCreateDisplayModeKHR;
              PFN_vkGetDisplayPlaneCapabilitiesKHR vkGetDisplayPlaneCapabilitiesKHR;
              PFN_vkCreateDisplayPlaneSurfaceKHR vkCreateDisplayPlaneSurfaceKHR;
#endif //VK_KHR_display

#ifdef VK_KHR_get_physical_device_properties2
              PFN_vkGetPhysicalDeviceFeatures2KHR vkGetPhysicalDeviceFeatures2KHR;
              PFN_vkGetPhysicalDeviceProperties2KHR vkGetPhysicalDeviceProperties2KHR;
              PFN_vkGetPhysicalDeviceFormatProperties2KHR vkGetPhysicalDeviceFormatProperties2KHR;
              PFN_vkGetPhysicalDeviceImageFormatProperties2KHR vkGetPhysicalDeviceImageFormatProperties2KHR;
              PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR vkGetPhysicalDeviceQueueFamilyProperties2KHR;
              PFN_vkGetPhysicalDeviceMemoryProperties2KHR vkGetPhysicalDeviceMemoryProperties2KHR;
              PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR vkGetPhysicalDeviceSparseImageFormatProperties2KHR;
#endif //VK_KHR_get_physical_device_properties2

#ifdef VK_KHR_device_group_creation
              PFN_vkEnumeratePhysicalDeviceGroupsKHR vkEnumeratePhysicalDeviceGroupsKHR;
#endif //VK_KHR_device_group_creation

#ifdef VK_KHR_external_memory_capabilities
              PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR vkGetPhysicalDeviceExternalBufferPropertiesKHR;
#endif //VK_KHR_external_memory_capabilities

#ifdef VK_KHR_external_semaphore_capabilities
              PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR vkGetPhysicalDeviceExternalSemaphorePropertiesKHR;
#endif //VK_KHR_external_semaphore_capabilities

#ifdef VK_KHR_external_fence_capabilities
              PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR vkGetPhysicalDeviceExternalFencePropertiesKHR;
#endif //VK_KHR_external_fence_capabilities

#ifdef VK_KHR_performance_query
              PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR;
              PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR;
#endif //VK_KHR_performance_query

#ifdef VK_KHR_get_surface_capabilities2
              PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR vkGetPhysicalDeviceSurfaceCapabilities2KHR;
              PFN_vkGetPhysicalDeviceSurfaceFormats2KHR vkGetPhysicalDeviceSurfaceFormats2KHR;
#endif //VK_KHR_get_surface_capabilities2

#ifdef VK_KHR_get_display_properties2
              PFN_vkGetPhysicalDeviceDisplayProperties2KHR vkGetPhysicalDeviceDisplayProperties2KHR;
              PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR vkGetPhysicalDeviceDisplayPlaneProperties2KHR;
              PFN_vkGetDisplayModeProperties2KHR vkGetDisplayModeProperties2KHR;
              PFN_vkGetDisplayPlaneCapabilities2KHR vkGetDisplayPlaneCapabilities2KHR;
#endif //VK_KHR_get_display_properties2

#ifdef VK_EXT_debug_report
              PFN_vkDebugReportCallbackEXT vkDebugReportCallbackEXT;
              PFN_vkCreateDebugReportCallbackEXT vkCreateDebugReportCallbackEXT;
              PFN_vkDestroyDebugReportCallbackEXT vkDestroyDebugReportCallbackEXT;
              PFN_vkDebugReportMessageEXT vkDebugReportMessageEXT;
#endif //VK_EXT_debug_report

#ifdef VK_NV_external_memory_capabilities
              PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV vkGetPhysicalDeviceExternalImageFormatPropertiesNV;
#endif //VK_NV_external_memory_capabilities

#ifdef VK_EXT_direct_mode_display
              PFN_vkReleaseDisplayEXT vkReleaseDisplayEXT;
#endif //VK_EXT_direct_mode_display

#ifdef VK_EXT_display_surface_counter
              PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT vkGetPhysicalDeviceSurfaceCapabilities2EXT;
#endif //VK_EXT_display_surface_counter

#ifdef VK_EXT_debug_utils
              PFN_vkDebugUtilsMessengerCallbackEXT vkDebugUtilsMessengerCallbackEXT;
              PFN_vkCreateDebugUtilsMessengerEXT vkCreateDebugUtilsMessengerEXT;
              PFN_vkDestroyDebugUtilsMessengerEXT vkDestroyDebugUtilsMessengerEXT;
              PFN_vkSubmitDebugUtilsMessageEXT vkSubmitDebugUtilsMessageEXT;
#endif //VK_EXT_debug_utils

#ifdef VK_EXT_sample_locations
              PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT vkGetPhysicalDeviceMultisamplePropertiesEXT;
#endif //VK_EXT_sample_locations

#ifdef VK_EXT_calibrated_timestamps
              PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT vkGetPhysicalDeviceCalibrateableTimeDomainsEXT;
#endif //VK_EXT_calibrated_timestamps

#ifdef VK_EXT_tooling_info
              PFN_vkGetPhysicalDeviceToolPropertiesEXT vkGetPhysicalDeviceToolPropertiesEXT;
#endif //VK_EXT_tooling_info

#ifdef VK_NV_cooperative_matrix
              PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV vkGetPhysicalDeviceCooperativeMatrixPropertiesNV;
#endif //VK_NV_cooperative_matrix

#ifdef VK_NV_coverage_reduction_mode
              PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV;
#endif //VK_NV_coverage_reduction_mode

#ifdef VK_EXT_headless_surface
              PFN_vkCreateHeadlessSurfaceEXT vkCreateHeadlessSurfaceEXT;
#endif //VK_EXT_headless_surface
       } VklInstanceTable;

       typedef struct VklDeviceTable
       {
#ifdef VK_VERSION_1_0
              PFN_vkDestroyDevice vkDestroyDevice;
              PFN_vkGetDeviceQueue vkGetDeviceQueue;
              PFN_vkQueueSubmit vkQueueSubmit;
              PFN_vkQueueWaitIdle vkQueueWaitIdle;
              PFN_vkDeviceWaitIdle vkDeviceWaitIdle;
              PFN_vkAllocateMemory vkAllocateMemory;
              PFN_vkFreeMemory vkFreeMemory;
              PFN_vkMapMemory vkMapMemory;
              PFN_vkUnmapMemory vkUnmapMemory;
              PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges;
              PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges;
              PFN_vkGetDeviceMemoryCommitment vkGetDeviceMemoryCommitment;
              PFN_vkBindBufferMemory vkBindBufferMemory;
              PFN_vkBindImageMemory vkBindImageMemory;
              PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements;
              PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements;
              PFN_vkGetImageSparseMemoryRequirements vkGetImageSparseMemoryRequirements;
              PFN_vkQueueBindSparse vkQueueBindSparse;
              PFN_vkCreateFence vkCreateFence;
              PFN_vkDestroyFence vkDestroyFence;
              PFN_vkResetFences vkResetFences;
              PFN_vkGetFenceStatus vkGetFenceStatus;
              PFN_vkWaitForFences vkWaitForFences;
              PFN_vkCreateSemaphore vkCreateSemaphore;
              PFN_vkDestroySemaphore vkDestroySemaphore;
              PFN_vkCreateEvent vkCreateEvent;
              PFN_vkDestroyEvent vkDestroyEvent;
              PFN_vkGetEventStatus vkGetEventStatus;
              PFN_vkSetEvent vkSetEvent;
              PFN_vkResetEvent vkResetEvent;
              PFN_vkCreateQueryPool vkCreateQueryPool;
              PFN_vkDestroyQueryPool vkDestroyQueryPool;
              PFN_vkGetQueryPoolResults vkGetQueryPoolResults;
              PFN_vkCreateBuffer vkCreateBuffer;
              PFN_vkDestroyBuffer vkDestroyBuffer;
              PFN_vkCreateBufferView vkCreateBufferView;
              PFN_vkDestroyBufferView vkDestroyBufferView;
              PFN_vkCreateImage vkCreateImage;
              PFN_vkDestroyImage vkDestroyImage;
              PFN_vkGetImageSubresourceLayout vkGetImageSubresourceLayout;
              PFN_vkCreateImageView vkCreateImageView;
              PFN_vkDestroyImageView vkDestroyImageView;
              PFN_vkCreateShaderModule vkCreateShaderModule;
              PFN_vkDestroyShaderModule vkDestroyShaderModule;
              PFN_vkCreatePipelineCache vkCreatePipelineCache;
              PFN_vkDestroyPipelineCache vkDestroyPipelineCache;
              PFN_vkGetPipelineCacheData vkGetPipelineCacheData;
              PFN_vkMergePipelineCaches vkMergePipelineCaches;
              PFN_vkCreateGraphicsPipelines vkCreateGraphicsPipelines;
              PFN_vkCreateComputePipelines vkCreateComputePipelines;
              PFN_vkDestroyPipeline vkDestroyPipeline;
              PFN_vkCreatePipelineLayout vkCreatePipelineLayout;
              PFN_vkDestroyPipelineLayout vkDestroyPipelineLayout;
              PFN_vkCreateSampler vkCreateSampler;
              PFN_vkDestroySampler vkDestroySampler;
              PFN_vkCreateDescriptorSetLayout vkCreateDescriptorSetLayout;
              PFN_vkDestroyDescriptorSetLayout vkDestroyDescriptorSetLayout;
              PFN_vkCreateDescriptorPool vkCreateDescriptorPool;
              PFN_vkDestroyDescriptorPool vkDestroyDescriptorPool;
              PFN_vkResetDescriptorPool vkResetDescriptorPool;
              PFN_vkAllocateDescriptorSets vkAllocateDescriptorSets;
              PFN_vkFreeDescriptorSets vkFreeDescriptorSets;
              PFN_vkUpdateDescriptorSets vkUpdateDescriptorSets;
              PFN_vkCreateFramebuffer vkCreateFramebuffer;
              PFN_vkDestroyFramebuffer vkDestroyFramebuffer;
              PFN_vkCreateRenderPass vkCreateRenderPass;
              PFN_vkDestroyRenderPass vkDestroyRenderPass;
              PFN_vkGetRenderAreaGranularity vkGetRenderAreaGranularity;
              PFN_vkCreateCommandPool vkCreateCommandPool;
              PFN_vkDestroyCommandPool vkDestroyCommandPool;
              PFN_vkResetCommandPool vkResetCommandPool;
              PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers;
              PFN_vkFreeCommandBuffers vkFreeCommandBuffers;
              PFN_vkBeginCommandBuffer vkBeginCommandBuffer;
              PFN_vkEndCommandBuffer vkEndCommandBuffer;
              PFN_vkResetCommandBuffer vkResetCommandBuffer;
              PFN_vkCmdBindPipeline vkCmdBindPipeline;
              PFN_vkCmdSetViewport vkCmdSetViewport;
              PFN_vkCmdSetScissor vkCmdSetScissor;
              PFN_vkCmdSetLineWidth vkCmdSetLineWidth;
              PFN_vkCmdSetDepthBias vkCmdSetDepthBias;
              PFN_vkCmdSetBlendConstants vkCmdSetBlendConstants;
              PFN_vkCmdSetDepthBounds vkCmdSetDepthBounds;
              PFN_vkCmdSetStencilCompareMask vkCmdSetStencilCompareMask;
              PFN_vkCmdSetStencilWriteMask vkCmdSetStencilWriteMask;
              PFN_vkCmdSetStencilReference vkCmdSetStencilReference;
              PFN_vkCmdBindDescriptorSets vkCmdBindDescriptorSets;
              PFN_vkCmdBindIndexBuffer vkCmdBindIndexBuffer;
              PFN_vkCmdBindVertexBuffers vkCmdBindVertexBuffers;
              PFN_vkCmdDraw vkCmdDraw;
              PFN_vkCmdDrawIndexed vkCmdDrawIndexed;
              PFN_vkCmdDrawIndirect vkCmdDrawIndirect;
              PFN_vkCmdDrawIndexedIndirect vkCmdDrawIndexedIndirect;
              PFN_vkCmdDispatch vkCmdDispatch;
              PFN_vkCmdDispatchIndirect vkCmdDispatchIndirect;
              PFN_vkCmdCopyBuffer vkCmdCopyBuffer;
              PFN_vkCmdCopyImage vkCmdCopyImage;
              PFN_vkCmdBlitImage vkCmdBlitImage;
              PFN_vkCmdCopyBufferToImage vkCmdCopyBufferToImage;
              PFN_vkCmdCopyImageToBuffer vkCmdCopyImageToBuffer;
              PFN_vkCmdUpdateBuffer vkCmdUpdateBuffer;
              PFN_vkCmdFillBuffer vkCmdFillBuffer;
              PFN_vkCmdClearColorImage vkCmdClearColorImage;
              PFN_vkCmdClearDepthStencilImage vkCmdClearDepthStencilImage;
              PFN_vkCmdClearAttachments vkCmdClearAttachments;
              PFN_vkCmdResolveImage vkCmdResolveImage;
              PFN_vkCmdSetEvent vkCmdSetEvent;
              PFN_vkCmdResetEvent vkCmdResetEvent;
              PFN_vkCmdWaitEvents vkCmdWaitEvents;
              PFN_vkCmdPipelineBarrier vkCmdPipelineBarrier;
              PFN_vkCmdBeginQuery vkCmdBeginQuery;
              PFN_vkCmdEndQuery vkCmdEndQuery;
              PFN_vkCmdResetQueryPool vkCmdResetQueryPool;
              PFN_vkCmdWriteTimestamp vkCmdWriteTimestamp;
              PFN_vkCmdCopyQueryPoolResults vkCmdCopyQueryPoolResults;
              PFN_vkCmdPushConstants vkCmdPushConstants;
              PFN_vkCmdBeginRenderPass vkCmdBeginRenderPass;
              PFN_vkCmdNextSubpass vkCmdNextSubpass;
              PFN_vkCmdEndRenderPass vkCmdEndRenderPass;
              PFN_vkCmdExecuteCommands vkCmdExecuteCommands;
#endif //VK_VERSION_1_0

#ifdef VK_VERSION_1_1
              PFN_vkBindBufferMemory2 vkBindBufferMemory2;
              PFN_vkBindImageMemory2 vkBindImageMemory2;
              PFN_vkGetDeviceGroupPeerMemoryFeatures vkGetDeviceGroupPeerMemoryFeatures;
              PFN_vkCmdSetDeviceMask vkCmdSetDeviceMask;
              PFN_vkCmdDispatchBase vkCmdDispatchBase;
              PFN_vkGetImageMemoryRequirements2 vkGetImageMemoryRequirements2;
              PFN_vkGetBufferMemoryRequirements2 vkGetBufferMemoryRequirements2;
              PFN_vkGetImageSparseMemoryRequirements2 vkGetImageSparseMemoryRequirements2;
              PFN_vkTrimCommandPool vkTrimCommandPool;
              PFN_vkGetDeviceQueue2 vkGetDeviceQueue2;
              PFN_vkCreateSamplerYcbcrConversion vkCreateSamplerYcbcrConversion;
              PFN_vkDestroySamplerYcbcrConversion vkDestroySamplerYcbcrConversion;
              PFN_vkCreateDescriptorUpdateTemplate vkCreateDescriptorUpdateTemplate;
              PFN_vkDestroyDescriptorUpdateTemplate vkDestroyDescriptorUpdateTemplate;
              PFN_vkUpdateDescriptorSetWithTemplate vkUpdateDescriptorSetWithTemplate;
              PFN_vkGetDescriptorSetLayoutSupport vkGetDescriptorSetLayoutSupport;
#endif //VK_VERSION_1_1

#ifdef VK_VERSION_1_2
              PFN_vkCmdDrawIndirectCount vkCmdDrawIndirectCount;
              PFN_vkCmdDrawIndexedIndirectCount vkCmdDrawIndexedIndirectCount;
              PFN_vkCreateRenderPass2 vkCreateRenderPass2;
              PFN_vkCmdBeginRenderPass2 vkCmdBeginRenderPass2;
              PFN_vkCmdNextSubpass2 vkCmdNextSubpass2;
              PFN_vkCmdEndRenderPass2 vkCmdEndRenderPass2;
              PFN_vkResetQueryPool vkResetQueryPool;
              PFN_vkGetSemaphoreCounterValue vkGetSemaphoreCounterValue;
              PFN_vkWaitSemaphores vkWaitSemaphores;
              PFN_vkSignalSemaphore vkSignalSemaphore;
              PFN_vkGetBufferDeviceAddress vkGetBufferDeviceAddress;
              PFN_vkGetBufferOpaqueCaptureAddress vkGetBufferOpaqueCaptureAddress;
              PFN_vkGetDeviceMemoryOpaqueCaptureAddress vkGetDeviceMemoryOpaqueCaptureAddress;
#endif //VK_VERSION_1_2

#ifdef VK_KHR_swapchain
              PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR;
              PFN_vkDestroySwapchainKHR vkDestroySwapchainKHR;
              PFN_vkGetSwapchainImagesKHR vkGetSwapchainImagesKHR;
              PFN_vkAcquireNextImageKHR vkAcquireNextImageKHR;
              PFN_vkQueuePresentKHR vkQueuePresentKHR;
              PFN_vkGetDeviceGroupPresentCapabilitiesKHR vkGetDeviceGroupPresentCapabilitiesKHR;
              PFN_vkGetDeviceGroupSurfacePresentModesKHR vkGetDeviceGroupSurfacePresentModesKHR;
              PFN_vkAcquireNextImage2KHR vkAcquireNextImage2KHR;
#endif //VK_KHR_swapchain

#ifdef VK_KHR_display_swapchain
              PFN_vkCreateSharedSwapchainsKHR vkCreateSharedSwapchainsKHR;
#endif //VK_KHR_display_swapchain

#ifdef VK_KHR_get_physical_device_properties2
#endif //VK_KHR_get_physical_device_properties2

#ifdef VK_KHR_device_group
              PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR vkGetDeviceGroupPeerMemoryFeaturesKHR;
              PFN_vkCmdSetDeviceMaskKHR vkCmdSetDeviceMaskKHR;
              PFN_vkCmdDispatchBaseKHR vkCmdDispatchBaseKHR;
#endif //VK_KHR_device_group

#ifdef VK_KHR_maintenance1
              PFN_vkTrimCommandPoolKHR vkTrimCommandPoolKHR;
#endif //VK_KHR_maintenance1

#ifdef VK_KHR_external_memory_fd
              PFN_vkGetMemoryFdKHR vkGetMemoryFdKHR;
              PFN_vkGetMemoryFdPropertiesKHR vkGetMemoryFdPropertiesKHR;
#endif //VK_KHR_external_memory_fd

#ifdef VK_KHR_external_semaphore_capabilities
#endif //VK_KHR_external_semaphore_capabilities

#ifdef VK_KHR_external_semaphore_fd
              PFN_vkImportSemaphoreFdKHR vkImportSemaphoreFdKHR;
              PFN_vkGetSemaphoreFdKHR vkGetSemaphoreFdKHR;
#endif //VK_KHR_external_semaphore_fd

#ifdef VK_KHR_push_descriptor
              PFN_vkCmdPushDescriptorSetKHR vkCmdPushDescriptorSetKHR;
              PFN_vkCmdPushDescriptorSetWithTemplateKHR vkCmdPushDescriptorSetWithTemplateKHR;
#endif //VK_KHR_push_descriptor

#ifdef VK_KHR_descriptor_update_template
              PFN_vkCreateDescriptorUpdateTemplateKHR vkCreateDescriptorUpdateTemplateKHR;
              PFN_vkDestroyDescriptorUpdateTemplateKHR vkDestroyDescriptorUpdateTemplateKHR;
              PFN_vkUpdateDescriptorSetWithTemplateKHR vkUpdateDescriptorSetWithTemplateKHR;
#endif //VK_KHR_descriptor_update_template

#ifdef VK_KHR_create_renderpass2
              PFN_vkCreateRenderPass2KHR vkCreateRenderPass2KHR;
              PFN_vkCmdBeginRenderPass2KHR vkCmdBeginRenderPass2KHR;
              PFN_vkCmdNextSubpass2KHR vkCmdNextSubpass2KHR;
              PFN_vkCmdEndRenderPass2KHR vkCmdEndRenderPass2KHR;
#endif //VK_KHR_create_renderpass2

#ifdef VK_KHR_shared_presentable_image
              PFN_vkGetSwapchainStatusKHR vkGetSwapchainStatusKHR;
#endif //VK_KHR_shared_presentable_image

#ifdef VK_KHR_external_fence_fd
              PFN_vkImportFenceFdKHR vkImportFenceFdKHR;
              PFN_vkGetFenceFdKHR vkGetFenceFdKHR;
#endif //VK_KHR_external_fence_fd

#ifdef VK_KHR_performance_query
              PFN_vkAcquireProfilingLockKHR vkAcquireProfilingLockKHR;
              PFN_vkReleaseProfilingLockKHR vkReleaseProfilingLockKHR;
#endif //VK_KHR_performance_query

#ifdef VK_KHR_get_memory_requirements2
              PFN_vkGetImageMemoryRequirements2KHR vkGetImageMemoryRequirements2KHR;
              PFN_vkGetBufferMemoryRequirements2KHR vkGetBufferMemoryRequirements2KHR;
              PFN_vkGetImageSparseMemoryRequirements2KHR vkGetImageSparseMemoryRequirements2KHR;
#endif //VK_KHR_get_memory_requirements2

#ifdef VK_KHR_sampler_ycbcr_conversion
              PFN_vkCreateSamplerYcbcrConversionKHR vkCreateSamplerYcbcrConversionKHR;
              PFN_vkDestroySamplerYcbcrConversionKHR vkDestroySamplerYcbcrConversionKHR;
#endif //VK_KHR_sampler_ycbcr_conversion

#ifdef VK_KHR_bind_memory2
              PFN_vkBindBufferMemory2KHR vkBindBufferMemory2KHR;
              PFN_vkBindImageMemory2KHR vkBindImageMemory2KHR;
#endif //VK_KHR_bind_memory2

#ifdef VK_KHR_maintenance3
              PFN_vkGetDescriptorSetLayoutSupportKHR vkGetDescriptorSetLayoutSupportKHR;
#endif //VK_KHR_maintenance3

#ifdef VK_KHR_draw_indirect_count
              PFN_vkCmdDrawIndirectCountKHR vkCmdDrawIndirectCountKHR;
              PFN_vkCmdDrawIndexedIndirectCountKHR vkCmdDrawIndexedIndirectCountKHR;
#endif //VK_KHR_draw_indirect_count

#ifdef VK_KHR_timeline_semaphore
              PFN_vkGetSemaphoreCounterValueKHR vkGetSemaphoreCounterValueKHR;
              PFN_vkWaitSemaphoresKHR vkWaitSemaphoresKHR;
              PFN_vkSignalSemaphoreKHR vkSignalSemaphoreKHR;
#endif //VK_KHR_timeline_semaphore

#ifdef VK_KHR_buffer_device_address
              PFN_vkGetBufferDeviceAddressKHR vkGetBufferDeviceAddressKHR;
              PFN_vkGetBufferOpaqueCaptureAddressKHR vkGetBufferOpaqueCaptureAddressKHR;
              PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR vkGetDeviceMemoryOpaqueCaptureAddressKHR;
#endif //VK_KHR_buffer_device_address

#ifdef VK_KHR_pipeline_executable_properties
              PFN_vkGetPipelineExecutablePropertiesKHR vkGetPipelineExecutablePropertiesKHR;
              PFN_vkGetPipelineExecutableStatisticsKHR vkGetPipelineExecutableStatisticsKHR;
              PFN_vkGetPipelineExecutableInternalRepresentationsKHR vkGetPipelineExecutableInternalRepresentationsKHR;
#endif //VK_KHR_pipeline_executable_properties

#ifdef VK_EXT_debug_marker
              PFN_vkDebugMarkerSetObjectTagEXT vkDebugMarkerSetObjectTagEXT;
              PFN_vkDebugMarkerSetObjectNameEXT vkDebugMarkerSetObjectNameEXT;
              PFN_vkCmdDebugMarkerBeginEXT vkCmdDebugMarkerBeginEXT;
              PFN_vkCmdDebugMarkerEndEXT vkCmdDebugMarkerEndEXT;
              PFN_vkCmdDebugMarkerInsertEXT vkCmdDebugMarkerInsertEXT;
#endif //VK_EXT_debug_marker

#ifdef VK_EXT_transform_feedback
              PFN_vkCmdBindTransformFeedbackBuffersEXT vkCmdBindTransformFeedbackBuffersEXT;
              PFN_vkCmdBeginTransformFeedbackEXT vkCmdBeginTransformFeedbackEXT;
              PFN_vkCmdEndTransformFeedbackEXT vkCmdEndTransformFeedbackEXT;
              PFN_vkCmdBeginQueryIndexedEXT vkCmdBeginQueryIndexedEXT;
              PFN_vkCmdEndQueryIndexedEXT vkCmdEndQueryIndexedEXT;
              PFN_vkCmdDrawIndirectByteCountEXT vkCmdDrawIndirectByteCountEXT;
#endif //VK_EXT_transform_feedback

#ifdef VK_NVX_image_view_handle
              PFN_vkGetImageViewHandleNVX vkGetImageViewHandleNVX;
#endif //VK_NVX_image_view_handle

#ifdef VK_AMD_draw_indirect_count
              PFN_vkCmdDrawIndirectCountAMD vkCmdDrawIndirectCountAMD;
              PFN_vkCmdDrawIndexedIndirectCountAMD vkCmdDrawIndexedIndirectCountAMD;
#endif //VK_AMD_draw_indirect_count

#ifdef VK_AMD_shader_info
              PFN_vkGetShaderInfoAMD vkGetShaderInfoAMD;
#endif //VK_AMD_shader_info

#ifdef VK_EXT_conditional_rendering
              PFN_vkCmdBeginConditionalRenderingEXT vkCmdBeginConditionalRenderingEXT;
              PFN_vkCmdEndConditionalRenderingEXT vkCmdEndConditionalRenderingEXT;
#endif //VK_EXT_conditional_rendering

#ifdef VK_NV_clip_space_w_scaling
              PFN_vkCmdSetViewportWScalingNV vkCmdSetViewportWScalingNV;
#endif //VK_NV_clip_space_w_scaling

#ifdef VK_EXT_display_control
              PFN_vkDisplayPowerControlEXT vkDisplayPowerControlEXT;
              PFN_vkRegisterDeviceEventEXT vkRegisterDeviceEventEXT;
              PFN_vkRegisterDisplayEventEXT vkRegisterDisplayEventEXT;
              PFN_vkGetSwapchainCounterEXT vkGetSwapchainCounterEXT;
#endif //VK_EXT_display_control

#ifdef VK_GOOGLE_display_timing
              PFN_vkGetRefreshCycleDurationGOOGLE vkGetRefreshCycleDurationGOOGLE;
              PFN_vkGetPastPresentationTimingGOOGLE vkGetPastPresentationTimingGOOGLE;
#endif //VK_GOOGLE_display_timing

#ifdef VK_EXT_discard_rectangles
              PFN_vkCmdSetDiscardRectangleEXT vkCmdSetDiscardRectangleEXT;
#endif //VK_EXT_discard_rectangles

#ifdef VK_EXT_hdr_metadata
              PFN_vkSetHdrMetadataEXT vkSetHdrMetadataEXT;
#endif //VK_EXT_hdr_metadata

#ifdef VK_EXT_debug_utils
              PFN_vkSetDebugUtilsObjectNameEXT vkSetDebugUtilsObjectNameEXT;
              PFN_vkSetDebugUtilsObjectTagEXT vkSetDebugUtilsObjectTagEXT;
              PFN_vkQueueBeginDebugUtilsLabelEXT vkQueueBeginDebugUtilsLabelEXT;
              PFN_vkQueueEndDebugUtilsLabelEXT vkQueueEndDebugUtilsLabelEXT;
              PFN_vkQueueInsertDebugUtilsLabelEXT vkQueueInsertDebugUtilsLabelEXT;
              PFN_vkCmdBeginDebugUtilsLabelEXT vkCmdBeginDebugUtilsLabelEXT;
              PFN_vkCmdEndDebugUtilsLabelEXT vkCmdEndDebugUtilsLabelEXT;
              PFN_vkCmdInsertDebugUtilsLabelEXT vkCmdInsertDebugUtilsLabelEXT;
#endif //VK_EXT_debug_utils

#ifdef VK_EXT_sample_locations
              PFN_vkCmdSetSampleLocationsEXT vkCmdSetSampleLocationsEXT;
#endif //VK_EXT_sample_locations

#ifdef VK_EXT_image_drm_format_modifier
              PFN_vkGetImageDrmFormatModifierPropertiesEXT vkGetImageDrmFormatModifierPropertiesEXT;
#endif //VK_EXT_image_drm_format_modifier

#ifdef VK_EXT_validation_cache
              PFN_vkCreateValidationCacheEXT vkCreateValidationCacheEXT;
              PFN_vkDestroyValidationCacheEXT vkDestroyValidationCacheEXT;
              PFN_vkMergeValidationCachesEXT vkMergeValidationCachesEXT;
              PFN_vkGetValidationCacheDataEXT vkGetValidationCacheDataEXT;
#endif //VK_EXT_validation_cache

#ifdef VK_NV_shading_rate_image
              PFN_vkCmdBindShadingRateImageNV vkCmdBindShadingRateImageNV;
              PFN_vkCmdSetViewportShadingRatePaletteNV vkCmdSetViewportShadingRatePaletteNV;
              PFN_vkCmdSetCoarseSampleOrderNV vkCmdSetCoarseSampleOrderNV;
#endif //VK_NV_shading_rate_image

#ifdef VK_NV_ray_tracing
              PFN_vkCreateAccelerationStructureNV vkCreateAccelerationStructureNV;
              PFN_vkDestroyAccelerationStructureKHR vkDestroyAccelerationStructureKHR;
              PFN_vkDestroyAccelerationStructureNV vkDestroyAccelerationStructureNV;
              PFN_vkGetAccelerationStructureMemoryRequirementsNV vkGetAccelerationStructureMemoryRequirementsNV;
              PFN_vkBindAccelerationStructureMemoryKHR vkBindAccelerationStructureMemoryKHR;
              PFN_vkBindAccelerationStructureMemoryNV vkBindAccelerationStructureMemoryNV;
              PFN_vkCmdBuildAccelerationStructureNV vkCmdBuildAccelerationStructureNV;
              PFN_vkCmdCopyAccelerationStructureNV vkCmdCopyAccelerationStructureNV;
              PFN_vkCmdTraceRaysNV vkCmdTraceRaysNV;
              PFN_vkCreateRayTracingPipelinesNV vkCreateRayTracingPipelinesNV;
              PFN_vkGetRayTracingShaderGroupHandlesKHR vkGetRayTracingShaderGroupHandlesKHR;
              PFN_vkGetRayTracingShaderGroupHandlesNV vkGetRayTracingShaderGroupHandlesNV;
              PFN_vkGetAccelerationStructureHandleNV vkGetAccelerationStructureHandleNV;
              PFN_vkCmdWriteAccelerationStructuresPropertiesKHR vkCmdWriteAccelerationStructuresPropertiesKHR;
              PFN_vkCmdWriteAccelerationStructuresPropertiesNV vkCmdWriteAccelerationStructuresPropertiesNV;
              PFN_vkCompileDeferredNV vkCompileDeferredNV;
#endif //VK_NV_ray_tracing

#ifdef VK_EXT_external_memory_host
              PFN_vkGetMemoryHostPointerPropertiesEXT vkGetMemoryHostPointerPropertiesEXT;
#endif //VK_EXT_external_memory_host

#ifdef VK_AMD_buffer_marker
              PFN_vkCmdWriteBufferMarkerAMD vkCmdWriteBufferMarkerAMD;
#endif //VK_AMD_buffer_marker

#ifdef VK_EXT_calibrated_timestamps
              PFN_vkGetCalibratedTimestampsEXT vkGetCalibratedTimestampsEXT;
#endif //VK_EXT_calibrated_timestamps

#ifdef VK_NV_mesh_shader
              PFN_vkCmdDrawMeshTasksNV vkCmdDrawMeshTasksNV;
              PFN_vkCmdDrawMeshTasksIndirectNV vkCmdDrawMeshTasksIndirectNV;
              PFN_vkCmdDrawMeshTasksIndirectCountNV vkCmdDrawMeshTasksIndirectCountNV;
#endif //VK_NV_mesh_shader

#ifdef VK_NV_scissor_exclusive
              PFN_vkCmdSetExclusiveScissorNV vkCmdSetExclusiveScissorNV;
#endif //VK_NV_scissor_exclusive

#ifdef VK_NV_device_diagnostic_checkpoints
              PFN_vkCmdSetCheckpointNV vkCmdSetCheckpointNV;
              PFN_vkGetQueueCheckpointDataNV vkGetQueueCheckpointDataNV;
#endif //VK_NV_device_diagnostic_checkpoints

#ifdef VK_INTEL_performance_query
              PFN_vkInitializePerformanceApiINTEL vkInitializePerformanceApiINTEL;
              PFN_vkUninitializePerformanceApiINTEL vkUninitializePerformanceApiINTEL;
              PFN_vkCmdSetPerformanceMarkerINTEL vkCmdSetPerformanceMarkerINTEL;
              PFN_vkCmdSetPerformanceStreamMarkerINTEL vkCmdSetPerformanceStreamMarkerINTEL;
              PFN_vkCmdSetPerformanceOverrideINTEL vkCmdSetPerformanceOverrideINTEL;
              PFN_vkAcquirePerformanceConfigurationINTEL vkAcquirePerformanceConfigurationINTEL;
              PFN_vkReleasePerformanceConfigurationINTEL vkReleasePerformanceConfigurationINTEL;
              PFN_vkQueueSetPerformanceConfigurationINTEL vkQueueSetPerformanceConfigurationINTEL;
              PFN_vkGetPerformanceParameterINTEL vkGetPerformanceParameterINTEL;
#endif //VK_INTEL_performance_query

#ifdef VK_AMD_display_native_hdr
              PFN_vkSetLocalDimmingAMD vkSetLocalDimmingAMD;
#endif //VK_AMD_display_native_hdr

#ifdef VK_EXT_buffer_device_address
              PFN_vkGetBufferDeviceAddressEXT vkGetBufferDeviceAddressEXT;
#endif //VK_EXT_buffer_device_address

#ifdef VK_EXT_line_rasterization
              PFN_vkCmdSetLineStippleEXT vkCmdSetLineStippleEXT;
#endif //VK_EXT_line_rasterization

#ifdef VK_EXT_host_query_reset
              PFN_vkResetQueryPoolEXT vkResetQueryPoolEXT;
#endif //VK_EXT_host_query_reset

#ifdef VK_NV_device_generated_commands
              PFN_vkGetGeneratedCommandsMemoryRequirementsNV vkGetGeneratedCommandsMemoryRequirementsNV;
              PFN_vkCmdPreprocessGeneratedCommandsNV vkCmdPreprocessGeneratedCommandsNV;
              PFN_vkCmdExecuteGeneratedCommandsNV vkCmdExecuteGeneratedCommandsNV;
              PFN_vkCmdBindPipelineShaderGroupNV vkCmdBindPipelineShaderGroupNV;
              PFN_vkCreateIndirectCommandsLayoutNV vkCreateIndirectCommandsLayoutNV;
              PFN_vkDestroyIndirectCommandsLayoutNV vkDestroyIndirectCommandsLayoutNV;
#endif //VK_NV_device_generated_commands
       } VklDeviceTable;

       VkResult vklInitVulkan(VklMasterTable* table);

       void vklLoadInstanceTable(VkInstance instance, VklMasterTable* master_table, VklInstanceTable* instance_table);

       void vklLoadDeviceTable(VkDevice device, VklInstanceTable* instance_table, VklDeviceTable* device_table);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //!__VULKAN_LOADER_H__
