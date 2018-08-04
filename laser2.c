#include <reg51.h>

void lasercount();
void reset();

sbit laser=P0^0;
sbit laser1=P0^1;
sbit ir=P0^5;

sbit led1=P3^2;
sbit led2=P3^3;
sbit led3=P3^4;
sbit relay=P0^7;

void delay(unsigned int itime);	
unsigned char count=0; 


void main(void)
  {
     
laser=1;
laser1=1;
ir=1;

led1=0;
led2=0;
led3=0;
relay=0;

    while(1)
      {
         if(ir==1)
      {
	   	
       while(ir==1);
       reset();
      }
			
       if(laser==1||laser1==1)
       { 
	   	
       while(laser==1||laser1==1);
       lasercount();
       }

     

  if(count==0)
  {
    relay=1;
    led1=0;
    led2=0;
    led3=0;
  }
  
  if(count==1)
  {
    relay=1;
    led1=1;
    led2=0;
    led3=0;  
  }
  
 if(count==2)
  {
    relay=1;
    led1=1;
    led2=1;
    led3=0; 
  }
  
 if(count==3)
  {
    relay=0;
    led1=1;
    led2=1;
    led3=1;  
  }
  
	delay(200);	
 }
}
void lasercount()
{
    count++;
 }

void reset()
{
 count=0;
}
void delay(unsigned int itime)
 {
 unsigned int i,j;
 for (i=0;i<itime;i++)
 for (j=0;j<1275;j++);
 }