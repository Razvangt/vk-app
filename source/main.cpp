#include "SDL_platform.h"
#include "vulkan/vulkan_core.h"
#include <SDL.h>
#include <SDL_vulkan.h>
#include <cstdint>
#include <cstdlib>
#define VULKAN_HPP_ENABLE_DYNAMIC_LOADER_TOOL 0
#include <vulkan/vulkan_raii.hpp>

#include "sdl/SDLLibrary.h"
#include "vulkan/VulkanLibrary.h"

auto
main(int argc, char *argv[]) -> int
{
    const SDLLibrary sdl{SDL_INIT_VIDEO};
    VulkanLibrary vulkan_library{};

    vk::raii::Context context{vulkan_library.get_instance_proc_addr()};

    vk::ApplicationInfo application_info{};
    application_info.apiVersion = VK_API_VERSION_1_3;

    vk::InstanceCreateInfo create_info{};
    create_info.pApplicationInfo = &application_info;
    const auto extensions = vulkan_library.get_instance_extensions();
    create_info.setPpEnabledExtensionNames(extensions);

    if (SDL_GetPlatform() == std::string_view{"macOS"}) {
    }
    const vk::raii::Instance Instance{context, create_info};
    return 0;
};
