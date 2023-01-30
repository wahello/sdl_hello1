cmake_minimum_required (VERSION 3.21)

project(wx-hello)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)


# Included the conan build information
include( ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake )
conan_basic_setup(TARGETS)

# include(ODB)

message(STATUS "CMAKE_C_STANDARD: " "${CMAKE_C_STANDARD}")
message(STATUS "CMAKE_LIBRARY_PATH: " "${CMAKE_LIBRARY_PATH}")

# find_package(wxWidgets )

get_cmake_property(_variableNames VARIABLES)
list (SORT _variableNames)
foreach (_variableName ${_variableNames})
    message(STATUS  " -===: " "${_variableName}=${${_variableName}}")
endforeach()



message(status " -s--= CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(status " -s--= CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(status " -s--= CMAKE_CURRRENT_BINARY_DIR: ${CMAKE_CURRRENT_BINARY_DIR}")
message(status " -s--= CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")
message(status " -s--= EXECUTABLE_OUTPUT_PATH: ${EXECUTABLE_OUTPUT_PATH}")
message(status " -s--= PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")
message(status " -s--= CMAKE_CURRENT_LIST_DIR: ${CMAKE_CURRENT_LIST_DIR}")
message(status " -s--= CMAKE_RUNTIME_OUTPUT_DIRECTORY: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


add_subdirectory(01)
add_subdirectory(02)
add_subdirectory(03)
add_subdirectory(04)
add_subdirectory(05)
add_subdirectory(06)
add_subdirectory(07)
add_subdirectory(08)


# https://www.bilibili.com/video/BV1rK411V7eu?p=1
add_subdirectory(c05)
add_subdirectory(c06)
add_subdirectory(c07)
add_subdirectory(c08)
add_subdirectory(c09)
add_subdirectory(c10)
add_subdirectory(c11)


