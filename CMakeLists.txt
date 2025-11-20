cmake_minimum_required(VERSION 4.0)
project(VulkanEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- SDL2 configuration ---

# Build static SDL, no tests
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON  CACHE BOOL "" FORCE)
set(SDL_TEST   OFF CACHE BOOL "" FORCE)

# this says to build SDL2 as a part of this project
add_subdirectory(external/SDL2)

# --- engine executable / Vulkan ---
find_package(Vulkan REQUIRED)

add_executable(VulkanEngine src/main.cpp)

# Link SDL2
target_link_libraries(VulkanEngine PRIVATE
        SDL2-static
        SDL2main
        Vulkan::Vulkan)

# Include SDL2 headers
target_include_directories(VulkanEngine PRIVATE
        external/SDL2/include)

# Target Win32 Vulkan
target_compile_definitions(VulkanEngine PRIVATE VK_USE_PLATFORM_WIN32_KHR)
