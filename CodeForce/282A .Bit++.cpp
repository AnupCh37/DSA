#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::string givenLanguage;
    int x = 0;
    while (n--)
    {
        std::cin >> givenLanguage;
        if (givenLanguage[1] == '+')
            x++;
        else
            x--;
    }
    std::cout << x << std::endl;
    return 0;
}