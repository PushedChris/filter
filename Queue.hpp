#ifndef QUEUE_HPP
#define QUEUE_HPP
//#include<iostream>
//#include<Queue.h>
#include<cassert>
using namespace std;

// from the brain hardware group huang

template<typename T>
class Queue{
public:
    Queue(int maxsize = 10);
    ~Queue();
    bool isFull() const;   
    bool isEmpty() const;
    int size() const;
    char push(T elem);
    char pop(T& elem);
    char at(int count,T& elem);
    unsigned int size();
private:
    T* array;
    int front;
    int rear;

    int capacity;
};


template <typename T>
Queue<T>::Queue(int maxsize):front(0),rear(0),capacity(maxsize+1)
{
   array = new T[maxsize+1];
   assert(array != NULL);   //错误即终止执行
}

template <typename T>
Queue<T>::~Queue(){
   delete(array);
}

template <typename T>
bool Queue<T>::isFull() const{
    return (rear+1)%capacity == front; //往正数看
}

template <typename T>
bool Queue<T>::isEmpty() const{
    return rear == front;
}

template <typename T>
char Queue<T>::push(T elem){
    if(isFull()){
        return -1;
    }else{
        array[rear] = elem;
        rear = (rear + 1)%capacity;
        return 1;
    }
}

template <typename T>
char Queue<T>::pop(T& elem){   // oldest data
     if(isEmpty())
       return -1;
     else {
        elem = array[front];
        front = (front + 1) % capacity;
        return 1;
     }
}

template <typename T>
char Queue<T>::at(int count,T& elem){ // count 0~9
     unsigned int loc;
     if(isEmpty())
       return -1;
     else {
        loc = (front + count) % capacity;
        elem = array[loc];
        return 1;
     }
}


template <typename T>
unsigned int Queue<T>::size(){ // count 0~9
     return ((rear - front + capacity)%capacity);
}


#endif
