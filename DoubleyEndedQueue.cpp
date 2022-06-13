#include <iostream>
using namespace std;

class Node{

	
public:
	int data;
	Node* next;
	Node* previous;
	Node(int d){
		this->next = this->previous = NULL;
		this->data = d; 
	}
};

class DoublyLinkedList{
protected:
	Node* head;
	Node* tail;
	DoublyLinkedList() {
		this->head = NULL;
		this->tail = NULL;
	}

	Node* createNode(int data ){
		Node* n = new Node(data);
		return n;
	}
	bool isEmpty(){
		if (this->head == NULL) {
			return true;
		}
		return false;
	}

	void insertAtStart(int data){
		Node* newNode = this->createNode(data);
		if(isEmpty()) {
			this->head = newNode;
			this->tail;
			return;
		}
		Node* temp = this->head;
		this->head = newNode;
		this->head->next = temp;
		temp->previous = this->head;
	}

	void insertAtEnd(int data ) {
		Node* newNode = this->createNode(data);
		if(isEmpty()) {
			this->head = newNode;
			return;
		}
		Node* temp = this->head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		this->tail = newNode;
		temp->next = newNode ;
		newNode->previous = temp;
	}

	void deleteFromStart(){
		if(isEmpty()) {
			return;		
		}
		Node* temp = this->head;
		if (temp->next ==NULL)
		{
			this->head = this->tail = NULL;
			delete temp;
			return;
		}
		this->head = temp->next;
		temp->next = NULL;
		delete temp;
	}
	void deleteFromEnd(){
		if(isEmpty()) {
			return;		
		}
		Node* temp = this->head;
		if (this->head->next == NULL) {
			delete temp;
			this->head = this->tail = NULL;
			return;
		}
		
		while(temp->next != NULL) {
			temp = temp->next;
		}
		this->tail = temp->previous;
		this->tail->next = NULL;
		delete temp;
		
	}

	int frontElement(){
		if(isEmpty()) {
			return -1;		
		}
		return this->head->data ;
	}

	int backElement(){
		if(isEmpty()) {
			return -1;		
		}
		return this->tail->data ;
	}

	void traverseLinkedList(){
		if (this->head == NULL) {
			return ;
		}
		Node* temp = this->head;
		while(temp != NULL) {
			cout << temp->data<<"  ";
			temp = temp->next; 
		}
		cout << endl;
	}
};


class DoublyEndedQueue: protected DoublyLinkedList {
public:
	void pushFront(int data) {
		this->insertAtStart(data);
	}
	void pushBack(int data) {
		this->insertAtEnd(data);
	}
	void popFront() {
		this->deleteFromStart();	
	}
	void popBack(){
		this->deleteFromEnd();
	}
	void peekFront(){
		if (this->frontElement() == -1) {
			cout << "connot peek front element."<< endl;
			return;
		}
		cout << this->frontElement() << endl;
	}

	void peekBack() {

		if (this->backElement() == -1) {
			cout << "connot peek front element."<< endl;
			return;
		}
		cout << this->backElement() << endl;

	}

	void traverseQueue() {
		this->traverseLinkedList();
	}
};


int main(int argc, char const *argv[])
{
	DoublyEndedQueue q1;
	q1.pushFront(10);
	q1.pushFront(30);
	q1.pushBack(20);
	q1.peekFront();
	q1.peekBack();
	q1.traverseQueue();
	q1.popFront();
	q1.popBack();
	q1.popFront();
	q1.traverseQueue();
	return 0;
}