cmake_minimum_required(VERSION 3.5)

project(qt_conan LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(TS_FILES qt_conan_de_DE.ts)


add_executable(qt_conan
  main.cpp
  mainwindow.cpp
  mainwindow.h
  mainwindow.ui
  conan_python_scripts.qrc
  )


target_link_libraries(qt_conan PRIVATE Qt5::Widgets)

