/* Explique o que a seguinte macro faz:*/

#include <stdio.h>

#define BitTst(var, pos) (var & (1 << pos))

int main()
{
    int PORTA = 0b00000000;

    if (BitTst(PORTA, 2))
    {
        return printf("OLOCO");
    }
    else
        return printf("OLOKINHO MEU");
}

/* Ele testa se o 3 bit está ativo ou não*/