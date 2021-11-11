#include <iostream>
using namespace std;
 
template <typename T>
class node
{
public:
    T data;
    node *next;
    node *previous;
    node(T el)
    {
        data = el;
        next = NULL;
        previous = NULL;
    }
};

class DoublyLinkedList
{
public:

template <class T>
    void insertAtHead(node<T> *head, T el)
    {
        node<T> *n = new node<T>(el);

        if (head == NULL)
        {
            head = n;
            return;
        }
        node<T> *temp = head;
        head = n;
        temp->previous = head;
        head->next = temp;
    }

template <class T>
    void insertAtTail(node<T> *head, T el)
    {
        node<T> *n = new node<T>(el);
        if (head == NULL)
        {
            insertAtHead(head, el);
            return;
        }

        node<T> *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->previous = temp;
    }
template <class T>

    void display(node<T> *head)
    {
        node<T> *temp = head;
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
    template <class T>

    void insertAtPosition(node<T> *head, T el, int pos)
    {

        if (pos == 1)
        {
            insertAtHead(head, el);
            return;
        }
        node<T> *n = new node<T>(el);
        node<T> *temp = head;
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
template <class T>

    void deleteFromHead(node<T> *head)
    {
        if (head == NULL)
        {
            cout << "Operation not possible" << endl;
            return;
        }
        node<T> *temp = head;
        head = temp->next;
        head->previous = NULL;
        cout << "Element successfully deleted from head" << endl;
    }
    template <class T>


    void deleteFromTail(node<T> *head)
    {
        node<T> *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->previous->next = NULL;
        temp->previous = NULL;
    }
template <class T>

    void deleteFromPosition(node<T> *head, int pos)
    {

        if (head == NULL)
        {
            cout << "Operation not possible" << endl;
            return;
        }
        if (pos == 1)
        {
            deleteFromHead(head);
        }

        node<T> *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp->next == NULL)
            {
                if (pos - 1 == i)
                {
                    deleteFromTail(head);
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
template <class T>

    void searchInList(node<T> *head, T el)
    {
        node<T> *temp = head;
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
template <class T>

    void createSecondLinkedList(node<T> *head1)
    {

        insertAtTail(head1, 1);
        insertAtTail(head1, 2);
        insertAtTail(head1, 3);
        cout << "Second linked list is created " << endl;
        display(head1);
    }
template <class T>

    void concatenateDoublyLinkedList(node<T> *head, node<T> *head1)
    {
        node<T> *temp = head;
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
            temp->next = head1;
            head1->previous = temp;
            cout << "Two lists has been concatenated" << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    cout << "-------CPP program implementing a linked list------- " << endl
         << endl;

    node<int> *head = NULL;

    cout << "An empty linked list is created" << endl;

    cout << "(i) Insert an element x at the front of the doubly linked list" << endl
         << "(ii) Insert an element x at position in the doubly linked list" << endl
         << "(iii)Insert an element x at the end of the doubly linked list" << endl
         << "(iv) Remove an element from the beginning of the doubly linked list" << endl
         << "(v) Remove an element from position in the doubly linked list." << endl
         << "(vi) Remove an element from the end of the doubly linked list" << endl
         << "(vii) Search for an element x in the doubly linked list and return its pointer" << endl
         << "(viii) Concatenate two doubly linked lists " << endl;

    node<int> *head1 = NULL;
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
            dll.insertAtHead(head, element);
            cout << "Element successfully inserted at head" << endl;
            dll.display(head);
            break;
        case 2:

            cout << "Enter the element you want to enter : ";
            cin >> element;
            cout << "Enter the postion of the element you want to insert : ";
            cin >> position;
            if (position == 1)
            {
                dll.insertAtHead(head, element);
            }
            else
            {
                dll.insertAtPosition(head, element, position);
            }

            dll.display(head);
            break;
        case 3:
            cout << "Enter the element you want to insert at tail :";
            cin >> element;
            dll.insertAtTail(head, element);
            dll.display(head);
            break;
        case 4:
            dll.deleteFromHead(head);
            dll.display(head);
            break;
        case 5:
            cout << "Enter the position of element  you want to remove from the linked list :";
            cin >> position;
            dll.deleteFromPosition(head, position);
            dll.display(head);
            break;
        case 6:
            dll.deleteFromTail(head);
            dll.display(head);
            break;
        case 7:
            cout << "Enter the element you want to search in the list :";
            cin >> element;
            dll.searchInList(head, element);
            dll.display(head);
            break;
        case 8:
            dll.createSecondLinkedList(head1);
            dll.concatenateDoublyLinkedList(head, head1);
            dll.display(head);
            break;
        default:
            cin.clear();
            cout << "Invalid input" << endl;
            break;
        }
        cout << "Do you want to continue operations on linked list. Press n/N to exit :";
        cin >> more;
        cout << endl
             << endl;
    } while (more != 'n' && more != 'N');

    dll.display(head);
    return 0;
}
