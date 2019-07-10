#include <stdio.h>
#include <stdlib.h>

/* Você está fazendo uma leitura de um conversor analógico para digital. O conversor é de apenas 10 bits e a
arquitetura do sistema possui registradores de 8 bits. Assim, dois registradores são utilizados para o
armazenamento final da conversão, e o resultado é armazenado a direita. Como formatar o resultado em um tipo
de dado inteiro não sinalizado de 32 bits? Suponha que o valor nos registradores seja:

Registrador 1: “01000101” e Registrador 2: “10101110”. */

typedef unsigned short int uint32;

int main()
{
    uint32 tipo = 0b000000000000000000000000;
    uint32 R1 = 0b01000101;
    uint32 R2 = 0b10101110;
    uint32 result;

    tipo = R1;

    tipo = tipo << 8;
    tipo = tipo | R2;

    printf("r1: %d , r2: %d, result: %d", R1, R2, tipo);
}