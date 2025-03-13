cmake_minimum_required(VERSION 3.25)
project(Terminal-C-Game)

link_directories(${CMAKE_SOURCE_DIR})
set(CMAKE_C_FLAGS "-Wall")

add_library(game player.c monster.c game.c inventory.c item.c tools.c)

add_executable(main main.c)

target_link_libraries(main game)