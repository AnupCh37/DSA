#pragma once
#include "Stack.h"
#include <string>

class infixtopostfix
{
private:
    std::string infix;
    std::string postfix;

public:
    infixtopostfix(std::string s)
    {
        infix = s;
        postfix = "";
    }

    void convert()
    {
        Stack<char> S;

        for (size_t i = 0; i < infix.length(); i++)
        {

            if (infix[i] == '(')
            {
                S.push(infix[i]);
            }

            else if (infix[i] == ')')
            {
                while (!S.empty() && S.peek() != '(')
                {
                    postfix += S.peek();
                    S.pop();
                }
                if (!S.empty())
                    S.pop();
            }

            else if (isOperator(infix[i]))
            {

                while (!S.empty() && S.peek() != '(' && !isGreater(infix[i], S.peek()))
                {
                    postfix += S.peek();
                    S.pop();
                }
                S.push(infix[i]);
            }

            else
            {
                postfix += infix[i];
            }
        }

        while (!S.empty())
        {
            postfix += S.peek();
            S.pop();
        }
    }

    void printResult()
    {
        std::cout << "Infix:   " << infix << std::endl;
        std::cout << "Postfix: " << postfix << std::endl;
    }
    std::string returResult()
    {
        return postfix;
    }

private:
    bool isOperator(char c)
    {
        return (c == '+' || c == '-' || c == '/' || c == '*');
    }

    bool isGreater(char a, char b)
    {
        if ((a == '/' || a == '*') && (b == '-' || b == '+'))
        {
            return true;
        }
        return false;
    }
};
