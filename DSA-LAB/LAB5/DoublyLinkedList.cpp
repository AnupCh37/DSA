#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    void insertBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;

        if (head != nullptr)
        {
            head->prev = newNode;
        }

        head = newNode;
    }

    void insertEnd(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int value)
    {
        Node *temp = head;

        while (temp != nullptr && temp->data != key)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Node not found" << endl;
            return;
        }

        Node *newNode = new Node(value);
        newNode->prev = temp;
        newNode->next = temp->next;

        if (temp->next != nullptr)
        {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    void insertBefore(int key, int value)
    {
        Node *temp = head;

        while (temp != nullptr && temp->data != key)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Node not found" << endl;
            return;
        }

        Node *newNode = new Node(value);
        newNode->next = temp;
        newNode->prev = temp->prev;

        if (temp->prev != nullptr)
        {
            temp->prev->next = newNode;
        }
        else
        {
            head = newNode;
        }

        temp->prev = newNode;
    }

    void deleteBeginning()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;

        if (head != nullptr)
        {
            head->prev = nullptr;
        }

        delete temp;
    }

    void deleteEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;

        if (head->next == nullptr)
        {
            head = nullptr;
            delete temp;
            return;
        }

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->prev->next = nullptr;
        delete temp;
    }

    void deleteAfter(int key)
    {
        Node *temp = head;

        while (temp != nullptr && temp->data != key)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Node not found" << endl;
            return;
        }

        if (temp->next == nullptr)
        {
            cout << "No node exists after the specified node" << endl;
            return;
        }

        Node *deleteNode = temp->next;
        temp->next = deleteNode->next;

        if (deleteNode->next != nullptr)
        {
            deleteNode->next->prev = temp;
        }

        delete deleteNode;
    }

    void deleteBefore(int key)
    {
        Node *temp = head;

        while (temp != nullptr && temp->data != key)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Node not found" << endl;
            return;
        }

        if (temp->prev == nullptr)
        {
            cout << "No node exists before the specified node" << endl;
            return;
        }

        Node *deleteNode = temp->prev;
        temp->prev = deleteNode->prev;

        if (deleteNode->prev != nullptr)
        {
            deleteNode->prev->next = temp;
        }
        else
        {
            head = temp;
        }

        delete deleteNode;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    ~DoublyLinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    DoublyLinkedList list;
    int choice, value, key;

    do
    {
        cout << "\n1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert after specific node" << endl;
        cout << "4. Insert before specific node" << endl;
        cout << "5. Delete from beginning" << endl;
        cout << "6. Delete from end" << endl;
        cout << "7. Delete after specific node" << endl;
        cout << "8. Delete before specific node" << endl;
        cout << "9. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertBeginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertEnd(value);
            break;

        case 3:
            cout << "Enter specific node value: ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> value;
            list.insertAfter(key, value);
            break;

        case 4:
            cout << "Enter specific node value: ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> value;
            list.insertBefore(key, value);
            break;

        case 5:
            list.deleteBeginning();
            break;

        case 6:
            list.deleteEnd();
            break;

        case 7:
            cout << "Enter specific node value: ";
            cin >> key;
            list.deleteAfter(key);
            break;

        case 8:
            cout << "Enter specific node value: ";
            cin >> key;
            list.deleteBefore(key);
            break;

        case 9:
            list.display();
            break;

        case 0:
            break;

        default:
            cout << "Invalid choice" << endl;
        }

    } while (choice != 0);

    return 0;
}