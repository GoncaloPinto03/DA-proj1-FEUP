cmake_minimum_required(VERSION 3.24)
project(PROJ1)

set(CMAKE_CXX_STANDARD 17)

file(GLOB DATA_STRUCTURES_FILES CONFIGURE_DEPENDS "data_structures/*.cpp")
add_library(DATA_STRUCTURES ${DATA_STRUCTURES_FILES})
add_executable(PROJ1 Tests/main.cpp Tests/read_files.cpp Tests/read_files.h Tests/station.cpp Tests/station.h Tests/network.cpp Tests/network.h)
