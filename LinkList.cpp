#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int value;
    Node *Next;

    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};
void insertAtTail(Node *&head, int val);
void insertAtHead(Node *&head, int val);
void display(Node *n);
int countLength(Node *&head);
void insertionAtSpecificPosition(Node *&head, int pos);
void searchByValueDuplicate(Node *&head, int key);
int searchByValueUnique(Node *&head, int key);

//
void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}
//
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    //
    newNode->Next = head;
    //
    head = newNode;
}
//
void insertionAtSpecificPosition(Node *&head, int pos, int value)
{
    int i = 0;
    Node *temp = head;

    while (i < pos - 2)
    {
        temp = temp->Next;
        i++;
    }
    Node *newNode = new Node(value);
    newNode->Next = temp->Next;
    temp->Next = newNode;
}
// countLength
int countLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->Next;
    }
    return count;
}
// print
void display(Node *n)
{

    while (n != NULL)
    {

        cout << n->value;
        if (n->Next != NULL)
        {
            cout << " -> ";
        }
        n = n->Next;
    }
    cout << endl
         << endl;
}
//
int searchByValueUnique(Node *&head, int key)
{
    Node *temp = head;
    int count = 1;
    // if value is mt
    if (temp == NULL)
    {
        return -1;
    }

    while (temp->value != key)
    {
        // if value is not found
        if (temp->Next == NULL)
        {
            return -1;
        }

        temp = temp->Next;
        count++;
    }
    return count;
}
// duplicate
void searchByValueDuplicate(Node *&head, int key)
{
    Node *temp = head;
    int size;
    size = countLength(head);

    int position[size + 1], k = 1;
    int count = 1;
    int flag = 0;

    while (temp != NULL)
    {
        if (temp->value == key)
        {
            // cout << count << " ";
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }
    if (flag == 0)
    {
        cout << "The Search value not yet in the List" << endl;
    }
    else
    {
        position[0] = k;
        cout << "The value found at Position: ";
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if (i < position[0] - 1)
                cout << " , ";
        }
        cout << endl;
    }
}
int main()
{
    Node *head = NULL;
    int value, position;
    // Choice 1: Insertion at Head
    // Choice 2: Insertion at Tail
    // Choice 3: Insertion at Specific Position
    cout << "Choice 1: Insertion at Head" << endl
         << "Choice 2: Insertion at Tail" << endl
         << "Choice 3: Insertion at Specific Position" << endl
         << "Choice 4: Search a Value (Unique List)" << endl
         << "Choice 5: Search a Value (Duplication enabled List)" << endl
         << "Choice 0: Exit" << endl;
    cout << "Next Choice: ";
    int choice;
    cin >> choice;

    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 3:
            cout << "Enter the Desired Position: ";
            cin >> position;
            cout << "Enter the value: ";
            cin >> value;
            insertionAtSpecificPosition(head, position, value);
            break;
        case 4:
            cout << "Enter the value to Search: ";
            cin >> value;
            position = searchByValueUnique(head, value);
            if (position != -1)
            {
                cout << "The Number is at Position: " << position << endl;
            }
            else
            {
                cout << "The number is not yet in the List" << endl;
            }
            break;
        case 5:
            cout << "Enter the value to Search: ";
            cin >> value;

            // cout << "The Number is at Position: ";
            searchByValueDuplicate(head, value);
            // if (position != -1)
            // {
            //     cout << "The Number is at Position: " << position << endl;
            // }
            // else
            // {
            //     cout << "The number is not yet in the List" << endl;
            // }
            break;

        default:
            break;
        }

        cout << "Next Choice: ";
        cin >> choice;
    }
    cout << "Link List: ";
    display(head);

    cout << "Length of the list: " << countLength(head) << endl;

    return 0;
}