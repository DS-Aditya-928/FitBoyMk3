cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(FitBoyMk3)

target_sources(app PRIVATE src/main.c)
add_subdirectory(lib/btManager)
add_subdirectory(lib/fonts)
add_subdirectory(lib/mainMenu)
add_subdirectory(lib/settings)
add_subdirectory(lib/buttons)
add_subdirectory(lib/appManager)
add_subdirectory(lib/notifications)
add_subdirectory(lib)