cmake_minimum_required(VERSION 3.16)
project(Libraries)

include_directories(include)

add_compile_options(-Wall -Wextra -Wpedantic)

add_library(c-data-datastructures
        include/vector.h
        src/vector.c
        include/list.h
        src/list.c
        include/stack.h
        src/stack.c
)

add_executable(main test/main.c)

target_link_libraries(main c-data-datastructures)