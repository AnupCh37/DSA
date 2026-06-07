#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int count = 0;
    while (n--)
    {
        int petya, vasya, tonya;
        std::cin >> petya >> vasya >> tonya;
        if (petya + vasya + tonya >= 2)
        {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}