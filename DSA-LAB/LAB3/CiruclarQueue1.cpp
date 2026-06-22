#include <iostream>

template <typename T, int cap>
class CircularQueue
{
private:
    int rear;
    int front;
    T arr[cap];
    int currSize = 0;

public:
    CircularQueue() : front(-1), rear(-1) {}

    void Enqueue(T item)
    {
        if ((rear + 1) % cap == front)
        {
            std::cout << "Circular Queue Overflow" << std::endl;
            return;
        }
        else if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % cap;
        currSize++;
        arr[rear] = item;
    }

    void dequeue()
    {
        if (front == -1)
        {
            std::cout << "Underflow" << std::endl;
            return;
        }

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % cap;
        }
        currSize--;
    }

    void printQueue()
    {
        if (front == -1)
        {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        int i = front;
        while (true)
        {
            std::cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % cap;
        }
        std::cout << std::endl;
    }
};

int main()
{

    CircularQueue<int, 10> cq;
    cq.Enqueue(1);
    cq.Enqueue(2);
    cq.Enqueue(3);
    cq.Enqueue(4);

    cq.dequeue();
    cq.dequeue();

    cq.printQueue();
    return 0;
}