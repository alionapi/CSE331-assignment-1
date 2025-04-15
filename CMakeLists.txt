cmake_minimum_required(VERSION 3.28)
project(sorting_analysis C)

set(CMAKE_C_STANDARD 23)
include_directories(${CMAKE_SOURCE_DIR}/sorting-analysis)
add_executable(sorting_analysis main.c
        algorithms/bubble_sort.c
        algorithms/insertion_sort.c
        algorithms/selection_sort.c
        algorithms/merge_sort.c
        algorithms/quick_sort.c
        algorithms/heap_sort.c
        algorithms/cocktail_sort.c
        algorithms/comb_sort.c
        algorithms/library_sort.c
        algorithms/tim_sort.c
        algorithms/intro_sort.c
        algorithms/tournament_sort.c
        algorithms/sort.h
)
