#include <iostream>
using namespace std;



class Node
{
public:
    
    int data;
    Node *next;

    Node(int el)
    {
        data = el;
        next = NULL;
    }
};

class circularLinkedList {
public:
    Node *head;

    circularLinkedList() {
        this->head = NULL;
    }

    
    void insertAtHead(int el)
    {
        Node *n = new Node(el);
        if (this->head == NULL)
        {
            this->head = n;
            this->head->next = this->head;
        }

        Node *last_element = this->head;
        while (last_element->next != this->head)
        {
            last_element = last_element->next;
        }

        n->next = this->head;
        last_element->next = n;
        this->head = n;

    }

    
    void display()
    {
        if (this->head == NULL)
        {
            cout << "Empty linked list" << endl;
            return;
        }

        Node *temp = this->head;

        if (temp->next == this->head)
        {
            cout << temp->data;
        }
        else
        {
            while (temp->next != this->head)
            {
                cout << temp->data;
                cout << "->";
                temp = temp->next;
            }
            cout << temp->data;
        }
        cout << endl;
    }

    
    int search_in_list(int el)
    {
        int position = 1;
        if (this->head == NULL)
        {
            return -1;
        }
        Node *temp = this->head;
        do
        {
            if (temp->data == el)
            {
                return position;
            }
            temp = temp->next;
            position++;
        } while (temp != head);
        return -1;
    }

    
    void insertAfterPosition( int elementToEnter, int pos)
    {
        if (pos == -1)
        {
            return;
        }
        else
        {
            if (this->head == NULL)
            {
                cout << "List is empty";
                return;
            }
            Node *n = new Node(elementToEnter);
            Node *temp = head;
            for (int i = 1; i < pos; i++)
            {
                if (temp->next == this->head)
                {
                    cout << "List is shorter then the input index " << endl;
                    return;
                }
                temp = temp->next;
            }
            Node *newTemp = temp->next;
            temp->next = n;
            n->next = newTemp;
        }
    }

    
    void insertAtEnd( int elementToEnter)
    {
        Node *n = new Node(elementToEnter);
        if (this->head == NULL)
        {
            insertAtHead(elementToEnter);
            return;
        }

        Node *temp = this->head;
        do
        {
            temp = temp->next;
        } while (temp->next != head);
        temp->next = n;
        n->next = this->head;
        
    }

    
    void deleteFromStart()
    {
        if (this->head == NULL)
        {
            cout << "Operation not possible" << endl;
            return;
        }

        Node *temp = this->head;

        while (temp->next != this->head)
        {
            temp = temp->next;
        }
        if (temp == this->head) {
            delete head;
            return ;
        } else{
            Node* old_head = this->head;
            this->head = old_head->next;
            temp->next = this->head;
            delete old_head;
        }
    }
    
    void deleteFromEnd()
    {
        if (this->head == NULL)
        {
            cout << "Operation not possible" << endl;
            return;
        }
        else if (this->head->next == this->head)
        {
            delete this->head;
        }
        else
        {
            Node *temp = this->head;
            while (temp->next->next != head)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = this->head;
        }
    }

    
    void removeNodeWithGivenElement(int pos)
    {

        if (pos == -1)
        {
            cout << "Operation not possible" << endl;
            
        }
        else if (pos == 1)
        {
            deleteFromStart();
        }
        else
        {
            Node *temp = this->head;
            for (int i = 1; i < pos - 1; i++)
            {
                if (temp->next == head)
                {
                    cout << "List is shorter then the input index " << endl;
                }
                temp = temp->next;
            }

            temp->next = temp->next->next;
            
        }
    }

    
    void printPointerOfPos( int pos)
    {

        Node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            if (temp->next == this->head)
            {
                cout << "List is shorter then the input index " << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Element found at position " << pos << " and its pointer is ";
        cout << temp->next << endl;
    }

    
    Node* createNewLinkedList() {
        this->insertAtHead(30);
        this->insertAtHead(20);
        this->insertAtHead(10);
        return this->head;
    }

    
    void concatenateTwoLinkedLists()
    {
        if (this->head == NULL)
        {
            cout << "Empty linked list cannot be concatenated " << endl;
            return;
        }
        else
        {
            Node *temp1 = this->head;
            circularLinkedList cll2;
            Node *temp2 = cll2.createNewLinkedList();
            Node *head2 = temp2;

            while (temp1->next != head) {
                temp1 = temp1->next;
            }
            temp1->next = temp2;
            while (temp2->next != head2)
            {
                temp2 = temp2->next;
            }
            temp2->next = this->head;
            cout << "Both linked list concatenated successfully" << endl;
        }
    }
    
};

int main(int argc, char const *argv[])
{

    cout << "-------CPP program implementing a linked list------- " << endl
         << endl;
    
    circularLinkedList cll;
    char more;
    int element, position, search;

    do
    {
        cout << "(i) Insert an element at the beginning of the circular linked list" << endl
             << "(ii) Insert an element x after an element y in the circular linked list" << endl
             << "(iii)Insert an element at the end of the circular linked list" << endl
             << "(iv) Remove an element from the back of the circular linked list." << endl
             << "(v) Remove an element from the front of the circular linked list." << endl
             << "(vi) Remove the element from the circularly linked list " << endl
             << "(vii)Search for an element from the circularly linked list and return its pointer" << endl
             << "(viii) Concatenate two circularly linked lists" << endl
             << endl; 

        int choice;
        cout << "Enter which operation you want to peform : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element you want to enter : ";
            cin >> element;

            cll.insertAtHead( element);

            cout << "Element successfully inserted at head" << endl;
            cll.display();
            break;
        case 2:

            cout << "Enter the element you want to enter : ";
            cin >> element;
            cout << "Enter the element whose next the given element  must reside : ";
            cin >> search;

            if (cll.search_in_list(search) == -1)
            {
                cout << "No element as " << search << " in the list" << endl;
                break;
            }

            cll.insertAfterPosition( element, cll.search_in_list(search));
            cll.display();
            break;
        case 3:
            cout << "Enter the element you want to enter : ";
            cin >> element;
            cll.insertAtEnd(element);
            cll.display();
            break;
        case 4:
            cll.deleteFromStart();
            cll.display();
            break;
        case 5:
            cll.deleteFromEnd();
            cll.display();
            break;
        case 6:
            cout << "Enter Element you want to remove :";
            cin >> search;
            cll.removeNodeWithGivenElement(cll.search_in_list(search));
            cll.display();
            break;
        case 7:
            cout << "Enter which element's pointer you want to print :";
            cin >> search;
            position = cll.search_in_list( search);
            if (position == -1)
            {
                cout << "Element Not found in the list " << endl;
                break;
            }
            else
            {
                cll.printPointerOfPos( position);
            }
            break;
        case 8:
        {
            cll.concatenateTwoLinkedLists();
            cll.display();
            break;
        }
        

        default:
            cin.clear();
            cout << "Invalid input" << endl;
            break;
        }
        cout << "Do you want to continue operations on linked list, press n/N to exit : ";
        cin >> more;

        cout << endl
             << endl;
    } while (more != 'n' && more != 'N');
    return 0;
}
