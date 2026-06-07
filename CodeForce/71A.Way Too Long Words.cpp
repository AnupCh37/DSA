// 71A Way Too long Words
#include <iostream>
#include <string>
class String
{
private:
    std::string s;

public:
    String(const std::string &w) : s(w)
    {
    }
    std::string toabbreviated()
    {

        int len = s.length();

        if (len > 10)
        {

            std::string result = " ";
            result += s[0];
            result += std::to_string(len - 2);
            result += s[len - 1];
            return result;
        }
        else
        {
            return s;
        }
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    if (std::cin >> n)
    {
        while (n--)
        {
            std::string w;
            std::cin >> w;

            String S(w);
            std::cout << S.toabbreviated() << "\n";
        }
    }
}