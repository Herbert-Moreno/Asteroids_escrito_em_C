cmake_minimum_required(VERSION 3.30)
project(Asteroids_in_C)

set(CMAKE_C_STANDARD 23)

#define todos os arquivos C que vai compilar junto com o main.c
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

set(RAYLIB_VERSION 5.5)
include(FetchContent)
FetchContent_Declare(
        raylib
        DOWNLOAD_EXTRACT_TIMESTAMP OFF
        URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

link_libraries(opengl32 gdi32)

add_executable(Asteroids_in_C "${MY_SOURCES}")

target_link_libraries(${PROJECT_NAME} raylib)

target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")

target_include_directories("${CMAKE_PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/include")
