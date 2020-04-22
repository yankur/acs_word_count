#include <sstream>
#include <fstream>
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

#include "merge.h"
#include "count_words.h"
#include "my_concurrent_queue.h"
#include "read_config.h"
#include "write_result.h"
#include "read_file.h"
#include "read_by_words.h"


inline std::chrono::high_resolution_clock::time_point get_current_time_fenced()
{
    std::atomic_thread_fence(std::memory_order_seq_cst);
    auto res_time = std::chrono::high_resolution_clock::now();
    std::atomic_thread_fence(std::memory_order_seq_cst);
    return res_time;
}

template<class D>
inline long long to_us(const D& d)
{
    return std::chrono::duration_cast<std::chrono::microseconds>(d).count();
}

int main() {
    auto config = read_conf();
    size_t threads_num=std::stoi(config["threads"]);
    size_t indexing_threads=std::stoi(config["indexing_threads"]);
    size_t max_words=std::stoi(config["max_words"]);
    size_t queue_limit=std::stoi(config["queue_limit"]);

    std::cout<<config["out_by_n"]<<std::endl;
    std::cout<<config["out_by_a"]<<std::endl;

    auto start_time = get_current_time_fenced();

    std::vector<std::thread> indexers;
    ConcurrentQueue<std::string> substring_queue(queue_limit);
    ConcurrentQueue<std::unordered_map<std::string, size_t>> dicts_queue(queue_limit);

    for(int i=0;i<indexing_threads;++i){
        indexers.emplace_back(count_words, std::ref(substring_queue), std::ref(dicts_queue));
    }
    read_by_words(config["infile"],substring_queue,max_words);


    auto d1 = dicts_queue.pop();

    while(dicts_queue.get_size()!=0){
        auto d2 = dicts_queue.pop();
        merge(d1, d2);
    }
//    for (int i = 0; i < threads_num; ++i) {
//        auto d2 = dicts_queue.pop();
//        merge(d1, d2);
//    }
    auto total_time = get_current_time_fenced() - start_time;

    write_result(d1, config["out_by_a"], "key");
    write_result(d1, config["out_by_n"], "val");

    std::cout << "Time: " <<  to_us(total_time) << std::endl;

    return 0;
}