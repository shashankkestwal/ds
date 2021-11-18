#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *previous;
    node(int el)
    {
        data = el;
        next = NULL;
        previous = NULL;
    }
};

class DoublyLinkedList
{
public:
    node* head ;

    DoublyLinkedList(){
        this->head = NULL;
    }


    void insertAtHead(int el)
    {
        node *n = new node(el);

        if (head == NULL)
        {
            head = n;
            return;
        }
        node *temp = head;
        head = n;
        temp->previous = head;
        head->next = temp;
    }


    void insertAtTail(int el)
    {
        node *n = new node(el);
        if (head == NULL)
        {
            insertAtHead(el);
            return;
        }

        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->previous = temp;
    }


    void display()
    {
        node *temp = head;
        if (temp == NULL)
        {
            cout << "Empty linked list" << endl;
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "null" << endl;
        }
    }
    

    void insertAtPosition( int el, int pos)
    {

        if (pos == 1)
        {
            insertAtHead( el);
            return;
        }
        node *n = new node(el);
        node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
            if (temp->next == NULL)
            {
                cout << "List is shorter then the input index " << endl;
                return;
            }
        }
        n->next = temp->next;
        temp->next->previous = n;
        n->previous = temp;
        temp->next = n;
    }


    void deleteFromHead()
    {
        if (head == NULL)
        {
            cout << "Operation not possible" << endl;
            return;
        }
        node *temp = head;
        head = temp->next;
        head->previous = NULL;
        cout << "Element successfully deleted from head" << endl;
    }
    


    void deleteFromTail()
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->previous->next = NULL;
        temp->previous = NULL;
    }


    void deleteFromPosition(int pos)
    {

        if (head == NULL)
        {
            cout << "Operation not possible" << endl;
            return;
        }
        if (pos == 1)
        {
            deleteFromHead();
        }

        node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp->next == NULL)
            {
                if (pos - 1 == i)
                {
                    deleteFromTail();
                }
                else
                {
                    cout << "List is shorter then the input index " << endl;
                }
                return;
            }
        }
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
        cout << "Element successfully deleted from desired position " << endl;
    }


    void searchInList(int el)
    {
        node *temp = head;
        if (head == NULL)
        {
            cout << "Operation not possible" << endl;
            return;
        }

        bool isPresent = false;
        int i = 1;
        while (temp != NULL)
        {
            if (temp->data == el)
            {
                cout << "Element found at index " << i << endl;
                cout << "Its next pointer is " << temp->next << endl;
                cout << "Its previous pointer is " << temp->previous << endl;
                isPresent = true;
            }
            temp = temp->next;
            i++;
        }
        if (!isPresent)
        {
            cout << "Element not found in the linked list" << endl;
        }
    }


    node* createSecondLinkedList()
    {
        this->insertAtTail(1);
        this->insertAtTail(2);
        this->insertAtTail(3);
        cout << "Second linked list is created " << endl;
        return this->head;
    }


    void concatenateDoublyLinkedList()
    {
        node *temp = head;
        DoublyLinkedList dll2;
        node *head2 = dll2.createSecondLinkedList();
        if (head == NULL)
        {
            cout << "Linked list is empty.\tConcatenation not possible " << endl;
            return;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            cout << endl << temp->data <<"  "<< head2->data<<endl;
            temp->next = head2;
            head2->previous = temp;
            cout << "Two lists has been concatenated" << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    cout << "-------CPP program implementing a linked list------- " << endl
         << endl;

    
    cout << "An empty linked list is created" << endl;

    cout << "(i) Insert an element x at the front of the doubly linked list" << endl
         << "(ii) Insert an element x at position in the doubly linked list" << endl
         << "(iii)Insert an element x at the end of the doubly linked list" << endl
         << "(iv) Remove an element from the beginning of the doubly linked list" << endl
         << "(v) Remove an element from position in the doubly linked list." << endl
         << "(vi) Remove an element from the end of the doubly linked list" << endl
         << "(vii) Search for an element x in the doubly linked list and return its pointer" << endl
         << "(viii) Concatenate two doubly linked lists " << endl;

    DoublyLinkedList dll;

    char more;
    int element;
    int position;
    do
    {
        int choice;
        cout << "Enter which operation you want to peform : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element you want to enter : ";
            cin >> element;
            dll.insertAtHead(element);
            cout << "Element successfully inserted at head" << endl;
            dll.display();
            break;
        case 2:

            cout << "Enter the element you want to enter : ";
            cin >> element;
            cout << "Enter the postion of the element you want to insert : ";
            cin >> position;
            if (position == 1)
            {
                dll.insertAtHead(element);
            }
            else
            {
                dll.insertAtPosition(element, position);
            }

            dll.display();
            break;
        case 3:
            cout << "Enter the element you want to insert at tail :";
            cin >> element;
            dll.insertAtTail(element);
            dll.display();
            break;
        case 4:
            dll.deleteFromHead();
            dll.display();
            break;
        case 5:
            cout << "Enter the position of element  you want to remove from the linked list :";
            cin >> position;
            dll.deleteFromPosition( position);
            dll.display();
            break;
        case 6:
            dll.deleteFromTail();
            dll.display();
            break;
        case 7:
            cout << "Enter the element you want to search in the list :";
            cin >> element;
            dll.searchInList( element);
            dll.display();
            break;

        case 8:
            dll.concatenateDoublyLinkedList();
            dll.display();
            break;

        // default:
        //     cin.clear();
        //     cout << "Invalid input" << endl;
        //     break;
        }
        cout << "Do you want to continue operations on linked list. Press n/N to exit :";
        cin >> more;
        cout << endl
             << endl;
    } while (more != 'n' && more != 'N');

    return 0;
}

