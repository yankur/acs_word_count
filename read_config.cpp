#include <iostream>
#include <fstream>
#include "read_config.h"

std::unordered_map<std::string, double> read_config(const std::string &conf_file_name) {
    std::ifstream in;
    in.open(conf_file_name);
    try
    {
        if (in.is_open()) {
            std::string s;

        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}