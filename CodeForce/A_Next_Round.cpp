#include <iostream>

int main()
{
    int n, k;
    int arr[50];
    int count = 0;
    std::cin >> n >> k;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    int min_score = arr[k - 1];
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] >= min_score && arr[i] > 0)
            count++;
    }

    std::cout
        << count << std::endl;
}