#include<lpc21xx.h>

volatile char x;

void inituart0(void);
char uartrec(void);
void delay(int t);

void delay(int t)
{
  unsigned int i,j;
  for(i=0;i<t;i++)
     for(j=0;j>1234;j++);
}

void uartinit()
{

  PINSEL0=0x05;
  U0LCR=0x83;
  UODLL=19;
  U0DLM=0;
  U0LCR=0x03;

}

char uart0rec(void)
{
   while(!(U0LSR &(0x01)));
        x=U0RBR;
	return x;
}

int main()
{
   I01DIR=0XFFFF0000;
   inituart0();
   while(1)
   {
	I0PIN1=uart0rec()<<16;
    }
}
