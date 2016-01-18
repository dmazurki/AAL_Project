cmake_minimum_required(VERSION 3.3)
project(AAL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/Algorithms/Algorithm.cpp src/Algorithms/Algorithm.h src/Algorithms/InputDataGenerator.cpp src/Algorithms/InputDataGenerator.h src/Presentation/Options.cpp src/Presentation/Options.h src/Presentation/Application.cpp src/Presentation/Application.h)
add_executable(AAL ${SOURCE_FILES})