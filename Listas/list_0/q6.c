#include <stdio.h>
#include <stdlib.h>

/*Crie uma função chamada swap. Esta função deve receber dois ponteiros para inteiro como parâmetro e inverter
seus conteúdos. void swap(int *a, int *b) */

void swap(int *a, int *b)
{
    int x;
    x = *a;
    *a = *b;
    *b = x;
}

void main()
{
    int n1, n2;

    scanf("%d", &n1);
    scanf("%d", &n2);

    printf("ANTES\n NUM 1: %d \n NUM 2: %d\n\n", n1, n2);

    swap(&n1, &n2);

    printf("DEPOIS\nNUM 1: %d \nNUM 2: %d", n1, n2);
}