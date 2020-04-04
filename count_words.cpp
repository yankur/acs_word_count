#include <map>
#include <boost/locale.hpp>

void dict_update(std::unordered_map<std::string, size_t> dict_of_words, const std::string& word);

std::unordered_map<std::string, size_t> count_words(const std::string& inp_string) {
    std::unordered_map<std::string, size_t> dict_of_words;

    boost::locale::generator gen;
    std::locale loc = gen("en_US.UTF-8");
    std::string norm_str = boost::locale::conv::from_utf(boost::locale::normalize(inp_string,boost::locale::norm_default, loc), "ISO8859-1");
    norm_str = boost::locale::fold_case(norm_str);

    boost::locale::boundary::ssegment_index map(boost::locale::boundary::word,norm_str.begin(),norm_str.end());
    map.rule(boost::locale::boundary::word_letters);

    for(boost::locale::boundary::ssegment_index::iterator it=map.begin(),e=map.end();it!=e;++it)
        dict_update(dict_of_words, * it);

    return dict_of_words;
}

void dict_update(std::unordered_map<std::string, size_t> dict_of_words, const std::string& word) {
    if (dict_of_words.count(word) == 0) {
        dict_of_words.insert (std::pair<std::string, size_t>(word, 1));
    }
    else {
        std::unordered_map<std::string, size_t>::iterator itr;
        itr = dict_of_words.find(word);
        if (itr != dict_of_words.end())
            itr->second = 1;
    }
}
