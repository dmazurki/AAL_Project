cmake_minimum_required(VERSION 3.3)
project(AAL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/Algoritms/main.cpp src/Algoritms/ProductionLine.cpp src/Algoritms/ProductionLine.h src/Algoritms/BasicAlgorithm.cpp src/Algoritms/BasicAlgorithm.h src/Algoritms/PatternSearchingAlgorithm.cpp src/Algoritms/PatternSearchingAlgorithm.h src/InputDataGenerator.cpp src/InputDataGenerator.h ArrayDestructor.hpp)
add_executable(AAL ${SOURCE_FILES})