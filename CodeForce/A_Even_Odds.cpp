#include <iostream>
#include <vector>
int main()
{
    int total, index;
    std::vector<int> v;
    std::cin >> total >> index;
    int odd, even;
    even = total / 2;
    odd = total - even;
    int j = 1;
    for (int i = 0; i < odd; i++)
    {

        v.push_back(j);
        j = j + 2;
    }
    j = 2;
    for (int i = 0; i < even; i++)
    {
        v.push_back(j);
        j = j + 2;
    }
    std::cout << v[index - 1] << std::endl;

    return 0;
}