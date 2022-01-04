#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		Node* next = NULL;
	}
};

class SinglyLinkedList {
public:
	Node* head;
	Node* tail;
	SinglyLinkedList(){
		this->head = NULL;
		this->tail = NULL;
	}

	void insertAtStart(int data );
	void insertAtEnd(int data);
	void deleteFromStart();
	void deleteFromEnd();
	void deleteItem(int data );
	void display();
	bool isEmpty();
	void reverseList();
	void deleteList();
	void findMiddleElement();
	bool detectLoops();
	int countNodesInLoop(Node * ptr);
};

int SinglyLinkedList :: countNodesInLoop(Node* ptr) {
	int count = 1;
	Node* temp = ptr->next;
	if (temp = ptr) {
		return count;
	}
	while(temp != ptr) {
		count++;
	}
	return count;
}

bool SinglyLinkedList :: detectLoops() {
	bool found = false;
	Node* slow_p;
	Node* fast_p;
	slow_p = fast_p = this->head;
	while(fast_p == NULL && fast_p->next == NULL) {
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p) {
			found = true;
		}
	}
	if (found = true) {
		cout << countNodesInLoop(slow_p);
	}
	return found;
}


bool SinglyLinkedList :: isEmpty() {
	if (this->head == NULL) {
		return true;
	}
	return false;
}

void SinglyLinkedList :: insertAtStart(int data) {
	Node* n = new Node(data);
	if (this->isEmpty()) {
		this->head = this->tail = n;
		return;
	}
	n->next = this->head;
	this->head = n;
	return;
}

void SinglyLinkedList :: insertAtEnd(int data) {
	Node* n = new Node(data);
	if (this->isEmpty()) {
		this->head = this->tail = n;
		return;
	}
	this->tail->next = n;
	this->tail = n;
}

void SinglyLinkedList :: deleteFromStart() {
	if (this->isEmpty()) {
		return;
	}
	if (this->head == this->tail) {
		Node* temp = this->head;
		delete temp;
		return;
	}
	Node* temp = this->head;
	this->head = this->head->next;
	delete temp;
	return;
}

void SinglyLinkedList :: deleteFromEnd() {
	if (this->isEmpty()) {
		return;
	}
	if (this->head == this->tail) {
		Node* temp = this->tail;
		this->head = this->tail = NULL;
		delete temp;
		return;
	}
	Node* temp = this->tail;
	Node* temp1 = this->tail;
	while(temp1->next != this->tail){
		temp1 = temp1->next;
	}
	this->tail = temp1;
	delete temp;
	return;
}

void SinglyLinkedList :: deleteItem(int data){
	if (this->isEmpty()) {
		return;
	} 
	Node* temp = this->head;
	Node* tempPrev = NULL;
	bool found = false;
	while(temp != NULL) {
		if (temp->data == data) {
			found = true;
			break;
		}
		tempPrev = temp;
		temp = temp->next;
	}
	if (found == true) {
		if (tempPrev == NULL) {
			this->head = this->tail = NULL;
			delete temp;
		} else {
			tempPrev->next = temp->next;
			temp->next = NULL;
			delete temp;
		}
	} else{
		cout << "data not found";
	}
}

void SinglyLinkedList :: display(){
	if (this->isEmpty()) {
		return;
	}
	Node* temp = this->head;
	while(temp != NULL) {
		cout << temp->data<<" ";
		temp = temp->next;
	}
}

void SinglyLinkedList :: reverseList() {
	if ( this->isEmpty()) {
		return;
	}
	Node * newHead = this->tail;
	Node* newTail = this->head;
	Node* temp = this->head;
    Node *prev = NULL, *store = temp;
    while(temp != NULL) {
    	store = store->next;
    	temp->next = prev;
    	prev = temp;
    	temp = store;	
    }
    Node* temp1 = this->head;
    this->head = this->tail;
    this->tail = temp1;
}

void SinglyLinkedList :: deleteList() {
	Node * temp = head; 
	while(head != NULL) {
		temp = head ;
		head = head->next ;
		delete temp;
	}
}

void SinglyLinkedList ::findMiddleElement() {
	Node* slow_p;
	Node* fast_p;
	slow_p = fast_p = this->head;
	while(fast_p != NULL && fast_p != this->tail) {
		fast_p = fast_p->next->next;
		slow_p = slow_p->next;
	}
	cout << "Middle element is : " << slow_p->data<< endl;
}

int main() {
	SinglyLinkedList s;
	s.insertAtEnd(10);
	s.insertAtEnd(20);
	s.insertAtEnd(30);
	s.insertAtEnd(40);
	s.insertAtEnd(50);
	s.display();
	// cout << s.detectLoops();
	// s.reverseList();
	s.findMiddleElement();
	// s.deleteFromStart();
	// s.deleteItem(20);
	s.display();
	return 0;
}
