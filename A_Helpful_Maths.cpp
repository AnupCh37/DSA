#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    string str, result;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '+')
            v.push_back(str[i]);
    }
    for (auto &x : v)
    {
        cout << x << endl;
    }
    sort(v.begin(), v.end());
    for (size_t i = 0; i < v.size(); i++)
    {
        result + = v.pop_back();
    }
    cout << result;
}