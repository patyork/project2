cmake_minimum_required(VERSION 2.8)

project(simphys_project2)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++0x")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(
 ${PROJECT_SOURCE_DIR}/include
 ${PROJECT_SOURCE_DIR}/src/main
 ${PROJECT_SOURCE_DIR}/src/test
)

# build and link test program.
add_executable(project2
  src/main/main.cpp
)
target_link_libraries(project2 spengine)

# build spengine library
add_library(spengine SHARED
  src/main/vec3.cpp
  src/main/particle.cpp
  src/main/render_engine.cpp
  src/main/input_manager.cpp
  src/main/quaternion.cpp
  src/main/simobject.cpp
  src/main/sim_engine.cpp
  src/main/sim_world.cpp
  src/main/simobject3D.cpp
  src/main/mesh.cpp
  src/main/rigid_body.cpp
  src/main/physics_engine.cpp
)
target_link_libraries(project2 GL)
target_link_libraries(project2 GLEW)
target_link_libraries(project2 GLU)
target_link_libraries(project2 freeimage)
