#zrobione na podstawie
#https://youtu.be/Lp1ifh9TuFI
cmake_minimum_required(VERSION 3.21)

set(PROJECT_NAME data_type_test)

project(${PROJECT_NAME} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

enable_testing()

add_subdirectory(googletest)

set(Sources
    ../src/linked_list.c
)

set(Headers
    ../src/linked_list.h
)
add_library(${PROJECT_NAME} STATIC ${Sources} ${Headers})

#dodaje folder test, ktory ma swojego CMakeLists.txt
add_subdirectory(linked_list)

## add includes 
target_include_directories(${PROJECT_NAME} PUBLIC ../src)
