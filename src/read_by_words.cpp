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
        part+=" "+word;
        ++counter;
        if(counter==max_words){
            std::cout<<"part pushed"<<std::endl;
            strings_queue.push(part);
            part.clear();
            counter=0;
        }
    }
    if(part.size()>0){
        strings_queue.push(part);
    }
    std::string poison_pill = "";
    strings_queue.push(poison_pill);
    strings_queue.poison();
}
