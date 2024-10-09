set(LIB_NAME MathModelLib)


set(DEPENDENCIES
    Lab2CoreLib
    Lab3CoreLib
    Lab5CoreLib
    ConsoleInterfaceLib
)

add_library(${LIB_NAME} STATIC)

target_include_directories(${LIB_NAME} PUBLIC "include")


file(GLOB_RECURSE SOURCES "include/*" "src/*")


target_sources(${LIB_NAME} PRIVATE ${SOURCES})
target_link_libraries(${LIB_NAME} PUBLIC ${DEPENDENCIES})
