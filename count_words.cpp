#include "count_words.h"

void dict_update(std::unordered_map<std::string, size_t> &dict_of_words, const std::string& word);
int next_nonalpha(const std::string &str, int current);


void count_words(const std::string &inp_string, ConcurrentQueue<std::unordered_map<std::string, size_t>> &queue) {

    std::cout << "Counting started.." << "\n";

    std::unordered_map<std::string, size_t> dict_of_words;
    std::string word = "";
    for (auto x : inp_string)
    {
        if (!isalpha(x)) {
            dict_update(dict_of_words, word);
            word = "";
        }
        else { word += char(tolower(x)); }
    }
    std::cout << "Counting finished. Start pushing.." << "\n";
    queue.push(dict_of_words);
}

void dict_update(std::unordered_map<std::string, size_t> &dict_of_words, const std::string& word) {
    if (dict_of_words.find(word) == dict_of_words.end()) {
        dict_of_words[word] = 1;
    } else {
        dict_of_words[word]++;
    }
}

int next_nonalpha(const std::string &str, int current){
    while (current < str.size()) {
        if (!isalpha(str[current])) {
            return current;
        }
        ++current;
    }
    return current;
}