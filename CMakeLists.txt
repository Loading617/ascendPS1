cmake_minimum_required(VERSION 3.10)
project(AscendPS1)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_definitions(${GTKMM_CFLAGS_OTHER})

add_executable(ps1_emulator src/main.cpp src/emulator.cpp src/gui.cpp)
target_link_libraries(ps1_emulator ${GTKMM_LIBRARIES})
