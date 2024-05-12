#ifndef VulkanLibrary_H
#define VulkanLibrary_H
#include "vulkan/vulkan_core.h"
#include <SDL_vulkan.h>
#include <vector>
#include "../exception/SDLException.h"
class VulkanLibrary
{
   public:
    /**
     * VulkanLibrary constructor
     */
    explicit VulkanLibrary(const char *path = nullptr);

    /**
     * Desctructor
     */
    ~VulkanLibrary();
    /**
     * return PFN_vkGetInstanceProcAddr
     */
    [[nodiscard]] const PFN_vkGetInstanceProcAddr
    get_instance_proc_addr();

    [[nodiscard]] const char *const *
    get_instance_extensions();
};
#endif  // !VulkanLibrary_H
