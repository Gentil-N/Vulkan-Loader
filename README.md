# Vulkan-Loader
Load vulkan dynamically.

## How to install
Just copy the two files in your project.
- Linux : Add "dl" as dynamic library before compilation.
- (Other platforms are not supported)

## How to use
Inculde "vulkan_loader.h" in required sources files :
```
#include "vulkan_loader.h"
```
Or :
```
#define VK_NO_PROTOTYPES
#include "vulkan/vulkan.h"
#include "vulkan_loader.h"
```
There are three Tables.
 - The "master" table : Must be unique for each process.
 - The "instance" table : Loaded for each instance of vulkan.
 - The "device" table : Loaded for each device created by instance.

## Example
```
#include <iostream>
#include "vulkan_loader.h"

int main()
{
       VklMasterTable master_table;
       if(vklInitVulkan(&master_table) != VK_SUCCESS)
       {
              std::cout << "vulkan is not installed !" << std::endl;
              return 1;
       }
       VkApplicationInfo app_info;
       app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
       app_info.pNext = NULL;
       app_info.pApplicationName = "test";
       app_info.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
       app_info.pEngineName = "none";
       app_info.engineVersion = VK_MAKE_VERSION(0, 0, 0);
       app_info.apiVersion = VK_API_VERSION_1_2;
       VkInstanceCreateInfo instance_info;
       instance_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
       instance_info.pNext = NULL;
       instance_info.flags = 0;
       instance_info.pApplicationInfo = &app_info;
       instance_info.enabledLayerCount = 0;
       instance_info.ppEnabledLayerNames = nullptr;
       instance_info.enabledExtensionCount = 0;
       instance_info.ppEnabledExtensionNames = nullptr;
       VkInstance instance;
       VkResult result = master_table.vkCreateInstance(&instance_info, nullptr, &instance);
       if(result != VK_SUCCESS)
       {
              std::cout << "error : failed to create instance !" << std::endl;
              return 1;
       }
       VklInstanceTable instance_table;
       vklLoadInstanceTable(instance, &master_table, &instance_table);
       if(instance_table.vkDestroyInstance == nullptr)
       {
              std::cout << "error : failed to load function !" << std::endl;
              return 1;
       }
       instance_table.vkDestroyInstance(instance, nullptr);
       return 0;
}
```
