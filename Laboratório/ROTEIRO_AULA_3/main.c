// Aluno: Antônio Henrique Alves Cardoso
// Matrícula: 14.2.1687

// Pratica número 3


#include "project.h"

// setando as variaveis on, off
enum state {ON=0, OFF};   
enum state state=OFF;
    
void Ligar();
void Desligar();
    
int main(void)
{
    LED_4_Write(0);

    CyGlobalIntEnable; 

    for(;;)
    {        
        switch(state)
        {
        case OFF:
        if(Button_Read()==1)
            Ligar();
        break;

        case ON:
        if(Touch_Read()==1)
            Desligar();
        break;
        }
     }
}

void Ligar(){
     LED_4_Write(1);
     state = ON;
     }   
    
void Desligar(){
     LED_4_Write(0);
     state = OFF;
     }   
    

/* [] END OF FILE */



   
    
    

    





