#include <iostream>
#define MAX 100

template <typename T>
class Queue
{
private:
    int rear;
    int front;
    T arr[MAX];

public:
    Queue() : front(-1), rear(-1) {}

    void Enqueue(T item)
    {
        if (rear == MAX - 1)
        {
            std::cout << "Overflow" << std::endl;
            return;
        }
        else if (front == -1)
        {
            front = 0;
        }
        rear++;
        arr[rear] = item;
    }

    void dequeue()
    {
        if (front == -1)
        {
            std::cout << "Underflow" << std::endl;
            return;
        }

        T item = arr[front];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }

    void printQueue()
    {
        if (front == -1)
        {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        for (int i = front; i <= rear; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    Queue<int> q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);

    q.dequeue();
    q.dequeue();

    q.printQueue();
    return 0;
}