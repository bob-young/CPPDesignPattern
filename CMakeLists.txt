cmake_minimum_required(VERSION 3.6)
project(designPattern)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Singleton.cpp Singleton.h Factory.cpp Factory.h AbstractFactory.cpp AbstractFactory.h Builder.cpp Builder.h Prototype.cpp Prototype.h Adapter.cpp Adapter.h)
add_executable(designPattern ${SOURCE_FILES})