#include <cctype>
#include <unordered_map>
#include <iostream>

void dict_update(std::unordered_map<std::string, size_t> dict_of_words, const std::string& word);

std::unordered_map<std::string, size_t> count_words(const std::string& inp_string) {
    std::cout << "im counting..";
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

    return dict_of_words;
}

void dict_update(std::unordered_map<std::string, size_t> dict_of_words, const std::string& word) {
    if (dict_of_words.find(word) == dict_of_words.end()) {
        dict_of_words[word] = 1;
    } else {
        dict_of_words[word]++;
    }
}

