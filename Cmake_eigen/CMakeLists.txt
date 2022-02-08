cmake_minimum_required (VERSION 3.10)
project (eigen_cmake VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#SET(CMAKE_CXX_FLAGS "-Wall -fno-rtti")
#SET(CMAKE_CXX_FLAGS_RELEASE "-O3") #-finline-functions
#SET(CMAKE_CXX_FLAGS_DEBUG  "-O0 -g -Wall -Wextra -Wpedantic")

set(P7_LOGGER false CACHE BOOL "Activate P7 logger (true/false)") # p7 switcher

add_subdirectory(./deps)
add_subdirectory(./src)

