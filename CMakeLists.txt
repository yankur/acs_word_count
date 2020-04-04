cmake_minimum_required(VERSION 3.10)
project(lab4_word_count)

SET(CMAKE_CXX_STANDARD 17)
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    # for Clang and AppleClang
    set( CMAKE_CXX_FLAGS "-Ofast" )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # for GCC
    set( CMAKE_CXX_FLAGS "-O3 -Wall -Wextra" )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    # for Intel ++
    set( CMAKE_CXX_FLAGS "-fast" )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # for MSVC
    set( CMAKE_CXX_FLAGS "-O2" )
endif()

#FIND_PACKAGE(  Boost 1.65 COMPONENTS REQUIRED)
#INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_executable(lab4_word_count
        count_words.cpp
        count_words.h
        main.cpp
        main.h
        merge.cpp
        merge.h
        my_queue.cpp
        my_queue.h
        read_config.cpp
        read_config.h)

#TARGET_LINK_LIBRARIES( lab4_word_count LINK_PUBLIC ${Boost_LIBRARIES} )