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
//
struct Test
{
    int position[1000];
};

// void func
void insertAtTail(Node *&head, int val);
void insertAtHead(Node *&head, int val);
void display(Node *n);
int countLength(Node *&head);
void insertionAtSpecificPosition(Node *&head, int pos);
void searchByValueDuplicate(Node *&head, int key);
int searchByValueUnique(Node *&head, int key);
void deletionAtHead(Node *&head);
void deletionAtTail(Node *&head);
void deletionAtSpecificPosition(Node *&head);
void deletionByValueUnique(Node *&head, int value);
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
// search By Value
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
        cout << "The Searched Value not yet in the List" << endl;
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
//
Test searchByValueDuplicateReturn(Node *&head, int key)
{
    Node *temp = head;
    Test T;
    int k = 1;
    int count = 1;

    while (temp != NULL)
    {
        if (temp->value == key)
        {
            // cout << count << " ";
            T.position[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    T.position[0] = k;
    return T;
}
//
void searchByValueUnique(Node *&head, int searchValue, int value)
{
    // Step 1: Search the Position od the search
    int position; 
    position = searchByValueUnique(head, searchValue);

    // Step 2: Insert the value at the Position +1
    insertionAtSpecificPosition(head, position + 1, value);
};
// Deletion
void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        head = temp->Next;
        delete temp;
    }
    else
    {
        cout << "There is No Value in the Linked List" << endl;
    }
}
void deletionAtTail(Node *&head)
{
    Node *temp = head;

    if (temp != NULL && temp->Next != NULL)
    {
        while (temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }
        Node *delNode = temp->Next;
        temp->Next = NULL;
        delete delNode;
    }
    else
    {
        // Head is NULL
        if (temp == NULL)
        {
            cout << "There is No Value in the Linked List" << endl;
        }
        else
        {
            deletionAtHead(head);
        }
    }
}

void deletionAtSpecificPosition(Node *&head, int position)
{
    Node *temp = head;
    if (temp != NULL)
    {

        if (position == 1)
        {
            deletionAtHead(head);
        }
        else if (position == countLength(head))
        {
            deletionAtTail(head);
        }
        else
        {
            int i = 1;
            while (i < position - 1)
            {
                temp = temp->Next;
                i++;
            }
            Node *delNode = temp->Next;
            temp->Next = delNode->Next;
            delete delNode;
        }
    }
    else
    {
        if (position > countLength(head))
        {
            cout << "Position Out of Bound";
        }
        else
        {
            cout << "There  is No Value in the Link List " << endl;
        }
    }
}
// 10
void deletionByValueUnique(Node *&head, int value)
{
    // Find the position
    int position;
    position = searchByValueUnique(head, value);

    // Delete the Node at the position
    if (position == -1)
    {
        cout << "Value not Found in the link list";
    }
    else
    {
        deletionAtSpecificPosition(head, position);
    }
}
int main()
{
    Node *head = NULL;
    int value, position;
    cout << "Choice 1: Insertion at Head" << endl
         << "Choice 2: Insertion at Tail" << endl
         << "Choice 3: Insertion at Specific Position" << endl
         << "Choice 4: Search a Value (Unique List)" << endl
         << "Choice 5: Search a Value (Duplication enabled List)" << endl
         << "Choice 6: Insertion after a specific value (Unique List)" << endl
         << "Choice 7: Deletion at Head" << endl
         << "Choice 8: Deletion at Tail" << endl
         << "Choice 9: Deletion at a Specific Position" << endl
         << "Choice 10: Deletion By Value (Unique List)" << endl
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
            Test T;
            T = searchByValueDuplicateReturn(head, value);
            if (T.position[0] == 1)
            {
                cout << "The Searched Value not yet in the List" << endl;
            }
            else
            {
                int size = T.position[0];
                cout << "The value found at Position: ";
                for (int i = 0; i < size; i++)
                {
                    cout << T.position[i];
                    if (i < size - 1)
                    {
                        cout << ", ";
                    }
                    cout << endl;
                }
            }
            break;
        case 6:
            cout << "Enter the value to Search: ";
            int searchValue;
            cin >> searchValue;
            cout << "Enter the value to insert: ";
            cin >> value;
            searchByValueUnique(head, searchValue, value);
            break;
        case 7:
            deletionAtHead(head);
            break;
        case 8:
            deletionAtTail(head);
            break;
        case 9:
            cout << "Enter the Desired Position: ";
            cin >> position;
            if (head == NULL)
            {
                cout << "There  is No Value in the Link List " << endl;
                break;
            }

            deletionAtSpecificPosition(head, position);
            cout << endl;
            display(head);
            break;
        case 10:
            cout << "Enter the Value to Delete: ";
            cin >> value;
            deletionByValueUnique(head, value);
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