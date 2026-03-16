cmake_minimum_required(VERSION 3.16)
project(collisions)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -O3")

option(GRAPHICS "Enable graphics" OFF)

if(GRAPHICS)
    add_definitions(-DGRAPHICS)
    add_subdirectory(SDL EXCLUDE_FROM_ALL)
endif()

find_package(MPI REQUIRED)

# Collect up sources with optional graphics source file
set(SOURCES CollisionSim.cpp circle_collider.cpp)
if(GRAPHICS)
list(APPEND SOURCES graphics_utils.cpp) 
endif()
add_executable(CollisionSim ${SOURCES})

# Link to the actual SDL3 library.
target_link_libraries(CollisionSim PUBLIC MPI::MPI_CXX)
if(GRAPHICS)
    target_link_libraries(CollisionSim PUBLIC SDL3::SDL3)
endif()