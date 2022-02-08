include(FetchContent) #Включить поддержку функции FetchContent
set(FETCHCONTENT_QUIET FALSE) #Флажок, который говорит FetchContent молчать, если сделать TRUE, то вы все поймете :)

FetchContent_Declare( #начало функции
  Eigen_lib #как называется библиотека, которая будет качаться (название может быть любым)
  GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git #ссылка на гит
  GIT_TAG 3.4.0 #версия библиотеки (можно найти варианты версии в git tags)
  GIT_SHALLOW TRUE #чтобы скачался только коммит на версии 3.4.0 или иначе скачается все дерево комитов
  GIT_PROGRESS TRUE) #показывать прогресс скачивания
set(EIGEN_BUILD_DOC OFF) #Какие то дополнителые параметры библиотеки Eigen
# note: To disable eigen tests,
# you should put this code in a add_subdirectory to avoid to change
# BUILD_TESTING for your own project too since variables are directory
# scoped
set(BUILD_TESTING OFF) #Какие то дополнителые параметры библиотеки Eigen
set(EIGEN_BUILD_PKGCONFIG OFF) #Какие то дополнителые параметры библиотеки Eigen

FetchContent_MakeAvailable(Eigen_lib) #Скачать и собрать библиотеку Eigen

add_subdirectory(libp7-baical) #Перейти в libp7-baical и найти там CMakeLists.txt. Для сторонних библиотек это значит ее собрать
