//
// Created by kurlyana on 23.04.2020.
//

#ifndef LAB4_WORD_COUNT_READ_DISK_H
#define LAB4_WORD_COUNT_READ_DISK_H

#include <boost/filesystem.hpp>
#include "my_concurrent_queue.h"
#include <string>
#include "../trash/unpack.h"
#include "../trash/read_by_words.h"

void read_archive(const char *archive_file, ConcurrentQueue<std::string> &substr_queue, int max_words);
void divide_and_push(const std::string& buff, ConcurrentQueue<std::string> &strings_queue, size_t max_words);

void read_disk(const boost::filesystem::path &dir, ConcurrentQueue<std::string> &substr_queue, size_t max_words);

#endif //LAB4_WORD_COUNT_READ_DISK_H
