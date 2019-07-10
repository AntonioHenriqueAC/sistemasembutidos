/* 1. Considere que a porta D de uma determinado microcontrolador genérico está sendo
utilizada conforme a configuração da Figura 1. Considere que o sentido dos pinos da porta
tenham que ser configurados, sendo assim, para o exemplo da Figura 1, cinco deles são
pinos de saídas (pinos 0, 3, 5, 6 e 7) e três deles são pinos de entrada (pinos 1, 2 e 4).
Este microcontrolador tem registradores de oito bits. O registrador REG_PORTD_DIR é
responsável por configurar a direção dos pinos, de forma que quando um bit do registrador
está em zero, o respectivo pino é um pino de saída. Quando um bit está em 1, o respectivo
pino é entrada. O registrador REG_PORTD_DIR está mapeado no endereço 0x00ff4466
no mapa de memória do microcontrolador. O registrador REG_PORTD é o responsável
pela interface com a porta e quando um determinado bit deste registrador está em nível 1 o
respectivo pino recebe 5 Volts. Quando o pino está em lógica 0, o pino recebe 0 Volts. Este
registrador está mapeado no mapa de memória do microcontrolador com o endereço
0x00ff4567. Escreve um código para colocar todos os LEDS em nível alto quando o botão
associado ao pino 1 for pressionado. Escreva uma API (application programming interface)
para facilitar a escrita do software. A API deve ter três funções:

a. void pinMode(pin, mode); O parâmetro pin deve receber o numero referente ao
pino da porta (0 a 7). Cada bit do registrador REG_PORTD_PIN está associado a
um pino da porta. A variável mode deve receber um tipo de dado ENUM (ex. enum
mode_enum {OUTPUT=0, INPUT}; typedef enum mode_enum pin_mode;) Esta
função deve escrever no registrador REG_PORTD_DIR de forma a configurar
APENAS o pino especificado pelos parâmetros da função, sem desconfigurar os
outros pinos.

b. void digitalWrite(pin, value); O parâmetro pin deve receber o número referente ao
pino da porta (0 a 7). Cada bit do registrador REG_PORTD está associado a um
pino da porta. O estado deste bit deve determinar o nível de tensão dos pinos. Esta
função deve escrever no registrador REG_PORTD de forma a configurar APENAS
o pino especificado pelos parâmetros da função, sem desconfigurar os outros
pinos. A variável valor deve receber um tipo de dado enum. (ex.: enum
value_enum {HIGH=1, LOW}; typedef enum value_enum pin_value;)
c.

pin_value digitalRead(pin); O parâmetro pin deve receber o número referente ao
pino da porta (0 a 7). Cada bit do registrador REG_PORTD está associado a um
pino da porta. Este função deve verificar (ler) o valor do bit do registrador
associado ao parâmetro de entrada (pin) e retornar tipo de dado enum, referente
ao estado do. */

// a)

#include <stdio.h>

typedef unsigned char uchar8;
uchar8 *REG_PORTD_DIR = 0x00ff4466;
enum mode_enum
{
    OUTPUT,
    INPUT
};
typedef enum mode_enum pin_mode;

void pinMode(uchar8 pin, pin_mode mode)
{
    if (mode == INPUT)
        *REG_PORTD_DIR |= (0x01 << pin); //forçando o pino (pin) a ser 1
    else
        *REG_PORTD_DIR &= (~(0x01 << pin)); // forçando o pino (pin) a ser 0
}

// b)

typedef unsigned char uchar8;
uchar8 *REG_PORTD = 0x00ff4567;
enum value_enum
{
    HIGH,
    LOW
};
typedef enum value_enum pin_value;

void digitalWrite(uchar8 pin, pin_value value)
{
    if (value == HIGH)
        *REG_PORTD |= (0x01 << pin); //forçando o pino (pin) a ser 1 = 5v
    else
        *REG_PORTD &= (0x01 << pin); // forçando o pino (pin) a ser 0 = 0v
}

// c)

typedef unsigned char uchar8;
uchar8 *REG_PORTD = 0x00ff4567;
enum value_enum
{
    HIGH = 1,
    LOW
};
typedef enum value_enum pin_value;

pin_value digitalRead(pin)
{
    if (((*REG_PORTD &= (0x01 << pin)) >= 1))
        return 1;
    else
        return 0;
}