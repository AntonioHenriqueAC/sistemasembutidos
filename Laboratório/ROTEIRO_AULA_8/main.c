// Aluno: Antônio Henrique Alves Cardoso
// Matrícula: 14.2.1687

// Pratica número 8


#include "project.h"
#include "stdio.h"


// start the interrupt
CY_ISR(Rotina){
    char tempo[50];
    static int segundo=0, minuto=0, hora=0;
    segundo++;
    if(segundo==60){
        minuto++;
        segundo=0;
    }if(minuto==60){
        hora++;
        minuto=0;
    }if(hora==24){
        hora=0;
    }

    sprintf(tempo,"\n\n%2d:%2d:%2d\n",hora,minuto,segundo);
    UART_1_UartPutString(tempo);
    
    Pin_1_Write(~Pin_1_Read());
    Pin_2_Write(Pin_1_Read());
    Pin_3_Write(Pin_1_Read());
    TEMPO_ClearFIFO();
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    TEMPO_Start();
    ISR_StartEx(Rotina);
    
    for(;;)
    {
    }
}

