#include <iostream>
#include <string>
#include "Stack.h"

class infixtopostfix
{
private:
    std::string infix;
    std::string postfix;

public:
    infixtopostfix(std::string s)
    {
        infix = s;
    }
    void convert()
    {
        Stack<char> S;
        int j = 0;
        for (size_t i = 0; i < infix.length(); i++)
        {
            if (infix[i] == '(')
            {
                S.push(infix[i]);
            }
            else if (infix[i] == ')')
            {
                while (!S.empty() && S.peek() != '(' && !isGreater(infix[i], S.peek()))
                {
                    postfix[j++] = S.peek();
                    S.pop();
                }

                S.pop();
            }
            else if (isOprator(infix[i]))
            {

                if (S.empty())
                {
                    S.push(infix[i]);
                }
                else if (infix[i] && (S.peek() == '(' || S.peek() == ')'))
                {
                    S.push(infix[i]);
                }
                else if (isEqual(infix[i], S.peek())) // case 2
                {
                    postfix[j++] = S.peek();
                    S.pop();
                    S.push(infix[i]);
                }
                else if (isGreater(infix[i], S.peek())) // case 1
                {
                    S.push(infix[i]);
                }
                else if (!isGreater(infix[i], S.peek()))
                {

                    while (!S.empty() && !isGreater(infix[i], S.peek()))
                    {
                        postfix[j++] = S.peek();
                        S.pop();
                    }
                    S.push(infix[i]);
                }
            }
            else
            {
                postfix[j++] = infix[i];
            }
        }
    }
    bool isOprator(char c)
    {
        if (c == '+' || c == '-' || c == '/' || c == '*')
            return true;
        else
            return false;
    }
    bool isGreater(char a, char b)
    {
        if ((a == '/' || a == '*') && (b == '-' || b == '+'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEqual(char a, char b)
    {
        if (((a == '*' || a == '/') && (b == '/' || b == '*')) || ((a == '+' || a == '-') && (b == '+' || b == '-')))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    infixtopostfix ItoP("A+B*D-(C/D)");
}