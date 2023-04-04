cmake_minimum_required(VERSION 3.24)
project(PROJ1)

set(CMAKE_CXX_STANDARD 17)

include_directories(Tests)
add_executable(PROJ1 Tests/Main.cpp Tests/Read_Files.cpp Tests/Network.cpp data_structures/Graph.cpp data_structures/Heap.cpp data_structures/UFDS.cpp data_structures/VertexEdge.cpp Tests/Station.cpp Tests/Menu.cpp Tests/Menu.h Tests/Auxiliar.h Tests/Auxiliar.cpp)
