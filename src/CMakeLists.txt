cmake_minimum_required(VERSION 3.23)

set (HEADERS
        ${INCLUDE_PATH}/Curve.h
        ${INCLUDE_PATH}/Circle.h
        ${INCLUDE_PATH}/Ellipse.h
        ${INCLUDE_PATH}/Helix.h
    )

set (SOURCE
        main.cpp
        Circle.cpp
        Ellipse.cpp
        Helix.cpp
    )

add_executable(3DCurvesHierarchy ${HEADERS} ${SOURCE})

target_include_directories (3DCurvesHierarchy PUBLIC ${INCLUDE_PATH})