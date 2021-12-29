#include <iostream>
using namespace std;

template <class T>
class Queue {

    private :
    int rear = -1;
    int front=  -1;
    int size = 5;
    int * arr ;
    
    public:

    Queue (int size){
        this->size = size;
        int* array = (int*)malloc(size*sizeof(int));
        this->arr = array;
    }
    
    bool isEmpty () {
        if (front == rear && front == -1) {
            return true;
        } else {
            return false;
        }      
    }

    int nextPosition() {
        return (rear + 1) % size;
    }

    bool isFull () {
        if (this->nextPosition() == this->front) {
            return true;
        } else {
            return false;
        }     
    }

    void enqueue (int data) {
        if (this->isFull()) {
            cout << "Queue is full"<<endl;
          return;
        }else {
            this->rear = this->nextPosition();
            this->arr[this->rear] = data;
            if(this->front == -1 ) {
                this->front = this->rear;
            }
        }
    }

    void dequeue () {
        if (this->isEmpty()) {
            cout <<"Queue is empty"<<endl;
            return;
        } else if(this->front == -1 ) {
            cout <<"Queue is empty"<<endl;
            return ;
        } else {        
            cout << this->arr[front] << "  ";
            if(front == rear) {
                front = rear = -1;
            }else {
                front = (front + 1) %size;
            }
        }  
        cout <<endl;   
    }

    void peek() {
        if (this->isEmpty()) {
            cout <<"Queue is empty"<<endl;
            return;
        } else if(this->front == -1 ) {
            cout <<"Queue is empty"<<endl;
            return ;
        }else {
            cout << this->arr[front] << "  ";
        }  
        cout <<endl;
    }

    void traverse () {
        if (isEmpty()) {
            cout <<"Queue is empty"<<endl;
            return ;
        } else {
            int i = this->front;
            while((i % this->size) != this->rear) {
                cout << this->arr[i] << "  ";
                i = ((i + 1) % this->size) ;
            }
            cout << this->arr[i]<<endl;
        }
    }
};

int main() {
    int size ;
    cout << "Enter the size of the queue :";
    cin >> size;
    Queue <int>q1 = Queue<int>(size);
    int choice;
    int element;
    char more;

    do {
        cout <<"(i)Enqueue in queue"<<endl
             <<"(ii)Dequeue in queue"<<endl
             <<"(iii)peek in queue"<<endl
             <<"(iv)traverse in queue"<<endl;
        cout <<"Enter which operation you want to perform :";
        cin >> choice;
        switch (choice) {
            case 1:
                cout <<"Enter the element you want to insert in queue :";
                cin >> element;
                q1.enqueue(element);
                break;
            case 2:
                q1.dequeue();
                break;
            case 3:
                q1.peek();
                break;
            case 4:
                q1.traverse();
                break;
            default:
                cout <<"Invalid input"<<endl;
                break;
        }

        cout <<"Do you want to continue the operation on queue (press n/N to exit) :";
        cin.clear();
        cin >> more;
        cout << endl;
    } while( more !='n' && more != 'N');
    return 0;
}

