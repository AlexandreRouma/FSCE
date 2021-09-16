cmake_minimum_required(VERSION 3.13)
project(fsce)

file(GLOB_RECURSE SRC "src/*.cpp")

add_compile_options("-g")

include_directories("src/")
add_executable(fsce ${SRC})

