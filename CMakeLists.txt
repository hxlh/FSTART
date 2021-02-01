cmake_minimum_required(VERSION 3.5)

project(FSTART LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#设置Qt库版本
set(CMAKE_PREFIX_PATH "D:\\software\\Qt5.15\\5.15.0\\mingw81_64")

find_package(Qt5 COMPONENTS Widgets Sql REQUIRED)
#获取当前目录下所有源文件到 CURR_DIR变量
aux_source_directory(. CURR_DIR)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(FSTART Qt5::Widgets Qt5::Sql)

#加入源码
target_sources(
  ${PROJECT_NAME}
  PRIVATE
  ${CURR_DIR}
)