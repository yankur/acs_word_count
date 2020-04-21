cmake_minimum_required(VERSION 3.10)
project(lab4_word_count)

SET(CMAKE_CXX_STANDARD 17)
#IF(CMAKE_COMPILER_IS_GNUCC)
#    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
#    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
#ENDIF(CMAKE_COMPILER_IS_GNUCC)
set(CMAKE_CXX_FLAGS "-g")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
#if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#    # for Clang and AppleClang
#    set( CMAKE_CXX_FLAGS "-Ofast" )
#elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#    # for GCC
#    set( CMAKE_CXX_FLAGS "-O3 -Wall -Wextra" )
#elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
#    # for Intel ++
#    set( CMAKE_CXX_FLAGS "-fast" )
#elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
#    # for MSVC
#    set( CMAKE_CXX_FLAGS "-O2" )
#endif()
SET(CMAKE_CXX_FLAGS -pthread)

find_package( Boost REQUIRED COMPONENTS)
#find_package(LibArchive REQUIRED)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

#find_package (LibArchive REQUIRED)
#target_link_libraries (unpack.cpp, LibArchive_LIBRARIES)


add_executable(lab4_word_count
        src/read_file.cpp
        src/read_file.h
        src/count_words.cpp
        src/count_words.h
        src/main.cpp
        src/main.h
        src/merge.cpp
        src/merge.h
        src/read_config.cpp
        src/read_config.h
        src/my_concurrent_queue.h
        src/write_result.cpp
        src/write_result.h
        src/unpack.cpp
        src/unpack.h)

target_link_libraries(lab4_word_count LINK_PUBLIC ${Boost_LIBRARIES})
target_include_directories(lab4_word_count PRIVATE ${Boost_INCLUDE_DIRS})