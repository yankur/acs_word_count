//
// Created by kurlyana on 21.04.2020.
//

#include <string>
#include "my_concurrent_queue.h"

void divide_and_push(const size_t max_words, const std::string& inp_string, ConcurrentQueue<std::string>& substring_queue) {
    size_t count_words = 0;
    size_t count_chars = 0;
    size_t zero_index = 0;
    for (size_t curr_index = 0; curr_index < inp_string.length(); ++curr_index) {
        if (isspace(inp_string[curr_index])) {
            count_words++;
            count_chars++;
            if (count_words >= max_words) {
                count_words = 0;
                substring_queue.push(inp_string.substr(zero_index, count_chars));
                zero_index = count_chars;
                count_chars = 0;
            }
        }
        else {
            count_chars++;
        }
    }
    if (count_chars != 0) {
        substring_queue.push(inp_string.substr(zero_index));
    }
}
