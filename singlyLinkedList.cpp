#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int el)
    {
        data = el;
        next = NULL;
    }
};

void insertAtTail(node *&head, int el)
{
    node *n = new node(el);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    
}

void insertAtHead(node *&head, int el)
{
    node *n = new node(el);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    head = n;
    head->next = temp;
}

void insertAtPosition(node *&head, int el, int pos)
{
    node *n = new node(el);

    if (head == NULL)
    {
        cout << "Empty List\nOperation not possible" << endl;
        return;
    }

    node *temp1 = head;
    node *temp2;
    for (int i = 1; i < pos - 1; i++)
    {
        temp1 = temp1->next;
        if (temp1->next == NULL)
        {
            cout << "List is shorter then the input index " << endl;
            return;
        }
    }
    temp2 = temp1->next;
    temp1->next = n;
    n->next = temp2;
    cout << "Element successfully inserted at desired position " << endl;
}

void deleteFromHead(node *&head)
{
    if (head == NULL)
    {
        cout << "Operation not possible" << endl;
        return;
    }
    node *temp = head;
    head = temp->next;
    cout << "Element successfully deleted from head" << endl;
}

void deleteFromPosition(node *&head, int pos)
{

    if (head->next == NULL)
    {
        cout << "Operation not possible" << endl;
        return;
    }
    node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            cout << "List is shorter then the input index " << endl;
            return;
        }
    }
    temp->next = temp->next->next;
    cout << "Element successfully deleted from desired position " << endl;
}
void searchInList(node *&head, int el)
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
            cout << "Its pointer is " << temp << endl;
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

void display(node *&head)
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

void createSecondLinkedList(node *&head1)
{
    insertAtTail(head1, 1);
    insertAtTail(head1, 2);
    insertAtTail(head1, 3);
    cout << "Second linked list is created " << endl;
    display(head1);
}
void concatenate(node *&head, node *&head1)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head1;
    cout << "Second linked list successfully concatenated with the original one " << endl;
}

int main(int argc, char const *argv[])
{

    cout << "-------CPP program implementing a linked list------- " << endl
         << endl;
    node *head = NULL;
    cout << "An empty linked list is created" << endl;

    cout << "(i) Insert an element at the beginning of the singly linked list" << endl
         << "(ii) Insert an element at desired position in the singly linked list" << endl
         << "(iii)Remove an element from the beginning of the singly linked list" << endl
         << "(iv) Remove an element from position in the singly linked list." << endl
         << "(v) Search for an element in the singly linked list and return its pointer" << endl
         << "(vi) Concatenate two singly linked lists " << endl
         << endl;

    node *head1 = NULL;
    char more;
    int element, position;

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
            insertAtHead(head, element);
            cout << "Element successfully inserted at head" << endl;
            display(head);
            break;
        case 2:

            cout << "Enter the element you want to enter : ";
            cin >> element;
            cout << "Enter the postion of the element you want to insert : ";
            cin >> position;
            if (position == 1)
            {
                insertAtHead(head, element);
            }
            else
            {
                insertAtPosition(head, element, position);
            }

            display(head);
            break;
        case 3:
            deleteFromHead(head);

            display(head);
            break;
        case 4:
            cout << "Enter the postion of the element you want to delete the element : ";
            cin >> position;
            if (position == 1)
            {
                deleteFromHead(head);
            }
            else
            {
                deleteFromPosition(head,  position);
            }

            display(head);
            break;
        case 5:
            cout << "Enter the element you want to search in the linked list :";
            cin >> element;
            searchInList(head, element);
            display(head);
            break;
        case 6:

            createSecondLinkedList(head1);
            concatenate(head, head1);
            display(head);
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
        cout << "Do you want to continue operations on linked list(press n/N to exit ) : ";
        cin.clear();
        cin >> more;
        cout << endl
             << endl;
    } while (more == 'n' && more == 'N');

    return 0;
}


