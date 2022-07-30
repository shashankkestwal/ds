#include <iostream>
using namespace std;

class Node{
public:
	string data;
	Node* next;
	Node(string data) {
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

	void insertAtStart(string data );
	
	
	void deleteItem(string data );
	void display();
	bool isEmpty();
	
	void insertAtPosition(string data);
	bool searchInList(string data);
};

bool SinglyLinkedList :: isEmpty() {
	if (this->head == NULL) {
		return true;
	}
	return false;
}

void SinglyLinkedList :: insertAtStart(string data) {
	Node* n = new Node(data);
	if (this->isEmpty()) {
		this->head = this->tail = n;
		return;
	}
	n->next = this->head;
	this->head = n;
	return;
}


void SinglyLinkedList :: deleteItem(string data){
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
			this->head = this->head->next;
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
		cout << temp->data << endl;
		temp = temp->next;
	}
}


bool SinglyLinkedList :: searchInList(string data) {
	if (this->isEmpty()) {
		return false;
	}
	Node* temp = this->head;
	while(temp != NULL) {
		if (temp->data == data) {
			return true;
		}
		temp=  temp->next;
	}
	return false;

}

void SinglyLinkedList :: insertAtPosition(string data) {
	if (this->isEmpty()) {
		insertAtStart(data);
		return;
	} 
	Node* prev ;
	Node* temp = this->head;
	while(temp != NULL) {
		if (temp->data > data) {
			break;
		}
		prev = temp;
		temp = temp->next;
	}

	if (prev == NULL) {
		insertAtStart(data);
		return;
	}
	Node * n = new Node(data);
	n->next = temp;
	prev->next = n;
}


class TicketReservation : public SinglyLinkedList{
public:
	void reserve_ticket(string passengerName) {
		this->insertAtPosition(passengerName);
		return;
	}
	void cancelTicket(string passengerName) {
		this->deleteItem(passengerName);
	}

	void searchPassenger(string passengerName) {
		if (searchInList(passengerName)) {
			cout << "Passenger is reserved !"<<endl;
		} else {
			cout <<"No reservation from passenger named passenger !"<<endl;
		}
	}
	void seeAllPassengers() {
		display();
	}
};


int main() {
	cout << "TICKET RESERVATION SYSTEM" << endl;
	
	int choice;
	char conti;
	string psName;
	TicketReservation tr;
	do{
		cout << "1. reserve a ticket.\n";
		cout <<"2. cancel a reservation\n";
		cout <<"3. check whether a ticket is reserved for a particular person.\n";
		cout <<"4. display the passenger list." << endl;
		cout << "Enter your choice " << endl;
		cin >> choice;
		switch (choice) {
			case 1:
				cout << "Enter the name of passenger" << endl;
				cin >> psName;
				tr.reserve_ticket(psName);
				break;

			case 2:
				cout << "Enter the name of passenger" << endl;
				cin >> psName;
				tr.cancelTicket(psName);
				break;
			case 3:
				cout << "Enter the name of passenger" << endl;
				cin >> psName;
				tr.searchPassenger(psName);
				break;
			case 4:
				tr.seeAllPassengers();  
				break;
			default:
				break;
		}
		cin >> conti;
	} while(conti !='n' && conti != 'N');
	return 0;
}
