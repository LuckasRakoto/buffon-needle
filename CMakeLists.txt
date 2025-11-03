cmake_minimum_required(VERSION 3.11)
include(FetchContent)
set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

# Project name and version
project(buffons_needles VERSION 1.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Glad
FetchContent_Declare(
    glad
    GIT_REPOSITORY https://github.com/Dav1dde/glad.git
    GIT_TAG        v2.0.8
    GIT_PROGRESS   TRUE
    SOURCE_SUBDIR  cmake
)

FetchContent_MakeAvailable(glad)
glad_add_library(glad_gl_core_43 STATIC REPRODUCIBLE LOADER API gl:core=4.3)

# GLFW
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.4 
)
FetchContent_MakeAvailable(glfw)

# GLM
FetchContent_Declare(
    glm
	GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG         0af55ccecd98d4e5a8d1fad7de25ba429d60e863	
)
FetchContent_MakeAvailable(glm)

# IMGUI
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG         v1.92.4
)


set(IMGUI_BUILD_GLFW_BINDING ON)
set(IMGUI_BUILD_OPENGL3_BINDING ON)

FetchContent_MakeAvailable(imgui)

include_directories(${CMAKE_SOURCE_DIR}/include ${imgui_SOURCE_DIR} ${imgui_SOURCE_DIR}/backends)
file(GLOB_RECURSE ALL_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${ALL_SOURCES})



target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)

# Link libraries
target_link_libraries(${PROJECT_NAME}
    glad_gl_core_43
    glfw
    glm::glm
    imgui
    imgui_impl_glfw
    imgui_impl_opengl3
    "-framework Cocoa"
    "-framework OpenGL"
    "-framework IOKit"
)
