cmake_minimum_required(VERSION 3.0)

project(StarblitzGame)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

target_link_libraries(StarblitzGame PRIVATE SDL2::SDL2 SDL2::SDL2_image)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_OBJECT_DIRECTORY ${CMAKE_BINARY_DIR}/obj)


add_executable(StarblitzGame
  src/StarblitzGameDisplay.cpp
  src/StarblitzGameLogic.cpp
  src/ScoreSystem.cpp
  src/Projectile.cpp
  src/Position.cpp
  src/Playership.cpp
  src/Invaders.cpp
  src/Partie.cpp
  src/InvadersManager.cpp
  src/Weapon.cpp
  src/ProjectileManager.cpp
  src/WeaponManager.cpp
)


target_link_libraries(StarblitzGame PRIVATE SDL2::SDL2 SDL2::SDL2_image)


add_custom_target(clean
  COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_SOURCE_DIR}/clean.cmake
  VERBATIM)

add_custom_target(realclean
  COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_SOURCE_DIR}/realclean.cmake
  VERBATIM)