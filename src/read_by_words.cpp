//
// Created by hryts on 4/22/20.
//

#include "read_by_words.h"
#include <iostream>
#include <fstream>

void read_by_words(std::string& filename, ConcurrentQueue<std::string> &strings_queue, size_t max_words) {
    std::ifstream file;
    file.open (filename);
    std::string word;
    word.clear();
    std::string part;
    size_t counter = 0;
    while(file>>word){
        if(counter==max_words){
            strings_queue.push(part);
            counter=0;
        }
        part+=" "+word;
        ++counter;
    }
    if(part.size()>0){
        strings_queue.push(part);
    }
}