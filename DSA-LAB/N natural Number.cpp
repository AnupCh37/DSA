#include <iostream>
int SumN(int n)
{
    if (n == 1)
        return 1;
    else
        return SumN(n - 1) + n;
}
int main()
{
    int n;
    std::cin >> n;
    std::cout << SumN(n) << std::endl;
    return 0;
}