cmake_minimum_required(VERSION 3.8)

project(Raytracer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra)

find_library(LIBCONFIG_LIBRARY NAMES config++ libconfig++ REQUIRED)
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.hpp")

add_executable(raytracer ${SOURCES} ${HEADERS})

target_include_directories(raytracer PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(raytracer PRIVATE ${LIBCONFIG_LIBRARY} sfml-graphics sfml-window sfml-system sfml-audio)
