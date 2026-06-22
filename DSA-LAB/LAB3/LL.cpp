#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void display()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = head;
    cout << "Linked List: ";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtBeginning(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;

    cout << "Node inserted at beginning." << endl;
}

void insertAtEnd(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Node inserted at end." << endl;
}

void insertAfterSpecificNode(int key, int value)
{
    Node *temp = head;

    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Specific node not found." << endl;
        return;
    }

    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted after specific node." << endl;
}

void insertBeforeSpecificNode(int key, int value)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (head->data == key)
    {
        insertAtBeginning(value);
        return;
    }

    Node *prev = head;
    Node *temp = head->next;

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Specific node not found." << endl;
        return;
    }

    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = temp;
    prev->next = newNode;

    cout << "Node inserted before specific node." << endl;
}

void insertAtNthPosition(int pos, int value)
{
    if (pos < 1)
    {
        cout << "Invalid position." << endl;
        return;
    }

    if (pos == 1)
    {
        insertAtBeginning(value);
        return;
    }

    Node *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Invalid position." << endl;
        return;
    }

    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted at position " << pos << "." << endl;
}

void deleteFromBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;

    cout << "Node deleted from beginning." << endl;
}

void deleteFromEnd()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        cout << "Node deleted from end." << endl;
        return;
    }

    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;

    cout << "Node deleted from end." << endl;
}

void deleteAfterSpecificNode(int key)
{
    Node *temp = head;

    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Specific node not found." << endl;
        return;
    }

    if (temp->next == NULL)
    {
        cout << "No node exists after the specific node." << endl;
        return;
    }

    Node *del = temp->next;
    temp->next = del->next;
    delete del;

    cout << "Node deleted after specific node." << endl;
}

void deleteFromNthPosition(int pos)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (pos < 1)
    {
        cout << "Invalid position." << endl;
        return;
    }

    if (pos == 1)
    {
        deleteFromBeginning();
        return;
    }

    Node *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        cout << "Invalid position." << endl;
        return;
    }

    Node *del = temp->next;
    temp->next = del->next;
    delete del;

    cout << "Node deleted from position " << pos << "." << endl;
}

int main()
{
    int choice, value, key, pos;

    do
    {
        cout << "\n--- Singly Linear Linked List Menu ---" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert After Specific Node" << endl;
        cout << "4. Insert Before Specific Node" << endl;
        cout << "5. Insert at Nth Position" << endl;
        cout << "6. Delete from Beginning" << endl;
        cout << "7. Delete from End" << endl;
        cout << "8. Delete After Specific Node" << endl;
        cout << "9. Delete from Nth Position" << endl;
        cout << "10. Display" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertAtEnd(value);
            break;

        case 3:
            cout << "Enter specific node value: ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> value;
            insertAfterSpecificNode(key, value);
            break;

        case 4:
            cout << "Enter specific node value: ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> value;
            insertBeforeSpecificNode(key, value);
            break;

        case 5:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> value;
            insertAtNthPosition(pos, value);
            break;

        case 6:
            deleteFromBeginning();
            break;

        case 7:
            deleteFromEnd();
            break;

        case 8:
            cout << "Enter specific node value: ";
            cin >> key;
            deleteAfterSpecificNode(key);
            break;

        case 9:
            cout << "Enter position: ";
            cin >> pos;
            deleteFromNthPosition(pos);
            break;

        case 10:
            display();
            break;

        case 0:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 0);

    return 0;
}
