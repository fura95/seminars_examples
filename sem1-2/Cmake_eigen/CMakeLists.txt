cmake_minimum_required (VERSION 3.10) #����������� ��������� ������ CMake
project (eigen_cmake VERSION 0.1.0) #�������� ������� � ��� ������

set(CMAKE_CXX_STANDARD 17) #��������� ������ �����������
set(CMAKE_CXX_STANDARD_REQUIRED ON) #������ ������������ ���������� �������
SET(CMAKE_CXX_FLAGS "-Wall -fno-rtti") #������, ������� �������� �� Linux\MacOS
SET(CMAKE_CXX_FLAGS_RELEASE "-O3") #-finline-functions #������, ������� �������� �� Linux\MacOS
SET(CMAKE_CXX_FLAGS_DEBUG  "-O0 -g -Wall -Wextra -Wpedantic") #������, ������� �������� �� Linux\MacOS

add_subdirectory(./deps) #����� � ����� deps, ����� ��� CMakeLists.txt � ��������� ��� ������
add_subdirectory(./src) #����� � ����� src, ����� ��� CMakeLists.txt � ��������� ��� ������

