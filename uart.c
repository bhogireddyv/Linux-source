#include<lpc214x.h>

void initclock(void);
void intiuart0(void);
void u0write(char data);
void send_string(char *str);
void delay(unsigned char t);
char string[]="hello bangalore\n";

void delay(unsigned char t)
{
   unsigned int i,j;
	for(i=0;i<t;i++)
	   for(j=0;j<1234;j++);
}

void inticlock()
{
  PLL0CON=0X01;
  PLL0CFG=0X24;
  PLL0FEED=0XAA;
  PLL0FEED=0X55;
  while(!(PLLSTAT&0X400));
  PLL0CON=0X03;
  PLL0FEED=0XAA;
  PLL0FEED=0X55;
  VPBDIV=0X01;
}

void inituart0()
{
    PINSEL0 &=0x5;//p0.1 for Rxd and p0.0 for Txd
     U0LCR=0X83;//DLAB=1
     U0DLL=110;
     U0DLM=1;
     U0FDR=0XF1;
     U0LCR=0X03;//8bits and parity=0 stopbit=1
     U0FCR=0X04;
     U0IER=0X03;//enable the transmit interrupt(THBR)
}

int main()
{
  initclock();
  inituart0()
  while(1)
  {
     send_string(string);
     delay(50);
   }
}

void uowrite(char str)
{

  while(!(U0LSR & (1<<5)))
	U0THR=str;
}
void send_string(char *str)
{
    while(*str!=0x00)
    {
	uowrite(*str)
	str++;
	delay(50);
     }
}