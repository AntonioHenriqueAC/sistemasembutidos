// Aluno: Antônio Henrique Alves Cardoso
// Matrícula: 14.2.1687

// Pratica número 10

#include <stdio.h>
#include "I2C.h"
#include "project.h"


#define REG_RED         0x04     
#define REG_GREEN       0x03      
#define REG_BLUE        0x02        


void setReg(unsigned char addr, unsigned char dta)
{
     //catch
    if (I2C_I2C_MSTR_NO_ERROR == status){       
        status = I2C_I2CMasterWriteByte(addr, timeout);     
        status = I2C_I2CMasterWriteByte(dta, timeout); 
 }
  
// control
void setRGB(unsigned char r, unsigned char g, unsigned char b);
void setColor(unsigned char color);

void setRGB(unsigned char r, unsigned char g, unsigned char b)
{
    setReg(REG_RED, r);
    setReg(REG_GREEN, g);
    setReg(REG_BLUE, b);
}

//branco, vermelho, verde e azul respectivamente
const unsigned char color_define[4][3] = 
{
    {255, 255, 255},          
    {255, 0, 0},              
    {0, 255, 0},               
    {0, 0, 255},             
};

void setColor(unsigned char color)
{
    if(color > 3)return ;
    setRGB(color_define[color][0], color_define[color][1], color_define[color][2]);
}

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
