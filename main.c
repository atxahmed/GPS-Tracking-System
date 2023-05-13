

/**
 * main.c
 */
#include "C:\Users\ahmed\workspace_v12\Final delivery\FUnctions.h"
int main(){
UART5_Init();
PortF_init();
SysTick_Init();
PortB_init();
while(1){
    char flag;
    char logname[] = "$GPRMC";
    char b;
    char nema[80]={0};
    char i=0;
    char n=0,m=0;
    char flag1=0;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    do{
        flag = 1;
        for(i=0;i<6;i++){
              while ((UART5_FR_R&0x10)!=0); //RXFE
              b = (char)(UART5_DR_R&0xff);
              if(b!=logname[i]){
                flag=0;
                break;}
        }
    }while(flag==0);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    i=0;
    char c=0;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    do{

         while ((UART5_FR_R&0x10)!=0); //RXFE
         nema[i] = (char)(UART5_DR_R&0xff);
         i++;

    }while(nema[i]!='*');

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    for (i=0 ; i<80 ; i++)
                   {
                       if(nema[i]==',')
                       {
                           c++;
                       }

                       if (c==2)
                       {i++;
                           if (nema[i] == 'A'){
                           continue;}

                           else
                               break ;

                       }

                       if ((c==3))
                       {i+=1;
                           for (;nema[i]!=',';i++)
                           {
                               lat[n]=nema[i];
                               n+=1;
                           }
                           i-=1;
                       }

                       if ((c==5))
                       {i+=1;
                           for (;nema[i]!=',';i++)
                           {
                               lon[m]=nema[i];
                               m+=1;
                           }
                           break;

                       }

                   }




double latitude  = Degconv(atof(lat));
double longitude = Degconv(atof(lon));
double y = CalcDist(destLat,destLon,latitude,longitude);
led_output(y);
if (y>4 && y<=8){
    GPIO_PORTB_DATA_R ^=0x01;
    delay(1);
    GPIO_PORTB_DATA_R ^=0x01;
}
if (y<4 && flag1==0){
    GPIO_PORTB_DATA_R ^=0x01;
    delay(3);
    GPIO_PORTB_DATA_R ^=0x01;
    flag1=1;
}




    }
}
