#include <iostream>
int main()
{
    std::string s;
    std::cin >> s;
    int countZero = 0, countOne = 0;
    int heightestCount = 0;
    for (const auto &ch : s)
    {
        if (ch == '0')
        {
            countZero++;
            countOne = 0;
            if (countZero > heightestCount)
            {
                heightestCount = countZero;
            }
        }
        else
        {
            countOne++;
            countZero = 0;
            if (countOne > heightestCount)
            {
                heightestCount = countOne;
            }
        }
    }
    if (heightestCount >= 7)
    {
        std::cout << "YES" << std::endl;
        return 0;
    }

    std::cout << "NO" << std::endl;
    return 0;
}
