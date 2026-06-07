#include <iostream>
#include <string>
#include "Stack.h"

class EvaluatePostfix
{
private:
    std::string postfix;
    Stack<int> S;

    bool isOperator(char c)
    {
        return (c == '+' || c == '-' || c == '/' || c == '*');
    }

public:
    EvaluatePostfix(const std::string &s)
    {
        postfix = s;
    }

    void Evaluate()
    {

        postfix += ')';
        int i = 0;

        while (postfix[i] != ')')
        {
            if (isdigit(postfix[i]))
            {

                S.push(postfix[i] - '0');
            }
            else if (isOperator(postfix[i]))
            {

                int A = S.peek();
                S.pop();

                int B = S.peek();
                S.pop();

                int C = 0;
                switch (postfix[i])
                {
                case '+':
                    C = B + A;
                    break;
                case '-':
                    C = B - A;
                    break;
                case '*':
                    C = B * A;
                    break;
                case '/':
                    C = B / A;
                    break;
                }
                S.push(C);
            }
            i++;
        }
    }

    void Result()
    {
        if (!S.empty())
        {
            std::cout << "The Result is : " << S.peek() << std::endl;
        }
        else
        {
            std::cout << "Stack is empty. Evaluation failed." << std::endl;
        }
    }
};

int main()
{
    std::string postfix = "623*+4-";
    EvaluatePostfix E(postfix);
    E.Evaluate();
    E.Result();
    return 0;
}