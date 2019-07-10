// Aluno: Antônio Henrique Alves Cardoso
// Matrícula: 14.2.1687

// Pratica número 1 

#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    uint8 x;
   
      
    for(;;)
    { 
        x = Pin_IN_Read();
   
        if (x==1){
            Pin_OUT_Write(x);
            CyDelay(500);
            Pin_OUT_Write(0);
        }
    }
}

/* [] END OF FILE */
