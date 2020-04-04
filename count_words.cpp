#include <cctype>
#include <map>

void dict_update(std::map<std::string, int> dict_of_words, const std::string& word);

std::map<std::string, int> count_words(const std::string& inp_string) {
    std::map<std::string, int> dict_of_words;

    std::string word;
    for (auto x : inp_string)
    {
        if (isalpha(x)) {
            dict_update(dict_of_words, word);
            word = "";
        }
        else { word += char(tolower(x)); }
    }

    return dict_of_words;
}

void dict_update(std::map<std::string, int> dict_of_words, const std::string& word) {
    if (dict_of_words.count(word) == 0) {
        dict_of_words.insert (std::pair<std::string, int>(word, 1));
    }
    else {
        std::map<std::string, int>::iterator itr;
        itr = dict_of_words.find(word);
        if (itr != dict_of_words.end())
            itr->second = 1;
    }
}
