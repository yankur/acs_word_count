CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(lab4_word_count)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS -pthread)
SET(CMAKE_CXX_FLAGS -lboost_filesystem)
SET(CMAKE_CXX_FLAGS -lboost_system)


FIND_PACKAGE( Boost REQUIRED COMPONENTS filesystem locale)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

IF (WIN32)
    FIND_LIBRARY( LibArchive NAMES libarchive.dll )
ELSEIF (APPLE)
    FIND_LIBRARY( LibArchive NAMES libarchive.dylib )
ELSE ()
    FIND_LIBRARY( LibArchive NAMES libarchive.so )
ENDIF ()


ADD_EXECUTABLE (lab4_word_count
        src/count_words_boost.cpp
        src/count_words_boost.h
        src/main.cpp
        src/merge.cpp
        src/merge.h
        src/read_config.cpp
        src/read_config.h
        src/my_concurrent_queue.h
        src/write_result.cpp
        src/write_result.h
        #        src/unpack.cpp
        #        src/unpack.h
        trash/read_by_words.cpp
        trash/read_by_words.h
        src/merge_all.cpp
        src/merge_all.h
        src/is_poisoned.cpp
        src/is_poisoned.h
        src/read_disk.cpp
        src/read_disk.h
        )

TARGET_LINK_LIBRARIES (lab4_word_count ${LibArchive})
TARGET_LINK_LIBRARIES ( lab4_word_count ${Boost_LIBRARIES})
TARGET_INCLUDE_DIRECTORIES (lab4_word_count PRIVATE ${Boost_INCLUDE_DIRS})