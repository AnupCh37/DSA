#include <iostream>
using namespace std;
class CircularQueue
{
private:
    int *arr;
    int currSize, cap;
    int f, r;

public:
    CircularQueue(int size)
    {
        cap = size;
        arr = new int[cap];
        currSize = 0;
        f = 0;
        r = -1;
    }
    void push(int data)
    {
        if (currSize == cap)
        {
            return;
        }
        r = (r + 1) % cap;
        arr[r] = data;
        currSize++;
    }
    void pop()
    {
        if (empty())
        {
            return;
        }
        f = (f + 1) % cap;
        currSize--;
    }
    int front()
    {

        if (empty())
        {
            return -1;
        }
        return arr[f];
    }
    bool empty()
    {
        return currSize == 0;
    }
    void printArr()
    {
        if (empty())
            return;
        else
        {
            for (int i = 0; i < currSize; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    CircularQueue cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    // cq.printArr();
    cq.pop();
    cq.push(4);
    // cq.printArr();
    while (!cq.empty())
    {
        cout << cq.front() << " ";
        cq.pop();
    }
    cout << endl;

    return 0;
}