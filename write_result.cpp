//
// Created by hryts on 4/5/20.
//

#include <unordered_map>
#include <fstream>
#include <iostream>
#include <map>
#include <boost/function.hpp>
#include <set>

void write_result(const std::unordered_map<std::string, size_t> &dict, std::string outfile_name, std::string sorted_by) {
    std::ofstream outfile;
    outfile.open(outfile_name);
    typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;
    Comparator comparator;
    if (sorted_by == "key") {
        comparator = [](std::pair<std::string, int> elem1 ,std::pair<std::string, int> elem2)
        {
            return elem1.first < elem2.first;
        };
    } else if (sorted_by == "val") {
        comparator = [](std::pair<std::string, int> elem1 ,std::pair<std::string, int> elem2)
        {
            return elem1.second > elem2.second;
        };
    } else {
        std::cerr << "Wrong argument for write_result given \n";
        exit(2);
    }

    std::set<std::pair<std::string, int>, Comparator> words_set(
            dict.begin(), dict.end(), comparator);

    for(auto elem : words_set)
    {
        outfile << "'" << elem.first << "': "  << elem.second << "\n";
    }

    outfile.close();
}