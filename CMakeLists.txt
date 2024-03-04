cmake_minimum_required(VERSION 3.27)
project(solitario)

set(CMAKE_CXX_STANDARD 17)

add_executable(solitario main.cpp
        Carta.cpp
        Carta.h
        Manejador.cpp
        Manejador.h
)
