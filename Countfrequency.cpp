//Count frequency of element
#include <iostream>
#include <iterator>
using namespace std;
int main()
{
    int arr[] = {3, 2, 7, 4, 1, 5, 2, 5, 2};
    int count = size(arr), search_element;
    int search_count = 0;
    cout << "Enter the element you want to search " << endl;
    cin >> search_element;
    for (size_t i = 0; i < count; i++)
    {
        if (search_element == arr[i])
        {
            search_count++;
        }
    }
    if (search_count == 0)
    {
        cout << "Element not found!" << endl;
    }
    else
    {
        cout << "The count of " << search_element << " is: " << search_count << endl;
    }

    return 0;
}
// Time-O(n) Space-(1)