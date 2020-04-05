//
// Created by hryts on 4/5/20.
//

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "read_file.h"


std::string read_file(std::string filename) {
    std::cout << "Reading file.." << "\n";
    std::string file_to_read = "/home/hryts/UCU/22/aks/acs_word_count/" + filename;
    std::ifstream raw_file(file_to_read, std::ios::binary);
    std::ostringstream buffer_ss;
    buffer_ss << raw_file.rdbuf();
    std::string buffer{buffer_ss.str()};
    std::cout << "Reading finished." << "\n";
    return buffer;
}