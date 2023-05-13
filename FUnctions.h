/*
 * FUnctions.h
 *
 *  Created on: May 13, 2023
 *      Author: ahmed
 */

#include "C:\Users\ahmed\Desktop\ASU ECE\EMBEDDED\ex labs\SH8AAL\tm4c123gh6pm.h"
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "C:\ti\TivaWare_C_Series-2.2.0.295\driverlib\sysctl.h"
#include "C:\ti\TivaWare_C_Series-2.2.0.295\driverlib\gpio.h"
#include "C:\ti\TivaWare_C_Series-2.2.0.295\driverlib\uart.h"
#define PI 3.14159265359
char lon [20]={0};
char lat [20]={0};
double destLat   = 29.9786380 ;
double destLon   = 31.4759907 ;
double y=0;
void PortB_init(void);
void SysTick_Init(void);
void SysTick_Wait1s(void);
void delay(unsigned long n);
double Degconv (double val);
double deg2rad(float deg);
double CalcDist(double lat1,double lon1,double lat2,double lon2);
void led_output(double x);
void PortF_init(void);
void UART5_Init(void) ;



