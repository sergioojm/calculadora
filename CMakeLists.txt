cmake_minimum_required(VERSION 3.5)
project(MiProyectoQt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Qt5Widgets REQUIRED)

add_executable(calculadora main.cpp GridLayout.cpp Lexer.cpp ListaEnlazada.cpp Token.cpp)
target_link_libraries(calculadora Qt5::Widgets)
