//
// Created by hryts on 4/22/20.
//

#include <string>
#include "../src/my_concurrent_queue.h"

#ifndef LAB4_WORD_COUNT_READ_BY_WORDS_H
#define LAB4_WORD_COUNT_READ_BY_WORDS_H

void read_by_words(std::string& filename, ConcurrentQueue<std::string>& strings_queue, size_t max_words);

#endif //LAB4_WORD_COUNT_READ_BY_WORDS_H
