# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.30
cmake_policy(SET CMP0009 NEW)

# MY_SOURCES at CMakeLists.txt:7 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "C:/Users/joseh.EMANUELLE/Documents/Asteroids_in_C/src/*.c")
set(OLD_GLOB
  "C:/Users/joseh.EMANUELLE/Documents/Asteroids_in_C/src/asteroid.c"
  "C:/Users/joseh.EMANUELLE/Documents/Asteroids_in_C/src/background.c"
  "C:/Users/joseh.EMANUELLE/Documents/Asteroids_in_C/src/game.c"
  "C:/Users/joseh.EMANUELLE/Documents/Asteroids_in_C/src/main.c"
  "C:/Users/joseh.EMANUELLE/Documents/Asteroids_in_C/src/player.c"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/Users/joseh.EMANUELLE/Documents/Asteroids_in_C/cmake-build-debug/CMakeFiles/cmake.verify_globs")
endif()
