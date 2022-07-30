#include <iostream>
using namespace std;

class Queue {
    public:    
    int i = 0;
    int n = 5;
    int arr[5];
    bool isfilled[5];
    Queue(){
        for (int i = 0; i < n; ++i) {   
        isfilled[i] = false;
        }
    }

    void isEmpty(){
        if (i == 0 ) {
            cout<<"Queue empty";
        }  
    }
    void enqueue (int data) {
        

        if (i < n) {
            this->arr[i] = data;
            this->isfilled[i] = true;
            i++;
        } else {
            cout<<"Queue full";
        }
    }
    void dequeue (int data) {
        if (isfilled[0] == true){
            for (int j = 0; j < i; j++) {
            this->arr[j] = this->arr[j+1];
            }
        isfilled[i] = false;
        if (i > 0) {
            i--;
        } else {
            i = 0;
        }
        } else {
            cout << "Queue empty"<< endl;
        }
    }
    void peek(){
        if (isfilled[0] == true)
        {
            cout<<this->arr[0];
            return;
        }
        cout << "Queue empty"<<endl;
    }

    void traverse() {
        if (isfilled[0] == true) {
            for (int j = 0; j < i; j++){
            cout<<this->arr[j]<<"  ";
            }
        } else{
            cout << "Queue empty "<<endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    Queue q1;
    cout << "------------- Implementation of queue using array -------------" << endl;

    int choice;
    char more;
    do
    {
        cout<<"(i)Enqueue in queue"<<endl
            <<"(ii)Dequeue in queue "<<endl
            <<"(iii)Peek in queue "<<endl
            <<"(iv)Traverse in queue"<<endl;
        cout << "Enter your choice :";
        cin.clear();
        cin >> choice;
        switch (choice)
        {
        case 1:
            int element;
            cout<<"Enter the element you want to enqueue :" ;
            cin>>element;
            q1.enqueue(element);
            break;
        case 2:
            q1.dequeue(element);
            break;
        case 3:
            q1.peek();
            break;
        case 4:
            q1.traverse();
        default:
            break;
        }

        cout << "Do you want to continue(press n/N to exit ) :";
        cin >> more;
        cout << endl;

    } while (more != 'n' && more != 'N');
    
    return 0;
}
