find_package(SFML REQUIRED COMPONENTS graphics window system)
find_package(TGUI REQUIRED)

add_executable(AttackPS1 main.cpp)
target_link_libraries(AttackPS1 TGUI::TGUI)
