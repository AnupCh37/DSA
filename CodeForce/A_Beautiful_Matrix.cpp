#include <iostream>

int main()
{
    int arr[5][5];
    int posR, posC;
    for (size_t i = 0; i < 5; i++)
    {

        for (size_t j = 0; j < 5; j++)
        {
            std::cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                posR = i + 1;
                posC = j + 1;
            }
        }
    }
    std::cout << abs(posR - 3) + abs(posC - 3) << std::endl;
}
