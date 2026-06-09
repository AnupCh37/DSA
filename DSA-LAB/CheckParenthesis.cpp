#include <iostream>
#include <string>
#include "Stack.h"

class CheckParenthesis
{
private:
    std::string exp;
    Stack<char> S;

public:
    CheckParenthesis(const std::string &s) : exp(s)
    {
    }

    void check()
    {

        for (size_t i = 0; i < exp.length(); i++)
        {
            if (exp[i] == '(')
            {
                S.push(exp[i]);
            }
            else if (exp[i] == ')')
            {
                if (S.empty())
                {
                    std::cout << "The expression is Invalid" << std::endl;
                    return;
                }
                else
                {
                    S.pop();
                }
            }
        }

        if (S.empty())
        {
            std::cout << "The expression is Valid" << std::endl;
        }
        else
        {
            std::cout << "The expression is Invalid" << std::endl;
        }
    }
};

int main()
{
    std::string exp;
    std::cout<<"Enter the give expression"<<std::endl;
    std::cin>>exp;

    CheckParenthesis CP(exp);
    CP.check();

    return 0;
}
