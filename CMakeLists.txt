cmake_minimum_required(VERSION 3.25)
project(VK_APP)

add_subdirectory(source)
add_subdirectory(thirdparty)
target_link_libraries(source PRIVATE thirdparty)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

