cmake_minimum_required(VERSION 3.0)

# Project name
project(StarblitzGame)

# Find SDL libraries
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

# Find gtest library
find_package(GTest REQUIRED)

# Include directories
include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${GTEST_INCLUDE_DIRS}
    ./src
)

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

# Test source files
set(TEST_SRC_FILES
    src/TestsRegression.cpp
)

# Compile object files with platform-specific flags
if(WIN32)
  add_compile_options("/W3")  # Warnings as errors on Windows
endif()

# Add executable
add_executable(StarblitzGame ${SRC_FILES})

# Link with SDL libraries
target_link_libraries(StarblitzGame 
    ${SDL2_LIBRARIES} 
    ${SDL2_IMAGE_LIBRARIES} 
    ${SDL2_TTF_LIBRARIES} 
    ${SDL2_MIXER_LIBRARIES}
)

# Add test executable
add_executable(TestsRegression ${TEST_SRC_FILES})

# Link with gtest library
target_link_libraries(TestsRegression 
    ${GTEST_BOTH_LIBRARIES}
    pthread
)

# Clean target
add_custom_target(clean COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/obj)
add_custom_target(realclean COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/obj ${CMAKE_CURRENT_BINARY_DIR}/bin)

# Dependencies
add_dependencies(StarblitzGame Compile)
