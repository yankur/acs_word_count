#include <iostream>
#include <thread>
#include <vector>
#include <deque>
#include <mutex>
#include <condition_variable>


template  <class T>
class my_concurrent_que{
private:
    std::deque<T> que_m;
    std::mutex m_m;
    std::condition_variable cv_m;
public:
    my_concurrent_que(){}

    void push(T t){
        std::lock_guard<std::mutex> lg(m_m);
        que_m.push_back(t);
    }

    size_t get_size() {
        std::lock_guard<std::mutex> lg(m_m);
        return que_m.size();
    }

    T pop(){
        std::unique_lock<std::mutex> lg(m_m);
        if(que_m.size() == 0) {
            cv_m.wait(lg);
        }
        T t = que_m.front();
        que_m.pop_front();
        return t;
    }
};