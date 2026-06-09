#include <iostream>
int Fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int FibonacciTail(int n, int a = 0, int b = 1)
{
    if (n == 0)
        return a;
    else if (n == 1)
        return b;
    else
        return FibonacciTail(n - 1, b, a + b);
}
int main()
{
    int n;
    std::cin >> n;
    std::cout << Fibonacci(n) << std::endl;
    std::cout << FibonacciTail(n) << std::endl;
    return 0;
}