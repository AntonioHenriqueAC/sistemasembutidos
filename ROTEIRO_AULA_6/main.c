// Aluno: Antônio Henrique Alves Cardoso
// Matrícula: 14.2.1687

// Pratica número 6


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    ADC_Start();
    ADC_StartConvert();

    // declarando valor analógico
    int x;

    for(;;);
    {   
        // valor do canal 0
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
        
        x = (x/2) + 100;

        CyDelay(x);
    }
}