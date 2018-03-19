cmake_minimum_required(VERSION 3.2)
project(EE450Project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(Server_SOURCE_FILES server.cpp server.h Dictionary.cpp Dictionary.h FileReader.cpp FileReader.h backendA.txt)
add_executable(Server ${Server_SOURCE_FILES})

add_executable(hello ${Server_SOURCE_FILES} Constants.cpp Constants.h)

