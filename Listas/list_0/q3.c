#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa para ler um inteiro do teclado. Ele deve responder ‘sim’ se ele é um múltiplo de 3 e ‘não’
caso contrário. Pesquise o funcionamento da função SCANF.
Tome como base a seguinte estrutura de programa:

#include <stdio.h>

int main() {

return 0;
}*/

int main()
{
    int n;

    printf("informe um numero\n");
    scanf("%d", &n);

    if ((n % 3) == 0)
    {
        return printf("numero múltiplo de 3");
    }
    else
    {
        return printf("NÃO é multiplo de 3");
    }

    return 0;
}