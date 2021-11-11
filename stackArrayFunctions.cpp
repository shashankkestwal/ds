#include <iostream>
#include "stackArrayFunctions.h"
using namespace std;


void Stack :: push(int data)
    {
        if (i < n)
        {
            arr[i] = data;
            i++;
        }
        else
        {
            cout << "Stack full" << endl;
        }
    }

    void Stack ::  pop()
    {
        if (i >= 0)
        {
            cout << arr[i - 1];
            i--;
        }
        else
        {
            cout << "Stack is empty";
        }
    }
    void Stack :: traverse()
    {
        if (i == 0)
        {
            cout << "Empty stack " << endl;
        }

        for (int j = 0; j < i; j++)
        {
            cout << arr[j] << " ";
        }
    }
    void Stack :: peek()
    {
        cout << arr[i - 1];
    }
    void Stack :: clear()
    {
        i = 0;
    }
