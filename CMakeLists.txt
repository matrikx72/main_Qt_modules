cmake_minimum_required(VERSION 3.16)

project(ConsoleApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)


find_package(Qt6 REQUIRED COMPONENTS Core Network Sql)

qt_add_executable(ConsoleApp main.cpp)

target_link_libraries(ConsoleApp PRIVATE
    Qt6::Core
    Qt6::Network
    Qt6::Sql
)