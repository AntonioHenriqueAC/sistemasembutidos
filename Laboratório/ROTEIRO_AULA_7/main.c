// Aluno: Antônio Henrique Alves Cardoso
// Matrícula: 14.2.1687

// Pratica número 7

#include <project.h>
#include <stdio.h>
#include <ADC.h>
#include <UART.h>

// --------------------------------- PARTE 3.1 ---------------------------------------

void UART_UartPutString();

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    ADC_Start();
    ADC_StartConvert();
    int x;
    
    UART_Start();
    UART_UartPutString("Starting readings..");

    for(;;)
    {
        x = ADC_GetResult16(0);
        LED_Write(!LED_Read());

        if (x>4095)
        {
            x=4095;
        }
        if (x<1)
        {
            x=1;
        }
        
        CyDelay (x);
        ADC_IsEndConversion(x);
        x=ADC_WAIT_FOR_RESULT;
        
    }
}



// --------------------------------- PARTE 3.2 --------------------------------------- 


int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    uint32 ch();
    uint16 x;

    /* Start SCB (UART mode) operation */
    UART_Start();
    UART_UartPutString("...";)
    ADC_StartConvert();
    
    for (;;)
    {
        
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        x = ADC_GetResult16;
        uint16 y = ADC_CountsTo_mVolts(0,x);
        
        int an_read;
        int VREFplus = 4095;

        uint16 temperature;
        an_read = x;
        uint16 B=3975;

        //get the resistance of the sensor
        uint16 resistance=(float)(VREFplus-an_read)*10000/an_read;          
        char str[40];
        sprintf(str,"Valor:%d", x);
        UART_UartPutString(str);
        
        // conveert to temperature via datasheet
        uint16 temperature=1/(log(resistance/10000)/B+1/298.15)-273.15;
 
    }
}

