// Insert a element at a given position
#include <iostream>
#include <iterator>
using namespace std;
int main()
{
    int arr[] = {3, 9, 1, 4, 7, 6, 3, 2, 8};
    int count = size(arr);
    int position, element;
    cout << "Enter the element :" << endl;
    cin >> element;
    cout << "Enter the position  :" << endl;
    cin >> position;
    int temp = arr[position];
    arr[position] = element;
    for (size_t i = position + 1; i < count + 1; i++)
    {
        temp = arr[]
    }

    return 0;
}
