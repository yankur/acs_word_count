#include <iostream>
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

    void push(T t);

    size_t get_size();

    T pop();
};