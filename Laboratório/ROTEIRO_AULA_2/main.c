// Aluno: Antônio Henrique Alves Cardoso
// Matrícula: 14.2.1687

// Pratica número 2


#include "project.h"


 
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

   int i = 0;

    // setando cada cor de led
   LedR_Write(1);
   LedB_Write(1);
   LedG_Write(1);
    
    for(;;){

    if (IN_Read()==0){
    CyDelay(500);
        i++;
    }
        
    if (i==1){
    LedR_Write(0);
    LedG_Write(1);
    LedB_Write(1);
    CyDelay(100);} 
        else if(i==2){
            LedR_Write(1);
            LedG_Write(0);
            LedB_Write(1);
            CyDelay(100);
        } else if(i==3){
                LedR_Write(1);
                LedG_Write(1);
                LedB_Write(0);
                CyDelay(100);
                }
        
    if(i==4) {i=1;}
    
    }
}

/* [] END OF FILE */
