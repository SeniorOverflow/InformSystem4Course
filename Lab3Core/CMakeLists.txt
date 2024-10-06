set(LIB_NAME Lab3CoreLib)



add_library(${LIB_NAME} STATIC)

target_include_directories(${LIB_NAME} PUBLIC "include")


file(GLOB_RECURSE SOURCES "include/*" "src/*")


target_sources(${LIB_NAME} PRIVATE ${SOURCES})

