#-----BEGIN OF Sources List-----
set(SOURCES ${SOURCES} main.cpp)
#-----END OF Sources List-----

add_executable(Eigen_example ${SOURCES})
target_include_directories(Eigen_example PRIVATE ./)
target_link_libraries(Eigen_example PRIVATE Eigen3::Eigen)