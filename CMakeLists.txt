cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Global project name
project ("Project Template")

# Add local module path to the cmake modules search path
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

# Include local cmake modules
include(gmock)

# Testing configuration
enable_testing()

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/components)

# Add components to projects build
add_subdirectory(components)

# Project source files
set (project_SRC
    src/main.cc
    )

# Main project target configuration
add_executable (projTemplate ${project_SRC})

# Target link libraries
target_link_libraries(projTemplate toDoCore)