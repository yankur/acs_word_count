#include "count_words.h"
#include "is_poisoned.h"

void dict_update(std::unordered_map<std::string, size_t> &dict_of_words, const std::string& word);
int next_nonalpha(const std::string &str, int current);
std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ");


void count_words(ConcurrentQueue<std::string>& inp_queue, ConcurrentQueue<std::unordered_map<std::string, size_t>> &queue) {
    while(true){
        const std::string& inp_string = inp_queue.pop();
        if(inp_string==""){ // poison pill
//            inp_queue.push(inp_string);
            break;
        }
        std::cout << "Counting started.." << std::endl;

        std::unordered_map<std::string, size_t> dict_of_words;
        std::string word = "";
        for (auto x : inp_string)
        {
            if (!isalpha(x)&&!(word.empty())) {
                trim(word);
                dict_update(dict_of_words, word);
                word = "";
            }
            else { word += char(tolower(x)); }
        }
        std::cout << "Counting finished. Start pushing.." << "\n";
        if(!is_poisoned_dict(dict_of_words)){
            queue.push(dict_of_words);
        }
    }
    std::unordered_map<std::string, size_t> poison_p;
    poison_p[""] = 0;
    queue.push(poison_p);
    return;
}

void dict_update(std::unordered_map<std::string, size_t> &dict_of_words, const std::string& word) {
    if(word.empty()){ return;}
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
    return str.size() - 1;
}

std::string& trim(std::string& str, const std::string& chars)
{
    str.erase(0, str.find_first_not_of(chars));
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}