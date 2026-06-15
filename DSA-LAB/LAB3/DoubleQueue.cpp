#include <iostream>
using namespace std;
template <typename T>

class Deque
{
private:
    int F;
    int R;
    static constexpr int N = 10;
    T DQ[N];

public:
    Deque() : F(-1), R(-1) {}
    void enqueueRear(T item)
    {
        if (R == N - 1)
        {
            cout << "Over flow " << endl;
            return;
        }
        if (F == -1)
            F = 0;
        R++;
        DQ[R] = item;
        return;
    }
    void enqeueFront(T item)
    {
        if (F == 0)
            return;

        if (F == -1)
            F = R = 0;
        else
            F--;
        DQ[F] = item;
        return;
    }
    T deqeueRear()
    {
        T item;
        if (F == -1)
            return T{};
        item = DQ[R];
        if (R == F)
            F = R = -1;
        else
            R--;
        return item;
    }
    T deqeueFront()
    {
        T item;
        if (F == -1)
            return T{};
        item = DQ[F];
        if (F == R)
            F = R = -1;
        else
            F++;
        return item;
    }
};

int main()
{
    Deque<int> dq;
    dq.enqeueFront(1);
    dq.enqeueFront(2);
    dq.deqeueFront();
    dq.enqueueRear(3);
    dq.deqeueRear();

    return 0;
}