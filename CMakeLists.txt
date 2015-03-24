cmake_minimum_required(VERSION 2.8.4)
project(levenshtein_distance)

include_directories(${SUPERGETOPT_DIR})
link_directories(${SUPERGETOPT_DIR})


set(SOURCE_FILES
    levenshtein.h
    levenshtein.c
    levenshtein-distance.c)

add_executable(levenshtein_distance ${SOURCE_FILES})
target_link_libraries(levenshtein_distance SuperGet m)



