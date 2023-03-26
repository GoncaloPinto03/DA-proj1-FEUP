cmake_minimum_required(VERSION 3.24)
project(PROJ1)

set(CMAKE_CXX_STANDARD 17)

file(GLOB DATA_STRUCTURES_FILES CONFIGURE_DEPENDS "data_structures/*.cpp")
add_library(DATA_STRUCTURES ${DATA_STRUCTURES_FILES})
add_executable(PROJ1 Tests/main.cpp Tests/read_files.cpp Tests/read_files.h Tests/Station.cpp Tests/Station.h Tests/Network.cpp Tests/Network.h Tests/Menu.cpp Tests/Menu.h Tests/Auxiliar.cpp Tests/Auxiliar.h)
