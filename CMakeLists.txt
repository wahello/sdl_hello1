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

add_subdirectory(01)
add_subdirectory(02)
add_subdirectory(03)
add_subdirectory(04)
add_subdirectory(05)
add_subdirectory(06)
add_subdirectory(07)
add_subdirectory(08)


# https://www.bilibili.com/video/BV1rK411V7eu?p=1
add_subdirectory(c01)
add_subdirectory(c02)
add_subdirectory(c03)
add_subdirectory(c04)
add_subdirectory(c05)
add_subdirectory(c06)


