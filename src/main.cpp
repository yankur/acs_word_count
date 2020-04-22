#include <sstream>
#include <fstream>
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

#include "merge.h"
#include "count_words_boost.h"
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
    size_t threads_num = std::stoi(config["threads"]);

    auto start_time = get_current_time_fenced();
//    std::string buffer = read_file(config["infile"]);
//    part_size depends on max words number in config


//    std::vector<std::thread> v;
    ConcurrentQueue<std::string> substring_queue;
    read_by_words(config["infile"], substring_queue,std::stoi(config["max_words"]));
    std::cout<<"read"<<std::endl;
    std::cout << substring_queue.pop();

    ConcurrentQueue<std::unordered_map<std::string, size_t>> dicts_queue;


    //    int tmp = 0;
//    for (size_t i = 0; i < threads_num; ++i) {
////        getting index of next nonalpha char to split string
////        tmp_e = index of end of next thread part
//        auto tmp_e = next_nonalpha(buffer, tmp + part_size);
////        cutting string start = tmp + 1
//        std::string buff_part = buffer.substr(tmp, tmp_e-tmp);
////        count_words(buff_part, dicts_queue);
//        v.emplace_back(count_words, std::ref(buff_part), std::ref(dicts_queue));
//        tmp = tmp_e;
//    }


//    for(auto& t: v){
//        t.join();
//    }
//    count_words(buffer, std::ref(dicts_queue));

    auto d1 = dicts_queue.pop();

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