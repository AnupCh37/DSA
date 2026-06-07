#include <iostream>
using namespace std;

void TowerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        cout << "Move disc 1 from " << source << " to " << destination << endl;
        return;
    }

    TowerOfHanoi(n - 1, source, destination, auxiliary);

    cout << "Move disc " << n << " from " << source << " to " << destination << endl;

    TowerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int N;
    cout << "Enter the number of discs: ";
    cin >> N;

    cout << "The sequence of moves are:\n";
    TowerOfHanoi(N, 'A', 'B', 'C');
    return 0;
}