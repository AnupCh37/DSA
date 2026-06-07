#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, min;
    std::cin >>
        n >> min;
    int count = 0, x;
    while (n--)
    {
        std::cin >> x;
        if (x > min)
        {
            count++;
        }
    }
    std::cout << n << std::endl;
}