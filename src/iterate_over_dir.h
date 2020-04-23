//
// Created by kurlyana on 23.04.2020.
//

#ifndef LAB4_WORD_COUNT_ITERATE_OVER_DIR_H
#define LAB4_WORD_COUNT_ITERATE_OVER_DIR_H

#include <boost/filesystem.hpp>
#include "my_concurrent_queue.h"
#include <string>
#include "unpack.h"
#include "read_by_words.h"

void iterate_over_dir(const boost::filesystem::path &dir, ConcurrentQueue<std::string> &substr_queue, size_t max_words);

#endif //LAB4_WORD_COUNT_ITERATE_OVER_DIR_H
