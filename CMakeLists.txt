cmake_minimum_required(VERSION 3.16)
project(SANITIZER_DETECTOR)
include(cmake/bootstrap.cmake)

add_executable(${PROJECT_NAME}
               src/app/sanitizer_detector/main.cpp
               src/sanitizer/address/issue/collection.hpp
               src/sanitizer/address/issue/collection.cpp
               )

target_include_directories(${PROJECT_NAME} PRIVATE src)
