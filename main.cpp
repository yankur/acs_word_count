#include <sstream>
#include <fstream>
#include <iostream>

#include "merge.h"
#include "count_words_boost.h"
#include "my_queue.h"


int main() {

    std::string current_file = "/home/hryts/UCU/22/aks/acs_word_count/data.txt";

    std::ifstream raw_file(current_file, std::ios::binary);
    std::ostringstream buffer_ss;
    buffer_ss << raw_file.rdbuf();
    std::string buffer{buffer_ss.str()};

    std::unordered_map<std::string, size_t> dict1 = count_words(buffer);
    auto dict2 = count_words(buffer);

    for(const auto& elem : dict1)
    {
        std::cout << elem.first << " a " << elem.second << "\n";
    }

<<<<<<< HEAD
    my_concurrent_que<std::unordered_map<std::string, size_t>> que;
    que.push(dict1);
    que.push(dict2);

    auto d1 = que.pop();
    auto d2 = que.pop();

    merge(d1, d2);

    for(const auto& elem : d1)
    {
        std::cout << elem.first << " a " << elem.second << "\n";
    }
=======
//    my_concurrent_que<std::unordered_map<std::string, size_t>> que;
//    que.push(dict1);
//    que.push(dict2);
//
//    auto d1 = que.pop();
//    auto d2 = que.pop();
//
//    merge(d1, d2);
//
//    for(auto elem : d1)
//    {
//        std::cout << elem.first << " a " << elem.second << "\n";
//    }
>>>>>>> c948539a9aafcf3b3b850ef6ce1b8e81e2a24a96
}