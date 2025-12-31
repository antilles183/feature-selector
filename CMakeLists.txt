cmake_minimum_required(VERSION 3.2...4.2.1)
project(feature-selector)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/arc")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

include_directories(${CMAKE_SOURCE_DIR}/src)
link_directories(${LIBRARY_OUTPUT_PATH})


add_subdirectory(src)
add_subdirectory(test)

# COMMENT
add_executable(feature-selector
    src/main.cpp
)

target_link_libraries(feature-selector featureSelectorLib)