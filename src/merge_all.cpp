//
// Created by hryts on 4/22/20.
//

#include "merge_all.h"
#include "merge.h"
#include "is_poisoned.h"

void merge_all(std::unordered_map<std::string, size_t> &res, ConcurrentQueue<std::unordered_map<std::string, size_t>> &dicts_q, std::mutex& m) {
    while(true){
        auto d1 = dicts_q.pop();
        if (is_poisoned_dict(d1)){
            dicts_q.push(d1);
            break;
        } else{
            m.lock();
            merge(res, d1);
            m.unlock();
        }
    }
}
