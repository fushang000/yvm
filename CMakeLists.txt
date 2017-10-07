cmake_minimum_required(VERSION 3.7)
project(ssvm)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ${BUILD_DIR}/bin)

set(SOURCE_FILES
infrastructure/RBTree.hpp 
infrastructure/Stack.hpp 
infrastructure/Supersonic.h
test/infrastructure/Test_RBTree.cpp
test/Tester.h)

add_executable(ssvm ${SOURCE_FILES})