cmake_minimum_required(VERSION 3.3)
project(AAL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/ProductionLine.cpp src/ProductionLine.h src/Algorithm.cpp src/Algorithm.h  src/InputDataGenerator.cpp src/InputDataGenerator.h)
add_executable(AAL ${SOURCE_FILES})