#ifndef LAB4_WORD_COUNT_COUNT_WORDS_H
#define LAB4_WORD_COUNT_COUNT_WORDS_H

#include <ctype.h>
#include <string>
#include <map>
#include <bits/unordered_map.h>
#include "my_concurrent_queue.h"

void count_words(const std::string& inp_string, ConcurrentQueue<std::unordered_map<std::string, size_t>> &queue);
int next_nonalpha(const std::string &str, int current);

#endif //LAB4_WORD_COUNT_COUNT_WORDS_H
