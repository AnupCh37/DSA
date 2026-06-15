#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void printLL()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            tail = head = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop_front()
    {
        if (head == NULL)
            return;

        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    void pop_back()
    {
        if (head == NULL)
            return;
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
        delete temp;
    }
    void insert(int val, int pos)
    {
        if (pos < 0)
            return;
        else if (pos == 0)
        {
            push_front(val);
            return;
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                return;
            }
            temp = temp->next;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    int Search(int key)
    {
        Node *temp = head;
        int index = 0;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }
};
int main()
{
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(5);
    ll.pop_front();
    ll.printLL();
    ll.pop_back();
    ll.printLL();
    ll.insert(4, 1);
    ll.printLL();
    cout << ll.Search(5) << endl;
    return 0;
}
// push_front operation
// Pointer           |Before push_front (Non-empty list)  |After push_front
// newNode->next     |NULL (or uninitialized)              |Points to the old head
// head              |Pointed to the old first node        |Points to newNode
// tail              |Pointed to the last node             |Unchanged (still points to the last node)