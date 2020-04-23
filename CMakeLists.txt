CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(lab4_word_count)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS -pthread)

FIND_PACKAGE( Boost REQUIRED COMPONENTS)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

IF (WIN32)
    FIND_LIBRARY( LibArchive NAMES libarchive.dll )
ELSEIF (APPLE)
    FIND_LIBRARY( LibArchive NAMES libarchive.dylib )
ELSE ()
    FIND_LIBRARY( LibArchive NAMES libarchive.so )
ENDIF ()


ADD_EXECUTABLE (lab4_word_count
        src/count_words.cpp
        src/count_words.h
        src/main.cpp
        src/merge.cpp
        src/merge.h
        src/read_config.cpp
        src/read_config.h
        src/my_concurrent_queue.h
        src/write_result.cpp
        src/write_result.h
        src/unpack.cpp
        src/unpack.h
        src/read_by_words.cpp
        src/read_by_words.h
        src/merge_all.cpp
        src/merge_all.h
        src/is_poisoned.cpp
        src/is_poisoned.h)

TARGET_LINK_LIBRARIES (lab4_word_count ${LibArchive})
TARGET_LINK_LIBRARIES ( lab4_word_count LINK_PUBLIC ${Boost_LIBRARIES})
TARGET_INCLUDE_DIRECTORIES (lab4_word_count PRIVATE ${Boost_INCLUDE_DIRS})