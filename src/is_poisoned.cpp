//
// Created by hryts on 4/23/20.
//

#include "is_poisoned.h"

bool is_poisoned_dict(std::unordered_map<std::string, size_t> dct){
    return dct.size() == 1 && dct.count("") > 0 && dct[""] == 0;
}