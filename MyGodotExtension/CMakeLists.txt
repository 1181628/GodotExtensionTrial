cmake_minimum_required(VERSION 3.22)
project(my_gdextension LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configure output directories for built binary DLL files
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/game/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/game/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/game/bin")

# Add godot-cpp CMake dependency
add_subdirectory(external/godot-cpp)

# Define source files
set(SOURCES
    src/register_types.h
    src/register_types.cpp
    src/example_node.h
    src/example_node.cpp
)

# Create shared library (.dll)
add_library(my_gdextension SHARED ${SOURCES})

# Target link godot-cpp bindings
target_link_libraries(my_gdextension PRIVATE godot::cpp)

# Include current src directory for header includes
target_include_directories(my_gdextension PRIVATE src)