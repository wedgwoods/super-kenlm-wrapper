
cmake_minimum_required(VERSION 3.1)
project(kenlm-jni)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(JNI)
find_package(Boost REQUIRED)

include(ExternalProject)

set(kenlm_STATIC_LIBRARIES
    ${CMAKE_CURRENT_BINARY_DIR}/kenlm/src/kenlm-build/lib/libkenlm.a
    ${CMAKE_CURRENT_BINARY_DIR}/kenlm/src/kenlm-build/lib/libkenlm_util.a)
set(kenlm_INCLUDE_DIRS ${CMAKE_CURRENT_BINARY_DIR}/kenlm/src/kenlm)
ExternalProject_Add(kenlm
    PREFIX kenlm
    GIT_REPOSITORY https://github.com/kpu/kenlm.git
    INSTALL_COMMAND ""
    CMAKE_CACHE_ARGS
        -DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=ON