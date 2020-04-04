#include <sstream>
#include <fstream>
#include <iostream>

#include "count_words.h"


int main() {
    
    std::string current_file = "/home/hryts/UCU/22/aks/acs_word_count/data.txt";

    std::ifstream raw_file(current_file, std::ios::binary);
    std::ostringstream buffer_ss;
    buffer_ss << raw_file.rdbuf();
    std::string buffer{buffer_ss.str()};

    auto dict = count_words(buffer);

    for(auto elem : dict)
    {
        std::cout << elem.first << " a " << elem.second << "\n";
    }
}