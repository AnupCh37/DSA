// Delete an element from an array
#include <iostream>
#include <iterator>
using namespace std;
int main()
{
    int arr[] = {8, 1, 4, 5, 7, 5, 2, 9, 3};
    int count = size(arr);
    int element, temp;
    cout << "Enter the element:" << endl;
    cin >> element;
    for (size_t i = 0; i < count; i++)
    {
        if (arr[i] == element)
        {
            for (size_t j = i; j < count; j++)
            {
                arr[j] = arr[j + 1];
            }

            count--;
            i--;
        }
    }

    cout << "The element is array is :" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
// Time-O(n^2) space-O(1)