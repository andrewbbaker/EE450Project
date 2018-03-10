cmake_minimum_required(VERSION 3.2)
project(EE450Project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES serverA.cpp serverA.h server.cpp server.h serverB.cpp serverB.h serverC.cpp serverC.h monitor.cpp monitor.h aws.cpp aws.h client.cpp client.h dictionary.cpp dictionary.h)
add_executable(EE450Project ${SOURCE_FILES})