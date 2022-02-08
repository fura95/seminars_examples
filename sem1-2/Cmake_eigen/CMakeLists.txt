cmake_minimum_required (VERSION 3.10) #минимальная требуемая версия CMake
project (eigen_cmake VERSION 0.1.0) #название проекта и его версия

set(CMAKE_CXX_STANDARD 17) #требуемая версия компилятора
set(CMAKE_CXX_STANDARD_REQUIRED ON) #делает обязательным предыдущую команду
#SET(CMAKE_CXX_FLAGS "-Wall -fno-rtti") #флажки, которые работают на Linux\MacOS
#SET(CMAKE_CXX_FLAGS_RELEASE "-O3") #-finline-functions #флажки, которые работают на Linux\MacOS
#SET(CMAKE_CXX_FLAGS_DEBUG  "-O0 -g -Wall -Wextra -Wpedantic") #флажки, которые работают на Linux\MacOS

set(P7_LOGGER false CACHE BOOL "Activate P7 logger (true/false)") #Создали bool переменную P7_LOGGER

add_subdirectory(./deps) #Зайти в папку deps, найти там CMakeLists.txt и запустить там сборку
add_subdirectory(./src) #Зайти в папку src, найти там CMakeLists.txt и запустить там сборку

