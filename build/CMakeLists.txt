cmake_minimum_required(VERSION 3.16.3)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(search VERSION 1.0.0)
set(WORKING_DIRECTORY /home/mohammed/Work/Projects/search)

add_executable(
    search
    ${WORKING_DIRECTORY}/source/utilities.cpp
    ${WORKING_DIRECTORY}/source/main.cpp
    ${WORKING_DIRECTORY}/include/utilities.hpp
)

include_directories(${WORKING_DIRECTORY})
set_target_properties(
    search PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${WORKING_DIRECTORY}/out
)