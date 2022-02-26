cmake_minimum_required(VERSION 3.20)
project(Lab C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab main.c)

add_subdirectory(libs)

target_link_libraries(Lab data_structures)
target_link_libraries(Lab algorithms)
