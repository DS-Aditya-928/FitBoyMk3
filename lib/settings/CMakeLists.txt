target_include_directories(app PRIVATE .)
include_directories(${LVGL_ROOT_DIR})
file(GLOB SOURCES "*.c")
target_sources(app PRIVATE ${SOURCES})