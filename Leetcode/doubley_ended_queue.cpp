#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int d) {
		this->data  = d;
	}
};

class CircularLinkedList {
public:
	Node* head ;
	Node* tail ;
	CircularLinkedList() {
		this->head = NULL;
		this->tail = NULL;
	}

	bool isEmpty() {
		if (head == NULL) {
			return true;
		} else {
			return false;
		}
	}

	void insertAtStart(int d) {
		Node* n = new Node(d);
		if (isEmpty()) {
			this->head = this->tail = n;
			this->head->next = n;
		} else {
			n->next = this->head ;
			this->head = n;
			this->tail->next = head; 
		}
	}

	void insertAtLast(int d) {
		Node* n = new Node(d);
		if (isEmpty()) {
			this->head = this->tail = n;
			this->head->next = n;
		} else {
			this->tail->next = n;
			this->tail = n;
			this->tail->next = head;
		}
	} 

	void deleteFromStart() {
		if (isEmpty()) {
			return;
		} else {
			if (this->head->next == this->head) {
				cout << this->head->data;
				this->head = this->tail = NULL ;
			}
			else{
				cout << this->head->data;
				this->head = this->head->next;
				this->tail->next = this->head;
			}
			
		}
	}

	void deleteFromLast() {
		if (isEmpty()) {
			return;
		} else {
			Node* temp = head;
			while(temp->next != tail){
				temp = temp->next; 
			}
			this->tail = temp;
			this->tail->next = this->head;
			delete temp;
		}
	}

	void traverseList() {
		if (isEmpty()) {
			return;
		} else {
			Node* temp = this->head;
			while(temp->next != this->head) {
				cout << temp->data << " ";
				temp = temp->next ;
			}
			cout << temp->data<<endl;
		}
	}
};


class Queue : public CircularLinkedList {
public:

	void push_at_last(int element) {
		this->insertAtLast(element);
	}

	void push_at_front(int element) {
		this->insertAtStart(element);
	}
	
	void pop_from_front() {
		if (isEmpty()) {
			cout <<"Empty Queue." << endl;
			return;
		} else {
			this->deleteFromStart();
		}
		cout << endl;
	}


	void pop_from_end() {
		if (isEmpty()) {
			cout <<"Empty Queue." << endl;
			return;
		} else {
			this->deleteFromLast();
		}
		cout << endl;
	}

	void peek_front() {
		if (this->isEmpty())
		{
			cout <<"Empty Queue." << endl;
			return;
		}else {
			cout << this->head->data << endl;
		}
	}

	void peek_end() {
		if (this->isEmpty())
		{
			cout <<"Empty Queue." << endl;
			return;
		}else {
			cout << this->tail->data << endl;
		}

	}

	void traverseQueue() {
		if (isEmpty()) {
			cout <<"Empty Queue."<< endl;
			return;
		} else{
			this->traverseList();
		}
		cout << endl;
	}

};

int main() {
	Queue q1;
    cout << "_______Implementation of queue using circular linked list ________" << endl;

    int choice;
    char more;
    int element;
    do
    {
        cout<<"(i)push in front of queue"<<endl
            <<"(ii)push in back of queue "<<endl
            <<"(iii)Peek front of the queue "<<endl
            <<"(iv)peek back of the queue" <<endl
            <<"(v)Pop front of the queue "<<endl
            <<"(vi)pop back of the queue" <<endl
            <<"(vii)Traverse the queue"<<endl
            <<"(viii)Exit the program"<<endl;


         cout <<"Enter your choice : ";
         cin >>choice;

        switch(choice){
        	case 1:
        		cout <<"Enter the element you want to push : ";
        		cin >>element;
        		q1.push_at_front(element);
        		break;
        		
        	case 2:
        		cout <<"Enter the element you want to push : ";
        		cin >>element;
        		q1.push_at_last(element);
        		break;

        	case 3:	
        		q1.peek_front();
        		break;

        	case 4:
        		q1.peek_end();
        		break;

        	case 5:	
        		q1.pop_from_front();
        		break;

        	case 6:
        		q1.pop_from_end();

        		break;
        	case 7:
        		q1.traverseQueue();
        		break;

        	case 8:
        		cout << "Exitting the program "<<endl;
        		return 0;
        	default :
        		return 0;
        }
        
        cout<<"Do you want to continue (press n/N to exit) : ";
        cin.clear();
        cin >> more;
        cout << endl<< endl;
    } while (more != 'n' && more != 'N');
 
 	return 0;   
}
