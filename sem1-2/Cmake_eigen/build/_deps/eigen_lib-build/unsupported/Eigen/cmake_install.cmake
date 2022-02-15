# Install script for directory: /home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE FILE FILES
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/AdolcForward"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/AlignedVector3"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/ArpackSupport"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/AutoDiff"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/BVH"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/EulerAngles"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/FFT"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/IterativeSolvers"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/KroneckerProduct"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/LevenbergMarquardt"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/MatrixFunctions"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/MoreVectorization"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/MPRealSupport"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/NonLinearOptimization"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/NumericalDiff"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/OpenGLSupport"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/Polynomials"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/Skyline"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/SparseExtra"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/SpecialFunctions"
    "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/Splines"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE DIRECTORY FILES "/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-src/unsupported/Eigen/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/vladislav/seminars/c++/seminars_examples/sem1-2/Cmake_eigen/build/_deps/eigen_lib-build/unsupported/Eigen/CXX11/cmake_install.cmake")

endif()

