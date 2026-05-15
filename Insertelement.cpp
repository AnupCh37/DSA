// Insert a element at a given position
#include <iostream>
#include <iterator>
using namespace std;
int main()
{
    int arr[] = {3, 9, 1, 4, 7, 6, 3, 2, 8};
    int count = size(arr);
    cout << "Count:" << count << endl;
    int position, element;
    cout << "Enter the element :" << endl;
    cin >> element;
    cout << "Enter the position  :" << endl;
    cin >> position;

    for (int i = count; i >= position - 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = element;
    cout << "The element in array is :" << endl;
    count++;
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
// Time-O(n) Space-O(1)
