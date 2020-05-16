#include <sstream>
#include <fstream>
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <vector>

#include "merge.h"
#include "count_words_boost.h"
#include "my_concurrent_queue.h"
#include "read_config.h"
#include "write_result.h"
#include "merge_all.h"
#include "read_disk.h"

#include <boost/locale.hpp>



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

    std::cout << "main" << "\n";
    auto config = read_conf();
    size_t merging_threads=std::stoi(config["threads"]);
    size_t indexing_threads=std::stoi(config["indexing_threads"]);
    size_t max_words=std::stoi(config["max_words"]);
    size_t queue_limit=std::stoi(config["queue_limit"]);

    auto start_time = get_current_time_fenced();

    std::vector<std::thread> indexers;
    std::vector<std::thread> mergers;
    ConcurrentQueue<std::string> substring_queue(queue_limit);
    ConcurrentQueue<std::unordered_map<std::string, size_t>> dicts_queue(queue_limit);
    std::mutex m;

    for(int i=0;i<indexing_threads;++i){
        indexers.emplace_back(count_words, std::ref(substring_queue), std::ref(dicts_queue));
    }

    std::cout << "reading" << "\n";
    std::cout << config["infile"] << "\n";
    read_disk(config["infile"],std::ref(substring_queue),max_words);

    std::cout << "counting" << "\n";

    auto res_d = dicts_queue.pop();
    for(int i=0;i<merging_threads;++i){
        mergers.emplace_back(merge_all, std::ref(res_d), std::ref(dicts_queue), std::ref(m));
    }
    std::cout << "merged" << "\n";


    for(int i=0;i<indexing_threads;++i){indexers[i].join();}
    std::unordered_map<std::string, size_t> t;
    t[""] = 0;
    dicts_queue.push(t);
    for(int i=0;i<merging_threads;++i){mergers[i].join();}


    auto total_time = get_current_time_fenced() - start_time;

    write_result(res_d, config["out_by_a"], "key");
    write_result(res_d, config["out_by_n"], "val");

    std::cout << std::endl << "Time: " <<  to_us(total_time) << std::endl;

    return 0;
}