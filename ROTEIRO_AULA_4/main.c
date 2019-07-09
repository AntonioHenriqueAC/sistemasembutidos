// Aluno: Antônio Henrique Alves Cardoso
// Matrícula: 14.2.1687

// Pratica número 4


#include "project.h"

 
// ----------------------------------- MOTOR CC --------------------------------------------------------

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

uint8   Buttom_H_Read(void);
uint8   Buttom_CC_Read(void);
void    OUT_CC_Write(uint8 value);

void    OUT_H_Write(uint8 value);

    for(;;);
    {
        if (Buttom_H_Read() == 0 && Buttom_CC_Read()==1){
             OUT_CC_Write(1);
             OUT_H_Write(0);
            CyDelay(500);
            OUT_CC_Write(0);     
             }
        
          if (Buttom_CC_Read() == 1 && Buttom_CC_Read()==0){
             OUT_CC_Write(0);
             OUT_H_Write(1);
             CyDelay(500);
             OUT_H_Write(0);
             }

    }
}

// ----------------------------------- SERVO MOTOR --------------------------------------------------------

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */


    int x=0;
    
    for(;;)
    {
        if (ButtomDD_Read()==1) {
            x=x+50;
        }
        if (ButtomLESS_Read()==1) {
            x=x-50;
        }
    Pin_OUT_Write(1);
    CyDelayUs(1500+x);
    Pin_OUT_Write(0);
    CyDelayUs(18500-x);

    // CyDelay(X) is for Xms, X is unsigned long
    // CyDelayUs(X) is for Xus, X is unsigned int
   
    }
}





