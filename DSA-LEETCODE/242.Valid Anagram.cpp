class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int frequency[26] = {0};
        if (t.size() != s.size())
            return false;
        for (char ch : s)
        {
            frequency[ch - 'a']++;
        }
        for (char ch : t)
        {
            frequency[ch - 'a']--;
        }
        for (auto i : frequency)
        {
            if (i != 0)
                return false;
        }
        return true;
    }
};