cmake_minimum_required(VERSION 3.8)
project(ssvm)

set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(SOURCE_FILES
        classfile/AccessFlag.h
        infrastructure/Stack.hpp infrastructure/RBTree.hpp infrastructure/Supersonic.h classfile/Common.h classfile/Common.h classfile/ConstantStructures.h test/infrastructure/Test_RBTree.cpp)

add_executable(ssvm ${SOURCE_FILES})