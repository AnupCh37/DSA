#include <iostream>
using namespace std;

const int MAX = 10;

struct Node
{
    int data;
    int next;
};

Node node[MAX];
int head = -1;
int avail = 0;

void initialize()
{
    for (int i = 0; i < MAX - 1; i++)
        node[i].next = i + 1;

    node[MAX - 1].next = -1;
}

int getNode()
{
    if (avail == -1)
        return -1;

    int p = avail;
    avail = node[avail].next;
    return p;
}

void freeNode(int p)
{
    node[p].next = avail;
    avail = p;
}

void insertEnd(int value)
{
    int p = getNode();

    node[p].data = value;
    node[p].next = -1;

    if (head == -1)
    {
        head = p;
        return;
    }

    int temp = head;

    while (node[temp].next != -1)
        temp = node[temp].next;

    node[temp].next = p;
}

void deleteEnd()
{
    if (head == -1)
        return;

    if (node[head].next == -1)
    {
        freeNode(head);
        head = -1;
        return;
    }

    int temp = head;

    while (node[node[temp].next].next != -1)
        temp = node[temp].next;

    int last = node[temp].next;
    node[temp].next = -1;
    freeNode(last);
}

void display()
{
    int temp = head;

    while (temp != -1)
    {
        cout << node[temp].data << " ";
        temp = node[temp].next;
    }
    cout << endl;
}

int main()
{
    initialize();

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    cout << "List after insertion: ";
    display();

    deleteEnd();

    cout << "List after deleting last node: ";
    display();

    return 0;
}