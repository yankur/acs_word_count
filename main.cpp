#include <sstream>
#include <fstream>
#include <iostream>

#include "merge.h"
#include "count_words.h"
#include "my_concurrent_queue.h"
#include "read_config.h"
#include "write_result.h"


int main() {

    auto config = read_conf();
    std::string file_to_read = "/home/hryts/UCU/22/aks/acs_word_count/" + config["infile"];

    // Read file
    std::ifstream raw_file(file_to_read, std::ios::binary);
    std::ostringstream buffer_ss;
    buffer_ss << raw_file.rdbuf();
    std::string buffer{buffer_ss.str()};


    std::unordered_map<std::string, size_t> dict1;
    std::unordered_map<std::string, size_t> dict2;
    count_words(dict1, buffer);
    count_words(dict2, buffer);

    ConcurrentQueue<std::unordered_map<std::string, size_t>> que;
    que.push(dict1);
    que.push(dict2);

    auto d1 = que.pop();
    auto d2 = que.pop();

    merge(d1, d2);

    write_result(d1, config["out_by_a"], "key");
    write_result(d1, config["out_by_n"], "val");

    return 0;
}