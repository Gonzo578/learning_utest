cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Global project name
project ("Project Template")

# Add local module path to the cmake modules search path
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

# Include local cmake modules
include(gmock)

# Testing configuration
enable_testing()

# Add boost cpp library to project
set(BOOST_ROOT "../../Libs/boost_1_64_0")
set(BOOST_INCLUDEDIR "../../Libs/boost_1_64_0/include")
set(BOOST_LIBRARYDIR "../../Libs/boost_1_64_0/lib")
find_package(Boost 1.64 EXACT REQUIRED COMPONENTS program_options)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/components)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS}) 

# Add components to projects build
add_subdirectory(components)

# Project source files
set (project_SRC
    src/main.cc
    )

# Main project target configuration
add_executable (projTemplate ${project_SRC})

# Target link libraries
target_link_libraries(projTemplate toDoCore ${Boost_LIBRARIES})
