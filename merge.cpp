#include "merge.h"


void merge(std::unordered_map<std::string, int> dict1, std::unordered_map<std::string, int> dict2) {
    for(std::pair<std::string, int> el : dict2) {
        if (dict1.find(el.first) == dict1.end()) {
            dict1[el.first] = el.second;
        } else {
            dict1[el.first] += el.second;
        }
    }
}