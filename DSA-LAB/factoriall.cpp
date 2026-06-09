#include <iostream>

int factorail(int n, int a)
{
    if (n == 0 || n == 1)
        return a;
    else
        return factorail(n - 1, a * n);
}
int factorailTail(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorailTail(n - 1);
}
int main()
{
    int n;
    std::cin >> n;
    std::cout << factorail(n, 1);
}