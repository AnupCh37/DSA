#include <iostream>
using namespace std;
class Queue
{
private:
    int rear;
    int front;
    int MAX = 100;
    int *arr = new int;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    void enqueue(int val)
    {
        if (rear == MAX - 1)
        {
            cout << "Queue Overflow";
            return;
        }
        else if (front == -1)
        {
            front = 0;
        }
        rear++;
        arr[rear] = val;
    }
    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        int val = arr[front];
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
        cout << "The deqeue element is " << val << endl;
    }
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty " << endl;
            return;
        }
        int i = front;
        while (i <= rear)
        {
            cout << arr[i] << " ";
            i++;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.display();
    return 0;
}