#include <unordered_map>
#include <boost/locale.hpp>

#include "count_words_boost.h"
#include "my_concurrent_queue.h"
#include "is_poisoned.h"

void dict_update(std::unordered_map<std::string, size_t> &dict_of_words, const std::string& word);

void count_words(ConcurrentQueue<std::string>& inp_queue, ConcurrentQueue<std::unordered_map<std::string, size_t>> &dicts_queue) {
    while(true){
        std::cout << "counting" << "\n";
        std::string inp_string = inp_queue.pop();
        if(inp_string.empty()){
            break;
        }
        std::unordered_map<std::string, size_t> dict_of_words;

        boost::locale::generator gen;
        std::locale loc = gen("en_US.UTF-8");
        std::locale::global(loc);

        std::string norm_str = boost::locale::conv::from_utf(boost::locale::normalize(inp_string,boost::locale::norm_default, loc), "ISO8859-1");
        norm_str = boost::locale::fold_case(norm_str);

        boost::locale::boundary::ssegment_index map(boost::locale::boundary::word,norm_str.begin(),norm_str.end());
        map.rule(boost::locale::boundary::word_letters);

        for(boost::locale::boundary::ssegment_index::iterator it=map.begin(),e=map.end();it!=e;++it)
            dict_update(dict_of_words, * it);

        if(!is_poisoned_dict(dict_of_words)){
            dicts_queue.push(dict_of_words);
        }
    }
}

void dict_update(std::unordered_map<std::string, size_t> &dict_of_words, const std::string& word) {
    if(word.empty()){ return;}
    if (dict_of_words.find(word) == dict_of_words.end()) {
        dict_of_words[word] = 1;
    } else {
        dict_of_words[word]++;
    }
}
