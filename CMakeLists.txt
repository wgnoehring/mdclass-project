cmake_minimum_required(VERSION 3.11)

project(YAMD)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 17)

include(tools)

add_external_package(Eigen3 VERSION 3.4.0 CONFIG)

set(YAMD_HDRS
        # Add header files here
        ${CMAKE_CURRENT_SOURCE_DIR}/run.h
        ${CMAKE_CURRENT_SOURCE_DIR}/verlet.h 
        ${CMAKE_CURRENT_SOURCE_DIR}/gravity.h 
        )

set(YAMD_SRCS
        # Add source files here
        ${CMAKE_CURRENT_SOURCE_DIR}/run.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/verlet.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/gravity.cpp
        )

set(YAMD_executable_SRCS
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        )

add_subdirectory(tests)

# Simulation code
add_executable(YAMD ${YAMD_SRCS} ${YAMD_HDRS} ${YAMD_executable_SRCS})
target_link_libraries(YAMD PUBLIC Eigen3::Eigen)
