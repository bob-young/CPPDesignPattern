cmake_minimum_required(VERSION 3.6)
project(designPattern)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Singleton.cpp Singleton.h Factory.cpp Factory.h AbstractFactory.cpp AbstractFactory.h Builder.cpp Builder.h Prototype.cpp Prototype.h Adapter.cpp Adapter.h Bridge.cpp Bridge.h Filter.cpp Filter.h Composite.cpp Composite.h Decorator.cpp Decorator.h Facade.cpp Facade.h Flyweight.cpp Flyweight.h Proxy.cpp Proxy.h ChainRespomsinility.cpp ChainRespomsinility.h Order.cpp Order.h Interpreter.cpp Interpreter.h iterator.cpp iterator.h Mediator.cpp Mediator.h Memento.cpp Memento.h Observer.cpp Observer.h State.cpp State.h NullObj.cpp NullObj.h Strategy.cpp Strategy.h Template.cpp Template.h Visitor.cpp Visitor.h MVC.cpp MVC.h)
add_executable(designPattern ${SOURCE_FILES})