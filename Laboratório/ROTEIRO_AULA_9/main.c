// Aluno: Antônio Henrique Alves Cardoso
// Matrícula: 14.2.1687

// Pratica número 9

#include "project.h"
#include "stdio.h"
#include "ADC.h"
#include "UART.h"

char read[50];

int ch1=0;
int ch2=0;

// Starting interrupt
CY_ISR(Rotina){

   ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
   ch1 = ADC_GetResult16(0); 
   ch2 = ADC_GetResult16(1); 

   sprintf(read,"%d %d\n\r", ch1,ch2);

   UART_UartPutString(read);
   Timer_ReadStatusRegister();
   
}
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    Timer_Start();
    ISR_StartEx(Rotina);
    ADC_Start();
    ADC_StartConvert();
    UART_Start();
    for(;;)
    {
    }
}

