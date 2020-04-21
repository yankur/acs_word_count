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
};

// template definition
template<typename T>
ConcurrentQueue<T>::ConcurrentQueue()
{
    mHead = NULL;
    size = 0;
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


template <typename T>
ConcurrentQueue<T>::ConcurrentQueue(ConcurrentQueue<T> const &queue) {
    mHead = queue.mHead;
    size = queue.size;
}

template<typename T>
void ConcurrentQueue<T>::push(T e)
{
    std::cout << "Pushing" << "\n";
    std::lock_guard<std::mutex> lg(m_m);
    ++size;
    NODE *ptr = new node;
    ptr->data = e;
    ptr->next = NULL;
    if(mHead == NULL) {
        std::cout << "queue head is null(pushed)" << "\n";
        mHead = ptr;
        cv_m.notify_one();
        return;
    }
    NODE *cur = mHead;
    while(cur) {
        std::cout << "seeking for null..." << "\n";
        if(cur->next == NULL) {
            cur->next = ptr;
            std::cout << "Gotcha!" << "\n";
            cv_m.notify_one();
            return;
        }
        cur = cur->next;
    }
}

template<typename T>
T ConcurrentQueue<T>::pop()
{
    size--;
    std::cout << "popping" << "\n";
    std::unique_lock<std::mutex> lg(m_m);
    if(size == 0) {
        std::cout << "queue size is 0" << "\n";
        cv_m.wait(lg);
    }
    if(mHead == NULL) {
        std::cout << "queue head is null" << "\n";
        T t;
        return t;
    }
    NODE *tmp = mHead;
    T res = mHead->data;
    mHead = mHead->next;
    delete tmp;
    std::cout << "Popped!" << "\n";
    return res;
}

#endif //LAB4_WORD_COUNT_MY_CONCURRENT_QUEUE_H
