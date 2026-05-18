// find second largeset element
//  Delete an element from an array
#include <iostream>
#include <iterator>
using namespace std;
int main()
{
    int arr[] = {7, 1, 4, 5, 7, 5, 2, 9, 3};
    int count = size(arr);
    int largest = arr[0];
    int second_largest = arr[0];
    for (size_t i = 0; i < count; i++)
    {
        if (arr[i] > largest)
            largest = arr[i];
        else if (arr[i] > second_largest && arr[i] != largest)
            second_largest = arr[i];
    }
    cout << "The largest element  " << largest << endl;
    cout << "The second largest element is " << second_largest << endl;
    return 0;
}
// Time-O(n) space-O(1)