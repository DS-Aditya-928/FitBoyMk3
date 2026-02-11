target_include_directories(app PRIVATE .)
file(GLOB SOURCES "*.c")
target_sources(app PRIVATE ${SOURCES})