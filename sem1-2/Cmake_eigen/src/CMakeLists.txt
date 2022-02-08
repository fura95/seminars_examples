#-----BEGIN OF Sources List-----
set(SOURCES ${SOURCES}	 main.cpp) #создание переменной SOURCES и записывания в нее файла с кодом, который будет компилироваться. В данной примере это main.cpp
#-----END OF Sources List-----

message(STATUS ${SOURCES}) #просто сообщение о том, какие файлы лежат в переменной SOURCES

add_executable(Eigen_example ${SOURCES}) #Создание исполняемого файла с именем Eigen_example (это также называется целью сборки) на основе файлов с кодом, которые были записаны в переменную SOURCES. В данной примере только main.cpp
target_link_libraries(Eigen_example PRIVATE Eigen3::Eigen) #Связь цели Eigen_example с библиотекой Eigen. Библиотека в Cmake называется Eigen3::Eigen