#-----BEGIN OF Sources List-----
set(SOURCES ${SOURCES}	 main.cpp) #�������� ���������� SOURCES � ����������� � ��� ����� � �����, ������� ����� ���������������. � ������ ������� ��� main.cpp
set(SOURCES ${SOURCES}	 file1.cpp)
#-----END OF Sources List-----

message(STATUS ${SOURCES}) #������ ��������� � ���, ����� ����� ����� � ���������� SOURCES

add_executable(Eigen_example ${SOURCES}) #�������� ������������ ����� � ������ Eigen_example (��� ����� ���������� ����� ������) �� ������ ������ � �����, ������� ���� �������� � ���������� SOURCES. � ������ ������� ������ main.cpp
target_link_libraries(Eigen_example PRIVATE Eigen3::Eigen) #����� ���� Eigen_example � ����������� Eigen. ���������� � Cmake ���������� Eigen3::Eigen3
