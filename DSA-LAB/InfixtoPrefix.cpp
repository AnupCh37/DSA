#include <iostream>
#include <string>
#include <algorithm>
#include "Infixtopostfix.h"

int main()
{
    std::string infix = "(A+B)*(C-D)";
    std::reverse(infix.begin(), infix.end());
    std::cout << infix << std::endl;
    int i = 0;
    while (infix[i] != '\0')
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
        i++;
    }
    std::cout << infix << std::endl;
    infixtopostfix ItoP(infix);
    ItoP.convert();
    std::string InterPost = ItoP.returResult();
    std::cout << " Intermediate Postfix : " << InterPost << std::endl;

    std::reverse(InterPost.begin(), InterPost.end());
    std::cout << "Prefix Result : " << InterPost << std::endl;
    return 0;
}