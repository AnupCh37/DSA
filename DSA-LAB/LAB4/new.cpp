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
    list.insertEnd(40);
    list.insertEnd(50);

    cout << "Original Linked List:" << endl;
    list.display();

    list.deleteBeginning();
    cout << "After deleting from beginning:" << endl;
    list.display();

    list.deleteEnd();
    cout << "After deleting from end:" << endl;
    list.display();

    list.deleteAfterNode(20);
    cout << "After deleting node after 20:" << endl;
    list.display();

    list.deleteNthPosition(2);
    cout << "After deleting 2nd position:" << endl;
    list.display();

    return 0;
}