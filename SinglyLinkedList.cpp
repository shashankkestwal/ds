#include <bits/stdc++.h>
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
	void pairWiseSwap();
	bool checkPalindrome();
	Node* findMiddleNode();
	void reverseListFromIndex(Node* index);
	void removeDuplicatesIfSorted();
	void removeDuplicates();
	// void revertReversal(Node* index );

	// void swap(Node* temp1, Node* temp2);

	int getLength() {
		return getLengthFromNode(head);
	}

	int getLengthFromNode(Node * ptr) {
		if(ptr == NULL) {
			return 0;
		} else {
			return 1 + getLengthFromNode(ptr->next);
		}
	}
};

Node* SinglyLinkedList :: findMiddleNode() {
	Node* slow_p = this->head;
	Node* fast_p = this->head;
	while(fast_p != NULL && fast_p != tail) {
		fast_p = fast_p->next->next;
		slow_p = slow_p->next;
	}
	return slow_p;
}

void SinglyLinkedList :: reverseListFromIndex(Node* index) {
	Node* prev = NULL;
	Node* curr = index->next;
	Node* new_tail = curr;
	Node* temp = curr->next;
	while(temp != NULL ){
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	index->next	= this->tail;
	this->tail = new_tail;
}

// void SinglyLinkedList :: revertReversal(Node* index) {
// 	Node* temp1 = this->tail;
// 	Node* new_tail = index->next;
// 	Node* prev = NULL;
// 	Node* curr = index->next;
// 	Node* temp = curr->next;
// 	while(temp != NULL) {

// 	}
// }

bool SinglyLinkedList :: checkPalindrome() {
	bool value = true;
	Node* middle = this->findMiddleNode();
	this->reverseListFromIndex(middle);
	
	Node* temp1 = this->head;
	Node* temp2 = middle->next;
	while(temp1 != middle && temp2 != NULL) {
		if (temp1->data != temp2->data) {
			value = false;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	this->reverseListFromIndex(middle);
	

	if (temp1 == middle && temp2 == NULL) {
		return value;
	} else if(temp1 != middle ) {
		return value;
	} 

	return value;
}


void SinglyLinkedList :: pairWiseSwap() {
	Node* temp1;
	Node* temp2 = NULL;
	Node* behind = this->head ;
	if (behind->next == NULL) {
		return;
	}
	Node* after = behind->next;
	int step = 0;

	while(behind != NULL && after != NULL) {
		cout << behind->data <<"  "<< after->data << endl;
		temp1 = after->next;
		if (behind == this->head) {
			this->head = after;
		}
		if (after == this->tail) {
			this->tail = behind;
		}


		if (step != 0) {
			temp2->next = after;
			after->next = behind;
			behind->next = temp1;
			temp2 = behind;		
		} else {
			temp2 = behind;
			after->next = behind;
			behind->next = temp1;
		}
		
		if (temp1 == NULL) {
			break;
		}
		behind = temp1;
		after = temp1->next;
		step++;
	}
}

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
	cout << endl;
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
	cout <<"Middle element is : " << slow_p->data<< endl;
}

void SinglyLinkedList :: removeDuplicatesIfSorted() {
	Node* temp = this->head;
	while(temp->next != NULL) {
		if (temp->next->data == temp->data) {
			Node* duplicate = temp->next;
			temp->next = duplicate->next;
			duplicate->next = NULL;
			delete(duplicate);
			continue;
		} 
		temp = temp->next;
	}
}

void SinglyLinkedList :: removeDuplicates() {
	unordered_set<int> set;
	if (this->head == NULL) {
		return;
	}
	Node* temp = this->head;
	Node* prev = temp;
	while(temp != NULL) {
		if (set.empty()) {
			set.insert(temp->data);
		} else{
			if (set.count(temp->data)) {
				prev->next = temp->next;
				temp->next = NULL;
				delete(temp);
				temp = prev;
			} else {
				set.insert(temp->data);
			}
		}
		prev = temp;
		temp = temp->next;
	}
}



SinglyLinkedList intersectionLinkedList(SinglyLinkedList s1, SinglyLinkedList s2) {
	Node* temp1 = s1.head;
	Node* temp2 = s2.head;
	SinglyLinkedList s3;
	while(temp1 != NULL && temp2 != NULL) {
		if (temp1->data == temp2->data) {
			if (s3.tail == NULL) {
				s3.insertAtEnd(temp1->data);
			} else if(s3.tail->data != temp1->data){
				s3.insertAtEnd(temp1->data);
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		} else if (temp1->data > temp2->data) {
			temp2 = temp2->next;
		} else if (temp2->data > temp1->data) {
			temp1 = temp1->next;
		}
	}
	return s3;
} 


int main() {
	SinglyLinkedList s;
	s.insertAtEnd(10);
	s.insertAtEnd(10);
	// s.insertAtEnd(10);
	s.insertAtEnd(20);
	s.insertAtEnd(20);
	s.insertAtEnd(20);
	s.insertAtEnd(30);
	s.insertAtEnd(30);
	s.insertAtEnd(40);
	s.insertAtEnd(40);


	s.display();
	
	// cout << "palindrome :" <<s.checkPalindrome() << endl;
	// // s.reverseListFromIndex();
	// // s.pairWiseSwap();
	// // cout << s.detectLoops();
	// // s.reverseList();
	// s.findMiddleElement();
	// // s.deleteFromStart();
	// // s.deleteItem(20);
	// s.display();
	// s.removeDuplicates();
	// // s.removeDuplicatesIfSorted();
	// s.display();






	SinglyLinkedList s1;
	s1.insertAtEnd(10);
	s1.insertAtEnd(10);
	s1.insertAtEnd(20);
	s1.insertAtEnd(30);
	s1.insertAtEnd(40);
	s1.display();


	SinglyLinkedList intersectedList = intersectionLinkedList(s,s1);
	intersectedList.display();


	return 0;
}
