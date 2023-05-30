/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

void setSpeeds (int16 left ,int16 right)
{
   
if(left<0)
{
   LEFT_PWM_WriteCompare(-1*left);
    LEFT_MOTOR_DIR_Write(0);
}
else
{
    LEFT_PWM_WriteCompare(left);
    LEFT_MOTOR_DIR_Write(1);
}

if(right<0)
{
    RIGHT_PWM_WriteCompare(-1*right);
    RIGHT_MOTOR_DIR_Write(0);
}
else
{
    RIGHT_PWM_WriteCompare(right);
    RIGHT_MOTOR_DIR_Write(1);
}

}

uint32_t lastTime=0;
 uint8_t MYTime(){
        uint32_t now=CySysTickGetValue();
        if(now-lastTime>100){return 1;}
        
        return 0;}

typedef enum
{
STRAIT,
TURN_R,
TURN_L,
BACK, 
SEARCHL,
SEARCHR,
NYEKK    
} Stateses;
 int tomb[6]={1023,1023,1023,1023,1023,1023};

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    //inditas
RIGHT_PWM_Start();
LEFT_PWM_Start();
CySysTickStart();
ADC_pot_Start();
//ADC_SARANAL_Start();
//LCD_Start();
setSpeeds(0,0);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
//valtozok
uint16 pot=1023;
uint16 potvalue=0;
//int tomb[6]={1023,1023,1023,1023,1023,1023};
Stateses States=NYEKK;
int startstat=0;

    for(;;)
    {
        /* Place your application code here. */
        //nyomogomb ki/be kapcsolas
        if  (BSTOPGOMB_Read()==0){startstat=1;}//kikapcs
        if  (BSTARTGOMB_Read()==0){startstat=0;}//bekapcs
        if(startstat==0)
        {States=NYEKK;
         //digitalis vonalkovato
        if(IR_FL1_Read()==0&&IR_FR2_Read()==0){States=STRAIT;}//vonalon van mind 2 IR
        if(IR_FL1_Read()==0&&IR_FR2_Read()==1){States= TURN_L;}//vonalon van jobb IR
        if(IR_FL1_Read()==1&&IR_FR2_Read()==0){States=TURN_R;}//vonalon van bal IR
        if(IR_FL1_Read()==1&&IR_FR2_Read()==1&&States==TURN_L){States=SEARCHR;}//keres jobbra
        if(IR_FL1_Read()==1&&IR_FR2_Read()==1&&States==TURN_R){States=SEARCHL;}//keres balra
        if(IR_FL1_Read()==1&&IR_FR2_Read()==1&&States==SEARCHR){States=SEARCHR;}//keres jobbra
        if(IR_FL1_Read()==1&&IR_FR2_Read()==1&&States==SEARCHL){States=SEARCHL;}//keres balra
            
         //analog utkozes ezrekelok
       //tomb=ADC_SARANAL_RETURN_STATUS;
        
        if((tomb[0]<255||tomb[1]<255||tomb[2]<255)&&(tomb[3]<255||tomb[4]<255||tomb[5]<255)){States=NYEKK;}
        if((tomb[0]<255||tomb[1]<255||tomb[2]<255)&&(tomb[3]>255&&tomb[4]>255&&tomb[5]>255)){States=BACK;}
        if(tomb[0]<255||tomb[1]<255||tomb[2]<255){States=States;}
        
        
        
        //pometeres sebessegvaltas
            ADC_pot_StartConvert();
            pot=ADC_pot_GetResult16();//pot ertek atad valtozo
            potvalue=(pot/1023)*100;//intervallum modosito 1023->255
            if(potvalue<1){potvalue=1;}//biztositas felt
            if(potvalue>99){potvalue=100;}//biztositas felt
            
           
         //  LCD_PrintHexUint8(States);
            
            switch(States)
        { case STRAIT:setSpeeds(80*potvalue*0.011,80*potvalue*0.011);
        break;
        case  TURN_R:setSpeeds(-60*potvalue*0.011,60*potvalue*0.011);
        break;
        case  TURN_L:setSpeeds(60*potvalue*0.011,-60*potvalue*0.011);
        break;
        case  BACK:setSpeeds(-80*potvalue*0.011,-80*potvalue*0.011);
        break;
        case   SEARCHL:setSpeeds(60*potvalue*0.011,90*potvalue*0.011);
         break;
        case   SEARCHR:setSpeeds(90*potvalue*0.011,60*potvalue*0.011);
         break;
        case NYEKK:setSpeeds(0,0);
        break;
        default: setSpeeds(0,0);
        break;
        }  
        }
        if(MYTime()){;/*100 ms eltelte utan}*/}
     //   LCD_ClearDisplay; 
        BLED3_Write(startstat);
    }
}

/* [] END OF FILE */
