#include<lpc214x.h>
#include<stdint.h>

void uart0init(void);
void uart0txchar(char ch);
void uart0sendstring(char *str);
unsigned char uart0_rxchar(void);
void uart0_rxstring(void);

char rec_string[100];
char string[100];
void delay(int t);
{
   unsigned int i,j;
   for(i=0;i<t;i++)
     for(j=0;j<1234;j++);
}

void uart0init(void)
{
  PINSEL0=0x05;
  U0LCR=0X83;
  U0DLL=0X00;
  U0DLM=0X00;
  U0DLL=0X61;
  U0LCR=0X03;
}

void uart0txchar(char ch)
{
  UOTHR=ch;
  while((U0LSR)& 0x40));
}

void uart0sendstring(char *str)
{
  unsigned int t=0;
  while(str[i]!='\0')
  {
     uart0txchar(str[i]);
     i++;
   }
}

unsigned char uart0rxchat(void)
{
  while((U0LSR &0x01)==0);
    retrun U0RBR;
}

void uart0rxstring(void)
{
  unsigned int i=0;
  do{
   while((U0LSR &0x01)==0);
     rec_string[i]=U0RBR;
       i++;
   }while((U0RBR!=0x0D));
}

int main()
{
char receive;
 uart0init();

 while(1)
 {
     UART0_SendString("uart ready");
     UART0_SendString("\r\n");
     UART0_SendString("\r\n");
     receive = UART0_RxChar();
     UART0_SendString("\r\n");
     UART0_SendString("Received:");
     UART0_TxChar(receive);
     UART0_SendString("\r\n");
 }
}
