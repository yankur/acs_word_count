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
    ConcurrentQueue();
    ~ConcurrentQueue();
    ConcurrentQueue(ConcurrentQueue<T> const &queue);
    void push(T e);
    T pop();
    size_t get_size();
private:
    struct node
    {
        T data;
        node* next;
    };
    typedef node NODE;
    NODE* mHead;
    std::mutex m_m;
    std::condition_variable cv_m;
    size_t size;
    bool poisoned;
};

// template definition
template<typename T>
ConcurrentQueue<T>::ConcurrentQueue()
{
    mHead = NULL;
    size = 0;
    poisoned = false;
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
    std::lock_guard<std::mutex> lg(m_m);
    NODE *ptr = new node;
    ptr->data = e;
    ptr->next = NULL;
    if(mHead == NULL) {
        mHead = ptr;
        ++size;
        cv_m.notify_one();
        return;
    }
    NODE *cur = mHead;
    while(cur) {
        if(cur->next == NULL) {
            cur->next = ptr;
            ++size;
            cv_m.notify_one();
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
        cv_m.wait(lg);
    }
    NODE *tmp = mHead;
    T res = mHead->data;
    mHead = mHead->next;
    delete tmp;
    size--;
    return res;
}

template<typename T>
size_t ConcurrentQueue<T>::get_size() {
    return size;
}

#endif //LAB4_WORD_COUNT_MY_CONCURRENT_QUEUE_H
