cmake_minimum_required(VERSION 3.6)
project(projekt2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES MSTreeLista.cpp MSTreeLista.h menu.cpp MacierzIncydencji.cpp MacierzIncydencji.h ListaSasiedztwa.cpp ListaSasiedztwa.h NajkrotszaSciezkaLista.cpp NajkrotszaSciezkaLista.h Edge.h MSTreeMacierz.cpp MSTreeMacierz.h Edge.cpp NajkrotszaSciezkaMacierz.cpp NajkrotszaSciezkaMacierz.h NSBellmanFordLista.cpp NSBellmanFordLista.h NSBellmanFordMacierz.cpp NSBellmanFordMacierz.h Testy.h Testy.cpp)
add_executable(projekt2 ${SOURCE_FILES})