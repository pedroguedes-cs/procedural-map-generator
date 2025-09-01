cmake_minimum_required(VERSION 3.10)
project(MapGenerator)

# Include headers
include_directories(code/include)

# Explicitly list all source files
set(SOURCES
    code/src/main.cpp
    code/src/image.cpp
    code/src/input.cpp
    code/src/map.cpp
    code/src/menu.cpp
    code/src/message.cpp
    code/src/overview.cpp
    code/src/palette.cpp
    code/src/style.cpp
    code/src/utilities.cpp
)

# Create executable
add_executable(main ${SOURCES})

# Put binary inside build/bin
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)