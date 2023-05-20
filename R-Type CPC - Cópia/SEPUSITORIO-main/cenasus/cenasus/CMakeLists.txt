cmake_minimum_required(version 2.8)

project(cenasus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wextra")

add_executable(cenasus cenasus.cpp Game.cpp Background.cpp Player.cpp Bullet.cpp Enemy.cpp)	

target_link_libraries (cenasus allegro allegro_image allegro_primitives)