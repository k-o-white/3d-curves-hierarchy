cmake_minimum_required(VERSION 3.23)

add_executable(Gtests tests.cpp
        ${INCLUDE_PATH}/Circle.h
        ${INCLUDE_PATH}/Ellipse.h
        ${INCLUDE_PATH}/Helix.h
        ${SOURCE_PATH}/Circle.cpp
        ${SOURCE_PATH}/Ellipse.cpp
        ${SOURCE_PATH}/Helix.cpp)

target_link_libraries(Gtests gtest_main)

include(GoogleTest)

gtest_discover_tests(Gtests)

target_include_directories(Gtests PUBLIC ${INCLUDE_PATH})
target_include_directories(Gtests PUBLIC ${SOURCE_PATH})