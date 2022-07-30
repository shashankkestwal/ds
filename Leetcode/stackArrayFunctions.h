#include <iostream>
// template <class T>
class Stack{
public:
    int arr[5];
    int i = 0;
    int n = 5;
    void push(int);
    void pop();
    void peek();
    void traverse();
    void clear();
};
