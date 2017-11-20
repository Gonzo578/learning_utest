cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project ("Project Template")

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/components)

# Add main project source folder to projects build
add_subdirectory(src)

# Add components to projects build
add_subdirectory(components)

# Target link libraries
