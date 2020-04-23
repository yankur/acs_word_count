//
// Created by kurlyana on 4/5/20.
//

#ifndef LAB4_WORD_COUNT_UNPACK_H
#define LAB4_WORD_COUNT_UNPACK_H

#include <archive.h>
#include <archive_entry.h>
#include <string>
#include <iostream>
#include "boost/filesystem.hpp"
#include "my_concurrent_queue.h"

std::string read_archive(const std::string& buffer , ConcurrentQueue<std::string> &substr_queue);

#endif //LAB4_WORD_COUNT_UNPACK_H
