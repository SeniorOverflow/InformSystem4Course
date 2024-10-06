set(LIB_NAME UiLib)


set(DEPENDENCIES
        MathModelLib
        Qt5::Widgets
)

add_library(${LIB_NAME} STATIC)

target_include_directories(${LIB_NAME} PUBLIC "include")


file(GLOB_RECURSE SOURCES "include/*" "src/*" "ui/*")


target_sources(${LIB_NAME} PRIVATE ${SOURCES})
target_link_libraries(${LIB_NAME} PUBLIC ${DEPENDENCIES})
