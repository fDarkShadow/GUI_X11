cmake_minimum_required(VERSION 3.10)

project(X11_main)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories("include")

add_executable(X11_main
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)
target_link_libraries(X11_main X11)