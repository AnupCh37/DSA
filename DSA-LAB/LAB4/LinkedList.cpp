#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int value)
    {
        val = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
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
    }

    void insertAfterNode(int value, int key)
    {
        Node *temp = head;

        while (temp != nullptr && temp->val != key)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Node not found" << endl;
            return;
        }

        Node *newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertBeforeNode(int value, int key)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->val == key)
        {
            insertBeginning(value);
            return;
        }

        Node *prev = nullptr;
        Node *temp = head;

        while (temp != nullptr && temp->val != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Node not found" << endl;
            return;
        }

        Node *newNode = new Node(value);
        newNode->next = temp;
        prev->next = newNode;
    }

    void insertNthPosition(int n, int value)
    {
        if (n < 1)
        {
            cout << "Position out of bounds" << endl;
            return;
        }

        if (n == 1)
        {
            insertBeginning(value);
            return;
        }

        Node *temp = head;

        for (int i = 1; i < n - 1; i++)
        {
            if (temp == nullptr)
            {
                cout << "Position out of bounds" << endl;
                return;
            }
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Position out of bounds" << endl;
            return;
        }

        Node *newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
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
        delete temp;
    }

    void deleteEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;

        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAfterNode(int key)
    {
        Node *temp = head;

        while (temp != nullptr && temp->val != key)
        {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr)
        {
            cout << "Deletion not possible" << endl;
            return;
        }

        Node *del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void deleteNthPosition(int n)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (n < 1)
        {
            cout << "Position out of bounds" << endl;
            return;
        }

        if (n == 1)
        {
            deleteBeginning();
            return;
        }

        Node *temp = head;

        for (int i = 1; i < n - 1; i++)
        {
            if (temp == nullptr)
            {
                cout << "Position out of bounds" << endl;
                return;
            }
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr)
        {
            cout << "Position out of bounds" << endl;
            return;
        }

        Node *del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void display()
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);

    list.insertBeginning(5);
    list.insertAfterNode(25, 20);
    list.insertBeforeNode(15, 20);
    list.insertNthPosition(3, 12);

    list.display();

    list.deleteBeginning();
    list.deleteEnd();
    list.deleteAfterNode(20);
    list.deleteNthPosition(2);

    list.display();

    return 0;
}