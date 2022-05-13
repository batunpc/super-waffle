cmake_minimum_required(VERSION 3.0.0)
project(cmaketuts VERSION 0.1.0)

add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(Adder)

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} 
    PUBLIC Adder
    PUBLIC  external/glfw/include
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE Adder
    PRIVATE external/glfw/src
)

target_link_libraries(${PROJECT_NAME} adder glfw)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
