#include <iostream>
#include <fstream>

#include "read_config.h"


std::unordered_map<std::string, std::string> read_conf(const std::string &conf_file_name) {
    std::ifstream in;
    in.open(conf_file_name);
    std::unordered_map<std::string, std::string> res;
    try
    {
        if (in.is_open()) {
            std::string s;
            while (getline(in, s)) {
                s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());
                auto eq = s.find('=');
                auto qu = s.find('"') + 1;

                if (s.empty() || eq == std::string::npos) {
                    continue;
                }

                auto name = s.substr(0, eq);
                std::string val;
                if (name != "threads") {
                    val = s.substr(qu, s.size()-qu-1);
                } else {
                    val = s.substr(eq + 1);
                }
                res[name] = val;
            }
            
        } else
        {
            std::cerr << "Couldn't open config file for reading. \n";
            exit(2);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Wrong configuration file arguments. \n";
        exit(3);
    }

    in.close();
    return res;   
}