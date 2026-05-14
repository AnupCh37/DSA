// Reverse an array
#include <iostream>
#include <iterator>
using namespace std;
int main()
{
    int arr[] = {3, 9, 2, 3, 4, 8, 1, 7, 11};
    int arr_length = size(arr);
    int temp;
    for (size_t i = 0; i < arr_length / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[arr_length - i - 1];
        arr[arr_length - i - 1] = temp;
    }
    for (size_t i = 0; i < arr_length; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
// Time -O(n) Space-O(1)