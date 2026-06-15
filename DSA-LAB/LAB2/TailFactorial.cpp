#include <iostream>
int tailFactorial(int n, int result)
{
    if (n == 0 || n == 1)
        return result;
    else
        return tailFactorial(n - 1, result * n);
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << tailFactorial(n, 1) << std::endl;
}