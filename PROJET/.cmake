cmake_minimum_required(VERSION 3.0)

# Project name
project(StarblitzGame)

# Find SDL libraries
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

# Include directories
include_directories(${SDL2_INCLUDE_DIRS})

# Source files
set(SRC_FILES
  src/StarblitzGameDisplay.cpp
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

# Object files (generated)
set(OBJECT_FILES
  ${CMAKE_CURRENT_BINARY_DIR}/obj/StarblitzGameDisplay.o
  ${CMAKE_CURRENT_BINARY_DIR}/obj/ScoreSystem.o
  ${CMAKE_CURRENT_BINARY_DIR}/obj/Projectile.o
  ${CMAKE_CURRENT_BINARY_DIR}/obj/Position.o
  ${CMAKE_CURRENT_BINARY_DIR}/obj/Playership.o
  ${CMAKE_CURRENT_BINARY_DIR}/obj/Invaders.o
  ${CMAKE_CURRENT_BINARY_DIR}/obj/Partie.o
  ${CMAKE_CURRENT_BINARY_DIR}/obj/InvadersManager.o
  ${CMAKE_CURRENT_BINARY_DIR}/obj/Weapon.o
  ${CMAKE_CURRENT_BINARY_DIR}/obj/ProjectileManager.o
  ${CMAKE_CURRENT_BINARY_DIR}/obj/WeaponManager.o
)

# Compile object files with platform-specific flags
if(WIN32)
  add_compile_options("/W3")  # Warnings as errors on Windows
endif()

add_executable(StarblitzGame ${OBJECT_FILES})

# Link with SDL libraries
target_link_libraries(StarblitzGame ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_MIXER_LIBRARIES})

# Create object directory
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/obj
  COMMAND mkdir ${CMAKE_CURRENT_BINARY_DIR}/obj
  VERBATIM
)

# Compile object files
add_custom_target(Compile ALL
  FOR_FILES ${SRC_FILES}
  COMMAND ${CMAKE_COMMAND} -E compile_objects
    $<FLAGS:COMPILE>
    $<$<PLATFORM_ID:WIN32>>:/W3  # Warnings as errors on Windows again
    $<INPUT_FILE>
    $<OUTPUT_FILE:${CMAKE_CURRENT_BINARY_DIR}/obj/${@base_name}.o>
)

# Clean target
add_custom_target(clean COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/obj)
add_custom_target(realclean COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/obj ${CMAKE_CURRENT_BINARY_DIR}/bin)

# Dependencies
add_dependencies(StarblitzGame Compile)