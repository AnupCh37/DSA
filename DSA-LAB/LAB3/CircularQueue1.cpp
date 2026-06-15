#include <iostream>
#define MAX 100
using namespace std;
struct circ_que
{
    int queue[MAX];
    int front;
    int rear;

    circ_que()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int val)
    {
        if ((rear + 1) % MAX == front)
        {
            cout << "Queue Overflow";
            return;
        }
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
            queue[rear] = val;
        }
    }
    void dequeue()
    {
        if (front == -1)
        {
            cout << "Underflow";
            return;
        }

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << "\n";
        }
        cout << "\n";
    }
};
int main()
{
    circ_que circ;
    circ.enqueue(25);
    circ.enqueue(30);
    circ.enqueue(20);
    circ.display();
    circ.dequeue();
    circ.display();
    circ.enqueue(35);
    circ.display();
    circ.dequeue();
    circ.display();
}