#include <iostream>
#include <unordered_map>
int main()
{
    std::string s;
    std::cin >> s;
    std::unordered_map<char, int> freqeuncyMap;
    for (char c : s)
    {
        freqeuncyMap[c]++;
    }
    s = (freqeuncyMap.size() % 2) ? "IGNORE HIM!" : "CHAT WITH HER!";
    std::cout << s << std::endl;
    return 0;
}