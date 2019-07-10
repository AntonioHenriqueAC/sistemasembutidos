#include <stdio.h>
#include <stdlib.h>

/* 5. Crie um programa que armazene o valor 0 em todos os endereços de memória , de 0x000
até 0x3FF. */

void main()
{
    unsigned int *valor;
    valor = 0x000;
    while (valor <= 0x3FF)
    {
        *valor = 0x000;
        valor++;
    }
}