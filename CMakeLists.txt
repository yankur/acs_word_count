cmake_minimum_required(VERSION 3.15)
project(lab4_word_count)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab4_word_count
        count_words.cpp
        count_words.h)
