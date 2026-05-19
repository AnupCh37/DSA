// Check if the array is sorted or not
#include <iostream>
#include <iterator>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int count = size(arr);
    bool ascending = true;
    bool descending = true;
    for (size_t i = 1; i < count - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            ascending = false;
        }

        // arr[i]<first_element
        if (arr[i] < arr[i + 1])
        {
            descending = false;
        }
    }
    if (ascending)
    {
        cout << "Array is sorted in Ascending Order" << endl;
    }
    else if (descending)
    {
        cout << "Array is sorted in Descending Order" << endl;
    }
    else
    {
        cout << "Array is Not Sorted" << endl;.
    }

    return 0;
}
// Time-O(n) Space-O(1)