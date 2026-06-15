#include <iostream>
int tailFibonnaci(int n, int a, int b)
{
    if (n == 0)
        return a;
    else if (n == 1)
        return b;
    else
        return tailFibonnaci(n - 1, b, a + b);
}
int main()
{
    int n;
    std::cin >> n;

    std::cout << tailFibonnaci(n, 0, 1) << std::endl;
    return 0;
}