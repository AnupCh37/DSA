class Solution
{
public:
    string smallestPalindrome(string s)
    {
        int len = s.size();
        int half = len / 2;
        char extrachar;
        if (len % 2 != 0)
            extrachar = s[half];
        vector<char> result;
        for (int i = 0; i < half; i++)
        {
            result.push_back(s[i]);
        }
        sort(result.begin(), result.end());
        string resultant, reverseResultant;
        for (auto ch : result)
        {
            resultant += ch;
        }
        reverseResultant = resultant;
        reverse(reverseResultant.begin(), reverseResultant.end());
        if (len % 2 != 0)
        {
            return resultant + extrachar + reverseResultant;
        }
        return resultant + reverseResultant;
    }
};
// 27 % && 5.50%
// some o the worst solution