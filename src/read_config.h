#include <unordered_map>
#include <functional>
#include <algorithm>

std::unordered_map<std::string, std::string> read_conf(const std::string &conf_file_name="../config.dat");