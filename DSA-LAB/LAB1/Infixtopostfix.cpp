#include "Infixtopostfix.h"

int main()
{
    infixtopostfix ItoP("A * (B + C) / D");
    ItoP.convert();
    ItoP.printResult();

    return 0;
}
