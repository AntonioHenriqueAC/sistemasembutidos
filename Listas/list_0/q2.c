#include <stdio.h>
#include <stdlib.h>

/*Construa uma máscara para extrair o resultado formado pelos bits 2, 3, 4 e 5 do registrador de 8 bits.Considere
por exemplo, que o registrador neste momento tenha valor: “01110101”.*/

int main()
{

    int mask = 0b0011110;

    int regist = 0b01110101;

    int result;

    result = mask & regist;

    printf("%d = %d & %d", result, mask, regist);
    printf("\n");

    return 0;
}