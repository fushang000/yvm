cmake_minimum_required(VERSION 3.7)
project(ssvm)

set(CMAKE_CXX_STANDARD 11)

set(RBTREE_SOURCE_FILES
infrastructure/RBTree.hpp 
infrastructure/Supersonic.h
test/infrastructure/Test_RBTree.cpp
test/Tester.h)

set(STRING_SOURCE_FILES
infrastructure/String.h
infrastructure/String.cpp
test/infrastructure/Test_String.cpp)


add_executable(test-rbtree ${RBTREE_SOURCE_FILES})
add_executable(test-string ${STRING_SOURCE_FILES})