#CMake C++1
SET(CMAKE_CXX_STANDART 11)

# Cpmpiler
SET(CMAKE_C_COMPILER "g++")

# Compile option
ADD_COMPILE_OPTIONS(-std=c++11)
ADD_EXECUTABLE(app.out main.cpp)
