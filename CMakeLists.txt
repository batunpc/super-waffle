cmake_minimum_required(VERSION 3.0.0)
project(cmaketuts VERSION 0.1.0)

#======= adder use logic =======
option(USE_ADDER "A simple library for adding 2 floats." ON)

if(USE_ADDER)
    add_subdirectory(Adder)
    list(APPEND EXTRA_LIB_DIRS "Adder")
    list(APPEND EXTRA_INCLUDES_DIRS "${PROJECT_SOURCE_DIR}/Adder")
    list(APPEND EXTRA_LINKS adder)

endif(USE_ADDER)
#======= adder use logic =======

add_executable(${PROJECT_NAME} main.cpp)

configure_file(cmaketutsConfig.h.in cmaketutsConfig.h)

include_directories(${CMAKE_CURRENT_BINARY_DIR})


target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})
#=========================================
# DOWNLOAD ALL THE SUBMODULES
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git") # checks if youre using git
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()
#=========================================
#CHECK ALL THE SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed.")
endif()

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
    ${EXTRA_INCLUDES}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
    ${EXTRA_LIB_DIRS}
)
target_link_libraries(${PROJECT_NAME} ${EXTRA_LINKS} glfw)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
