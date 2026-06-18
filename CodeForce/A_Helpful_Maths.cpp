#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main()
{
    std::vector<int> v;
    std::string s;
    std::cin >> s;
    for (const auto &ch : s)
    {
        if (ch != '+')
        {
            v.push_back(ch - '0');
        }
    }
    sort(v.begin(), v.end());
    std::string a;
    for (const auto &num : v)
    {
        a = num + "+";
    }
    a.pop_back();
    std::cout << s << std::endl;
    return 0;
}