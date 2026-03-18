cmake_minimum_required(VERSION 4.0)
project(CPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(CPP
        TP2/headers/Point.h
        TP2/sources/Point.cpp
        TP2/headers/Forme.h
        TP2/headers/Triangle.h
        TP2/headers/Quadri.h
        TP2/headers/Cercle.h
        TP2/sources/Cercle.cpp
        TP2/sources/Forme.cpp
        TP2/sources/Triangle.cpp
        TP2/sources/Quadri.cpp
        TP2/main.cpp
        #        tp/point/point.cpp
#        tp/point/point.h
#        tp/rectangle/rectangle.cpp
#        tp/rectangle/rectangle.h
#        tp/main.cpp
#        tp/base.cpp
#        tp/base.h
#        tp/deadly_diamand.cpp
#        main.cpp
#        Others/lamda_function.cpp
)
