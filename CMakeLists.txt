cmake_minimum_required(VERSION 3.23)
project(3DCurvesHierarchy)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)
set(SOURCE_PATH ${CMAKE_SOURCE_DIR}/src)

include(FetchContent)
include(GoogleTest)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

find_package(OpenMP REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")

add_subdirectory(src)
add_subdirectory(tests)

target_link_libraries(3DCurvesHierarchy PRIVATE OpenMP::OpenMP_CXX)
