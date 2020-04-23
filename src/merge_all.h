//
// Created by hryts on 4/22/20.
//

#ifndef LAB4_WORD_COUNT_MERGE_ALL_H
#define LAB4_WORD_COUNT_MERGE_ALL_H

#include <string>
#include <unordered_map>

#include "my_concurrent_queue.h"

void merge_all(std::unordered_map<std::string, size_t> &res, ConcurrentQueue<std::unordered_map<std::string, size_t>> &dicts_q, size_t pill_number);

#endif //LAB4_WORD_COUNT_MERGE_ALL_H
