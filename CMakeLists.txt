cmake_minimum_required(VERSION 3.4)
project(Budget)

find_package(GTest REQUIRED)
find_package (SQLite3)
if (SQLITE3_FOUND)
  include_directories(${SQLITE3_INCLUDE_DIRS})
  target_link_libraries (tutorial ${SQLITE3_LIBRARIES})
endif (SQLITE3_FOUND)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${OPENSCENEGRAPH_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)

set(TEST_NAME ${PROJECT_NAME}_UnitTests)

add_executable(${TEST_NAME}
    UnitTests.cpp
    )

add_executable(${PROJECT_NAME}
    Main.cpp
    Budget.cpp
    Budget.hpp
    )

target_link_libraries(${PROJECT_NAME}
    sqlite3
    )

target_link_libraries(${TEST_NAME}
    ${GTEST_LIBRARIES}
    ${GTEST_MAIN_LIBRARIES}
    )

