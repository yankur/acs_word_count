//
// Created by hryts on 4/22/20.
//

#include "merge_all.h"
#include "merge.h"

bool is_poisoned_dict(std::unordered_map<std::string, size_t> dct){
    return dct.size() == 1 && dct.count("") > 0 && dct[""] == 0;
}

void merge_all(ConcurrentQueue<std::unordered_map<std::string, size_t>> &dicts_q) {
    while(dicts_q.get_size()!=1 && !dicts_q.is_poisoned()){
        auto d1 = dicts_q.pop();
        auto d2 = dicts_q.pop();
        if (is_poisoned_dict(d1) || is_poisoned_dict(d2)){
            std::unordered_map<std::string, size_t> poison_p;
            poison_p[""] = 0;
            dicts_q.push(poison_p);
            merge(d1, d2);
            break;
        }
        merge(d1, d2);
        dicts_q.push(d1);
    }
}
