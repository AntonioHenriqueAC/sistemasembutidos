// Aluno: Antônio Henrique Alves Cardoso
// Matrícula: 14.2.1687

// Pratica número 5

#include "project.h"

static int count = 1;

switch (count)
{
case 1:
   LED_RED_Write(0);
   LED_GREEN_Write(1);
   LED_BLUE_Write(1);
   count++;
   break;
case 2:
   LED_RED_Write(1);
   LED_GREEN_Write(0);
   LED_BLUE_Write(1);
   count++;
   break;
case 3:
   LED_RED_Write(1);
   LED_GREEN_Write(1);
   LED_BLUE_Write(0);
   count++;
   break;
case 4:
   LED_RED_Write(1);
   LED_GREEN_Write(1);
   LED_BLUE_Write(1);
   count = 1;
   break;
}
Button_ClearInterrupt();


int main(void)
{
   CyGlobalIntEnable; /* Enable global interrupts. */

   for (;;)
   {
   }
}
