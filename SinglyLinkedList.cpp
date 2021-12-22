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
};

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

int main() {
	SinglyLinkedList s;
	s.insertAtStart(10);
	s.insertAtEnd(20);
	s.deleteFromStart();
	s.deleteItem(20);
	s.display();
	return 0;
}