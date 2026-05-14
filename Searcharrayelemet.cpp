// Search an element in an array.
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    int arr[] = {8, 1, 3, 4, 9, 2, 5, 2, 6};
    int count = size(arr);
    int search_element;

    cout << "Enter the element to search:" << endl;
    cin >> search_element;
    bool status = false;
    for (size_t i = 0; i < count; i++)
    {
        if (search_element == arr[i])
        {
            cout << "The element is found in position " << i + 1 << endl;
            status = true;
        }
    }
    if (!status)
    {
        cout << "Element not found!" << endl;
    }
    return 0;
}
// time -O(n) space-O(1)