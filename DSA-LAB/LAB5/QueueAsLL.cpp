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

class QueueLL
{
private:
    Node *Front;
    Node *Rear;

public:
    QueueLL() : Front(nullptr), Rear(nullptr) {}

    void Enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (Front == nullptr)
        {
            Front = newNode;
            Rear = newNode;
            return;
        }
        Rear->next = newNode;
        Rear = newNode;
    }

    int pop()
    {
        if (top == nullptr)
        {
            cout << "Stack Underflow! Stack is empty." << endl;
            return -1;
        }

        Node *temp = top;
        int poppedValue = top->val;
        top = top->next;
        delete temp;

        return poppedValue;
    }

    int peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty." << endl;
            return -1;
        }

        return top->val;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void display()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty." << endl;
            return;
        }

        Node *temp = top;

        cout << "Stack elements: ";
        while (temp != nullptr)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    stackLL s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Top element: " << s.peek() << endl;

    cout << "Popped element: " << s.pop() << endl;

    s.display();

    return 0;
}