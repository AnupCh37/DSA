#include <iostream>
#include "Stack.h"

int main()
{
    Stack<char> S;

    S.push('D');
    S.push('S');
    S.push('A');
    S.push('I');
    S.push('S');
    S.push('G');
    S.push('O');
    S.push('O');
    S.push('D');
    S.view();

    S.pop();
    S.pop();
     S.pop();
    S.view();

    S.peek();

    return 0;
}
