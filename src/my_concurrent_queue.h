//
// Created by hryts on 4/5/20.
//

#ifndef LAB4_WORD_COUNT_MY_CONCURRENT_QUEUE_H
#define LAB4_WORD_COUNT_MY_CONCURRENT_QUEUE_H


#include <iostream>
#include <mutex>
#include <condition_variable>

// Queue implementation taken from https://www.bogotobogo.com/cplusplus/template_declaration_definition_header_implementation_file.php x indrekis
// Queue declaration
template<typename T>
class ConcurrentQueue
{
public:
    explicit ConcurrentQueue(size_t lim);
    ~ConcurrentQueue();
    void push(T e);
    T pop();
    size_t get_size();
    void poison();
    bool is_poisoned();
private:
    struct node
    {
        T data;
        node* next;
    };
    typedef node NODE;
    NODE* mHead;
    std::mutex m_m;
    std::condition_variable for_pop;
    std::condition_variable for_push;
    size_t size;
    size_t limit;
    bool poisoned;
};

// template definition
template<typename T>
ConcurrentQueue<T>::ConcurrentQueue(size_t lim)
{
    mHead = NULL;
    size = 0;
    poisoned = false;
    limit = lim;
}

template<typename T>
ConcurrentQueue<T>::~ConcurrentQueue()
{
    NODE *tmp;
    while(mHead) {
        tmp = mHead;
        mHead = mHead->next;
        delete tmp;
    }
}

template<typename T>
void ConcurrentQueue<T>::push(T e)
{
    std::unique_lock<std::mutex> lg(m_m);
    if(size>=limit){
        for_push.wait(lg);
    }
    NODE *ptr = new node;
    ptr->data = e;
    ptr->next = NULL;
    if(mHead == NULL) {
        mHead = ptr;
        ++size;
        for_pop.notify_one();
        return;
    }
    NODE *cur = mHead;
    while(cur) {
        if(cur->next == NULL) {
            cur->next = ptr;
            ++size;
            for_pop.notify_one();
            return;
        }
        cur = cur->next;
    }
}

template<typename T>
T ConcurrentQueue<T>::pop()
{
    std::unique_lock<std::mutex> lg(m_m);
    if(size == 0) {
        if (poisoned) {
            T res;
            return res;
        }
        for_pop.wait(lg);
    }
    NODE *tmp = mHead;
    T res = mHead->data;
    mHead = mHead->next;
    delete tmp;
    size--;
    for_push.notify_one();
    return res;
}

template<typename T>
size_t ConcurrentQueue<T>::get_size() {
    return size;
}

template<typename T>
void ConcurrentQueue<T>::poison() {
    poisoned=true;
}

template<typename T>
bool ConcurrentQueue<T>::is_poisoned() {
    return poisoned;
}

#endif //LAB4_WORD_COUNT_MY_CONCURRENT_QUEUE_H
