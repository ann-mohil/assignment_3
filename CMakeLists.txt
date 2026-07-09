cmake_minimum_required(VERSION 4.2)
project(assignment_3)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_library(cipher SHARED
        Cipher.h
        CeasarCipher.h
        CeasarCipher.cpp
        VigenereCipher.h
        VigenereCipher.cpp
        cipher_api.h
        cipher_api.cpp)

add_executable(assignment_3 main.cpp
        Line.h
        ContactLine.h
        ChecklistLine.cuh
        TextLine.cpp
        ChecklistLine.cpp
        Text.cpp
        Line.cpp
        CipherLoader.cpp
        ContactLine.cpp)

