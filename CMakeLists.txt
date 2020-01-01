cmake_minimum_required(VERSION 3.15)
project(SoftwareProject3 C)

set(CMAKE_C_STANDARD 90)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fmessage-length=0 -ansi -Wall -Wextra -Werror -pedantic-errors")
add_executable(SoftwareProject3 Game.c MainAux.c Parser.c Solver.c main.c )