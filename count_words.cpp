#include <cctype>
#include <map>
#include <boost/locale.hpp>

void dict_update(std::map<std::string, size_t> dict_of_words, const std::string& word);

std::map<std::string, size_t> count_words(const std::string& inp_string) {
    std::map<std::string, size_t> dict_of_words;

    boost::locale::generator gen;
    std::locale loc = gen("en_US.UTF-8");
    std::string norm_str = boost::locale::conv::from_utf(boost::locale::normalize(inp_string,boost::locale::norm_default, loc), "ISO8859-1");
//    std::cout << str << std::endl;
//    norm_str = boost::locale::fold_case(norm_str);


    std::string word;
    for (auto x : norm_str)
    {
        if (isalpha(x)) {
            dict_update(dict_of_words, word);
            word = "";
        }
        else { word += char(tolower(x)); }
    }

    return dict_of_words;
}

void dict_update(std::map<std::string, size_t> dict_of_words, const std::string& word) {
    if (dict_of_words.count(word) == 0) {
        dict_of_words.insert (std::pair<std::string, size_t>(word, 1));
    }
    else {
        std::map<std::string, size_t>::iterator itr;
        itr = dict_of_words.find(word);
        if (itr != dict_of_words.end())
            itr->second = 1;
    }
}
