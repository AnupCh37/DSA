// Find the average of the array
#include <iostream>
#include <iterator>
int main()
{
    int arr[] = {3, 4, 9, 1, 4, 8, 3, 7, 2};
    int sumarr = 0;
    int lengtharr = std::size(arr);
    for (size_t i = 0; i < lengtharr; i++)
    {
        sumarr += arr[i];
    }
    std::cout << "The average of the array is :" << static_cast<float>(sumarr) / lengtharr << std::endl;
    return 0;
}
// Time -O(n)
// Space -O(1)