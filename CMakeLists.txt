cmake_minimum_required(VERSION 3.10)
project(Simple C)

set(CMAKE_C_STANDARD 17)

add_executable(Simple main.c simple.c)

target_compile_options(Simple PRIVATE -Wall -Wextra)