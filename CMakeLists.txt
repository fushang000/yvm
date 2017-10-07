cmake_minimum_required(VERSION 3.8)
project(ssvm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        classfile/AccessFlag.h
        infrastructure/main.cpp infrastructure/Stack.hpp infrastructure/RBTree.hpp infrastructure/Supersonic.h classfile/Common.h classfile/Common.h classfile/ConstantStructures.h)

add_executable(ssvm ${SOURCE_FILES})