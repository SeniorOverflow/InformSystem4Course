cmake_minimum_required(VERSION 3.16)
project(IS_System)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(MathModel)
add_subdirectory(ConsoleInterface)

add_executable(${PROJECT_NAME} main.cpp )

target_link_libraries( ${PROJECT_NAME}
       ConsoleInterfaceLib
        MathModelLib
)
