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

    int dequeue()
    {
        if (Front == nullptr)
        {
            std::cout << "Queue Underflow" << std::endl;
            return -1;
        }
        Node *temp = Front;
        int DequeuedValue = Front->val;
        Front = Front->next;
        if (Front == nullptr)
        {
            Rear = nullptr;
        }
        delete temp;
        return DequeuedValue;
    }

    int peek()
    {
        if (Front == NULL)
        {
            std::cout << "Queue is Empty" << std::endl;
            return -1;
        }
        return Front->val;
    }
    bool isEmpty()
    {
        return Front == nullptr;
    }
    void display()
    {
        if (Front == nullptr)
        {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        Node *temp = Front;
        while (temp != NULL)
        {
            std::cout << temp->val << " ->" << " ";
            temp = temp->next;
        }
        std::cout << " NULL" << std::endl;
        return;
    }
};

int main()
{
    QueueLL q;
    q.Enqueue(10);
    q.Enqueue(5);
    q.Enqueue(15);
    q.Enqueue(12);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    std::cout << q.peek() << std::endl;
    q.dequeue();
    std::cout << q.peek() << std::endl;
    return 0;
}