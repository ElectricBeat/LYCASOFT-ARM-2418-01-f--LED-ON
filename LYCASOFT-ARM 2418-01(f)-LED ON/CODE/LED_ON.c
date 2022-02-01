#include <lpc21xx.h>

void delay_ms(unsigned int count)
{
  unsigned int j=0,i=0;
  for(j=0;j<count;j++)
  {
    for(i=0;i<333;i++);
  }
}

int main() 
{
	int i;
	int k;
	
  PINSEL0 = 0x0000;			//Configure the P0 Pins for GPIO;
  PINSEL1 = 0x0000;			//Configure the P1 Pins for GPIO;
  PINSEL2 = 0x00000000;			//Configure the P1 Pins for GPIO;
	
  IODIR0 = 0xffffffff;			//Configure the P0 pins as OUTPUT;
	IODIR1 = 0xffffffff;			//Configure the P1 pins as OUTPUT;

  while(1)
  {
		k=0x01;
		
		for(i=0;i<32;i++)
		{
			IOSET0 = k;		// Make all the Port pins as high  
 			 delay_ms(100);
			
			IOCLR0 = k;		// Make all the Port pins as low 
			k = k<<1;
		}
		
		k = 0x010000;
//		k = k<<16;
		
		for(i=0;i<16;i++)
		{
			IOSET1 = k;		// Make all the Port pins as high
			 delay_ms(100);
			
			IOCLR1 = k;		// Make all the Port pins as low
			k = k<<1;
		}
  }
}