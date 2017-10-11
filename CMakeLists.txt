cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
project(SSVM)

configure_file("${PROJECT_SOURCE_DIR}/config.h.in" "${PROJECT_SOURCE_DIR}/src/infrastructure/ImplConfig.h")
option(USE_STD_TYPE_TRAIT "use stl type trait implementation version" ON)

# add infrastructure libararies
add_subdirectory(src)