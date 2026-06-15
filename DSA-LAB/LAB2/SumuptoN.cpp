#include <iostream>

int SumN(int n)
{
    if (n == 1)
        return 1;
    else
        return SumN(n - 1) + n;
}
int SumTail(int n, int a = 1)
{
    if (n == 1)
        return a;
    else
        return SumTail(n - 1, n + 1);
}
 
int main()
{
    int n;
    std::cin >> n;
    std::cout << SumN(n);
    std::cout << SumTail(n);
}