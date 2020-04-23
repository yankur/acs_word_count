//
// Created by hryts on 4/22/20.
//

#include "merge_all.h"
#include "merge.h"
#include "is_poisoned.h"

void merge_all(std::unordered_map<std::string, size_t> &res, ConcurrentQueue<std::unordered_map<std::string, size_t>> &dicts_q, size_t pill_number) {
    size_t pills_counter = 0;
    while(pills_counter<pill_number){
        auto d1 = dicts_q.pop();
        if (is_poisoned_dict(d1)){
            pills_counter++;
        } else{
            merge(res, d1);
        }
    }
}
