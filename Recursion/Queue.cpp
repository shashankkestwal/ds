#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    int val;
    Node(int val) {
        this->val= val;
        this->next = NULL;
    }
};
class MyQueue {
public:
    Node* head;
    Node* tail;
    MyQueue() {
        this->head = NULL;
        this->tail = NULL;
    }
    
    void push(int x) {
        Node* temp = new Node(x);
        if(this->head == NULL){
            this->head = this->tail = temp;
            return;
        } 
        this->tail->next = temp;
        this->tail = this->tail->next;
    }
    
    int pop() {
        
        // Store previous front and
        // move front one node ahead

        if(this->head == NULL) {
            this->tail = NULL;
            return -1;
        }

        Node * temp = this->head;
        int data = this->head->val;
        this->head = this->head->next;
        delete temp;
        return data;
    }
    
    int peek() {
        if(this->head == NULL) return -1;
        return this->head->val;
    }
    
    bool empty() {
        if(this->head == NULL) return true;
        return false;
    }
};

int main() {
    MyQueue m;
    m.push(10);
    m.push(20);
    m.push(30);
    cout << m.peek();
    cout << m.pop();
    cout << m.peek();
    cout << m.pop();
    return 0;
}
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */