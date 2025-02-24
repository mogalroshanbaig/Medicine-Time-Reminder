//Header file to lcd 
#include<lpc21xx.h>
#include"lcd.h"
void delay_ms(unsigned int dlyMs){
    for(dlyMs *= 12000; dlyMs > 0; dlyMs--);
}
void LCDcommand(unsigned char mycmd){
    IODIR0 |= (1 << RS) | (1 << RW) | (1 << EN) | (0xFF << CMD);
    IOCLR0 = (1 << RS);//RS=0
    IOCLR0 = (1 << RW);//RW=0
    IOSET0 = (mycmd << CMD);
    IOCLR0 = (~mycmd << CMD);
    IOSET0 = (1 << EN);
	  /*while(isLCDBusy()){
		}*/
    delay_ms(10);
    IOCLR0 = (1 << EN);
}

void LCDdata(unsigned char mydata){
	  IODIR0 |= (1 << RS) | (1 << RW) | (1 << EN) | (0xFF << CMD);
    IOSET0 = (1 << RS);//RS=1
    IOCLR0 = (1 << RW);//RW=0
    IOSET0 = (mydata << CMD);
    IOCLR0 = (~mydata << CMD);
    IOSET0 = (1 << EN);
    delay_ms(1);
	  //while(isLCDBusy());
    IOCLR0 = (1 << EN);
}


void initLCD(void){
    LCDcommand(0x38);
    LCDcommand(0x0C);
    LCDcommand(0x06);
    LCDcommand(0x01);
    LCDcommand(0x80);
}
void LCDyr(unsigned int num){
	unsigned int a[10];
	int i=0;
	if(num==0){
		LCDdata(num+48);
	}else{
		while(num){
			a[i++]=(num%10);
			num=num/10;
		}
	}
	for(i--;i>=0;i--)
	LCDdata(a[i]+48);
}
