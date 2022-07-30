#include <iostream>
#include "stackArrayFunctions.h"
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "------------- Implementation of stack using array -------------" << endl;
    Stack s1;
    int choice;
    char more;
    do
    {
        cout << "(i) Push an element in stack" << endl
             << "(ii) Pop an element in statck" << endl
             << "(iii) Peek an element in stack" << endl
             << "(iv) Traverse over the stack " << endl
             << "(v) Clear the stack " << endl;

        cout << "Enter which operation you want to peform : ";

        cin >> choice;
        int data;
        switch (choice)
        {
        case 1:
            cout << "Enter the element you want to push : ";
            cin >> data;
            s1.push(data);
            break;
        case 2:

            s1.pop();
            break;
        case 3:
            s1.peek();
            break;
        case 4:
            s1.traverse();
            break;
        case 5:
            s1.clear();
            break;
        default:
            cin.clear();
            cout << "Invalid input" << endl;
            break;
        }
        cout << endl
             << "Do you want to continue operations on stack, press n/N to exit : ";
        cin >> more;

        cout << endl
             << endl;
    } while (more != 'n' && more != 'N');

    return 0;
}

