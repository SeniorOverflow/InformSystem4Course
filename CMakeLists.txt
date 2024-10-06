cmake_minimum_required(VERSION 3.16)
project(IS_System LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt5 COMPONENTS Widgets REQUIRED)


add_subdirectory(Lab2Core)
add_subdirectory(Lab3Core)
add_subdirectory(Lab5Core)

add_subdirectory(MathModel)
add_subdirectory(ConsoleInterface)
add_subdirectory(Gui)


add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries( ${PROJECT_NAME}
        Lab2CoreLib
        Lab3CoreLib
        Lab5CoreLib
        ConsoleInterfaceLib
        MathModelLib
        UiLib
        Qt5::Widgets
)
