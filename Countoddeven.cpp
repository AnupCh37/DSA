#include <iostream>
#include <iterator>
using namespace std;
int main()
{
    int arr[] = {9, 7, 11, 2, 3, 5, 4, 1, 3, 8, 6, 18};
    int count_odd = 0, count_even = 0;
    int arr_length = size(arr);
    for (size_t i = 0; i < arr_length; i++)
    {
        if (arr[i] % 2 == 0)
            count_even++;
        else
            count_odd++;
    }
    cout << "The count of even number and odd number is " << count_even << " &  " << count_odd << endl;

    return 0;
}
// Time - O(n)
// Space -O(1)