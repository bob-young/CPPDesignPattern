cmake_minimum_required(VERSION 3.6)
project(designPattern)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Singleton.cpp Singleton.h Factory.cpp Factory.h AbstractFactory.cpp AbstractFactory.h Builder.cpp Builder.h Prototype.cpp Prototype.h Adapter.cpp Adapter.h Bridge.cpp Bridge.h Filter.cpp Filter.h Composite.cpp Composite.h Decorator.cpp Decorator.h Facade.cpp Facade.h Flyweight.cpp Flyweight.h Proxy.cpp Proxy.h)
add_executable(designPattern ${SOURCE_FILES})