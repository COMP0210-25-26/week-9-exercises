# Collect up sources with optional graphics source file
set(SOURCES CollisionSim.cpp circle_collider.cpp)
if(GRAPHICS)
list(APPEND SOURCES graphics_utils.cpp) 
endif()
add_executable(CollisionSim ${SOURCES})
target_include_directories(CollisionSim PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Link to the actual SDL3 library.
target_link_libraries(CollisionSim PUBLIC MPI::MPI_CXX)
if(GRAPHICS)
    target_link_libraries(CollisionSim PUBLIC SDL3::SDL3)
endif()