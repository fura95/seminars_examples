include(FetchContent) #�������� ��������� ������� FetchContent
set(FETCHCONTENT_QUIET FALSE) #������, ������� ������� FetchContent �������, ���� ������� TRUE, �� �� ��� ������� :)

FetchContent_Declare( #������ �������
  Eigen_lib #��� ���������� ����������, ������� ����� �������� (�������� ����� ���� �����)
  GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git #������ �� ���
  GIT_TAG 3.4.0 #������ ���������� (����� ����� �������� ������ � git tags)
  GIT_SHALLOW TRUE #����� �������� ������ ������ �� ������ 3.4.0 ��� ����� ��������� ��� ������ �������
  GIT_PROGRESS TRUE) #���������� �������� ����������
set(EIGEN_BUILD_DOC OFF) #����� �� ������������ ��������� ���������� Eigen
# note: To disable eigen tests,
# you should put this code in a add_subdirectory to avoid to change
# BUILD_TESTING for your own project too since variables are directory
# scoped
set(BUILD_TESTING OFF) #����� �� ������������ ��������� ���������� Eigen
set(EIGEN_BUILD_PKGCONFIG OFF) #����� �� ������������ ��������� ���������� Eigen

FetchContent_MakeAvailable(Eigen_lib) #������� � ������� ���������� Eigen

#add_subdirectory(libp7-baical) #������� � libp7-baical � ����� ��� CMakeLists.txt. ��� ��������� ��������� ��� ������ �� �������
