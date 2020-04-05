//
// Created by hryts on 4/5/20.
//

#include <unordered_map>
#include <fstream>
#include <iostream>
#include <vector>
#include <boost/function.hpp>
#include <set>

void write_result(const std::unordered_map<std::string, size_t> &dict, std::string outfile_name, std::string sorted_by) {
    // Open file
    std::ofstream outfile;
    outfile.open(outfile_name);

    // Comparator
    typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;
    Comparator comparator;
    if (sorted_by == "val") {
        comparator = [](std::pair<std::string, int> elem1 ,std::pair<std::string, int> elem2) {
            return elem1.first < elem2.first;
        };
    } else if (sorted_by == "key") {
        comparator = [](std::pair<std::string, int> elem1 ,std::pair<std::string, int> elem2) {
            return elem1.second > elem2.second;
        };
    } else {
        std::cerr << "Wrong argument for write_result given \n";
        exit(2);
    }

    // Create and sort a vector
    std::vector<std::pair<std::string, size_t>> words_set;
    for (auto elem : dict) {
        words_set.push_back(elem);
    }
    std::sort(words_set.begin(), words_set.end(), comparator);

    // Write res and close the file
    for(auto elem : words_set)
    {
        outfile << "'" << elem.first << "': "  << elem.second << "\n";
    }
    outfile.close();
}