#include "merge.h"


void merge(std::unordered_map<std::string, size_t> &dict1, std::unordered_map<std::string, size_t> &dict2) {
    for(std::pair<std::string, size_t> el : dict2) {
        if (dict1.find(el.first) == dict1.end()) {
            dict1[el.first] = el.second;
        } else {
            dict1[el.first] += el.second;
        }
    }
}
