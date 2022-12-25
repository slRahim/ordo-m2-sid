cmake_minimum_required(VERSION 3.23)
project(ord_m2_sid C)

set(CMAKE_C_STANDARD 99)

add_executable(ord_m2_sid main.c heuristics.c heuristics.h genetic.c genetic.h init_core.c init_core.h)
