add_library(thirdparty INTERFACE)

add_subdirectory(SDL)
add_subdirectory(Vulkan-Headers)

target_link_libraries(thirdparty INTERFACE Vulkan::Headers SDL3::SDL3)

