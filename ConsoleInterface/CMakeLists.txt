set(LIB_NAME ConsoleInterfaceLib)

# add dependencies


add_library(${LIB_NAME} STATIC)

target_include_directories(${LIB_NAME} PUBLIC "include")


file(GLOB_RECURSE SOURCES "include/*" "src/*")


target_sources(${LIB_NAME} PRIVATE ${SOURCES} )