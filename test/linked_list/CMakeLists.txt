cmake_minimum_required(VERSION 3.21)

set(PROJECT_NAME ListTest)

set(Sources
    linked_list_test.cpp
)

add_executable(${PROJECT_NAME} ${Sources})
target_link_libraries(${PROJECT_NAME} PUBLIC
    data_type_test
    gtest_main  #google main
)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)