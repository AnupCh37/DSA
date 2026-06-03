#include <iostream>
#include "Stack.h"

int main()
{
    Stack<char> S;

    S.push('H');
    S.push('A');
    S.push('R');
    S.push('I');
    S.view();

    S.pop();
    S.pop();
    S.view();

    S.peek();

    return 0;
}
