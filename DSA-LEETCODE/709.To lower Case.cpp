class Solution
{
public:
    string toLowerCase(string s)
    {

        for (auto &ch : s)
        {
            int c = ch;
            if (c >= 65 && c <= 90)
                c += 32;
            ch = (char)c;
        }

        return s;
    }
};