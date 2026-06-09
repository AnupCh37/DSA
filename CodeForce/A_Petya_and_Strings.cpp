#include <iostream>
#include <string>
#include <cctype>
int main()
{
    std::string s1;
    std::string s2;
    std::cin >> s1;
    std::cin >> s2;
    for (char &c1 : s1)
    {
        c1 = std::tolower(static_cast<unsigned char>(c1));
    }
    for (char &c2 : s2)
    {
        c2 = std::tolower(static_cast<unsigned char>(c2));
    }
    if (s1 < s2)
    {
        std::cout << -1 << std::endl;
    }
    else if (s1 > s2)
    {
        std::cout << 1 << std::endl;
    }
    else
    {
        std::cout << 0 << std::endl;
    }
}