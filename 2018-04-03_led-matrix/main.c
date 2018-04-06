#include<reg52.h> 
#define DataPort P1 			 

sbit LATCH1=P2^0;				  
sbit LATCH2=P3^5;				 
sbit P21=P2^1; 


unsigned char code Smile[] = {0x00, 0x00, 0x24, 0x24, 0x81, 0x42, 0x3c, 0x00};
unsigned char code Up[]    = {0x18, 0x3c, 0x66, 0xc3, 0x00, 0x00, 0x00, 0x00};
unsigned char code Left[]  = {0x18, 0x30, 0x60, 0xc0, 0xc0, 0x60, 0x30, 0x18};
unsigned char code Down[]  = {0x00, 0x00, 0x00, 0x00, 0xc3, 0x66, 0x3c, 0x18};
unsigned char code Right[] = {0x18, 0x0c, 0x06, 0x03, 0x03, 0x06, 0x0c, 0x18};

unsigned char code Line[] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};

void Delay(unsigned int t); 	  //   delay
void Draw(unsigned char code *img);	//display not moving image		 

void InitInterrupt(){
	EA = 1;
	EX0 = 1;
	IT0 = 1;
}


main()
{
  P1 = 0x00;						 
	P21 = 0;	
 	InitInterrupt();					 
		  
	while(1){
		
		
	}				
}

void Delay(unsigned int t){
	while(--t);
}

void Draw(unsigned char code *img){
	unsigned int i;	
	
	for (i = 0; i < 8; i++)
	{
		DataPort = 0x0; 					 
		LATCH1 = 1;
		LATCH1 = 0;

		DataPort = Line[i]; 		
		LATCH2 = 1;
		LATCH2 = 0;

		DataPort = img[i];		   
		LATCH1 = 1;
		LATCH1 = 0;
	}
}




