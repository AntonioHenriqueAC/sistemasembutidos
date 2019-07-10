/* 2. Num dado sistema, a posição de memória de valor 0xF34 mapeia um módulo interno do
microcontrolador dedicado a medir corrente (registrador para um sensor de corrente). O
registrador associado ao módulo tem 8 bits.
Sabendo-se que a tensão do sistema é sempre constante em 10 volts, crie uma
função que retorne o valor da resistência. Cuidado com o valor de corrente, pois pode assu
mir o valor zero ou negativo, Tome as devidas precauções para evitar
erros de cálculo. A resistência é sempre positiva. Equação para resistência: R = V ÷ I .

#define VAR (*(unsigned char*)0x00F) //exemplo de variável de 8 bits para acesso ao
endereço 0x00F

#define PORTA (*(unsigned char*)0xF80); */

#include <stdio.h>

#define corrente (*(unsigned char *)0xF34) //exemplo de variável de 8 bits para acesso ao endereço 0xF34;

unsigned int readOHM()
{

    if (corrente > 0)
    {
        return (10 / (corrente));
    }
    else
    {
        return 0;
    }
}
