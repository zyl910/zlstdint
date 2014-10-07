# stdintt: zlstdint test for C.
cmake_minimum_required(VERSION 2.6)
project(stdintt)
include_directories(${PROJECT_SOURCE_DIR}/../../src)
AUX_SOURCE_DIRECTORY(. SRC_LIST) 
SET(SRC_LIST ${SRC_LIST} ../../src/z_stdint.h)
SET(SRC_LIST ${SRC_LIST} ../../src/z_inttyp.h)
ADD_EXECUTABLE(stdintt ${SRC_LIST})

