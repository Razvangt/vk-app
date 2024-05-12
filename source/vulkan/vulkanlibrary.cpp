#include "VulkanLibrary.h"
#include <vector>
#include "SDL_stdinc.h"
#include "SDL_vulkan.h"
#include "vulkan/vulkan_core.h"

VulkanLibrary::VulkanLibrary(const char *path)
{
    if (const int error_code = SDL_Vulkan_LoadLibrary(path)) {
        throw SDLException{SDL_GetError(), error_code};
    }
}

VulkanLibrary::~VulkanLibrary()
{
    SDL_Vulkan_UnloadLibrary();
}

const PFN_vkGetInstanceProcAddr
VulkanLibrary::get_instance_proc_addr()
{
    if (const auto get_instance_proc_addr =
            reinterpret_cast<PFN_vkGetInstanceProcAddr>(
                SDL_Vulkan_GetVkGetInstanceProcAddr())) {
        return get_instance_proc_addr;
    } else {
        throw SDLException{
            "Couldnt Load vkGetInstanceProcAddr function from the "
            "vulkan dynamic library "};
    }
}

// UNA LISTA DE NOMBRES DE Extension
const char *const *
VulkanLibrary::get_instance_extensions()
{
    uint32_t count_instance_extensions;

    const char *const *instance_extensions = SDL_Vulkan_GetInstanceExtensions(
        &count_instance_extensions);

    if (instance_extensions == NULL) {
        throw SDLException{"Couldn't get vulkan instance extensions count"};
    }
    return instance_extensions;
}
