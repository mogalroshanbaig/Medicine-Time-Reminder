#include<lpc21xx.h>
#include"rtc.h"
#include"lcd.h"
signed char week[][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

void initRTC(void){
	  //Clock Control Register,controls the operation of clock divide circuit
    CCR = (1 << 1);//Reset the Timer,CCR 5bit register out of 1st bit is reset bit
    PREINT = PREINT_VAL;//PreScaler integer portion to reduce the frequency speed,provide it to the timer
    PREFRAC = PREFRAC_VAL;//Prescaler fraction portion
    CCR = (1 << 0) | (1 << 4);//0th bit is Enable bit,4th bit is clock source bit
}

void RTCsettime(unsigned int hr, unsigned int min, unsigned int sec){
    HOUR = hr;
    MIN = min;
    SEC = sec;
}
void RTCsetdate(unsigned int day,unsigned int mon,unsigned int yr){
	DOM=day;
	MONTH=mon;
	YEAR=yr;
}
void showtime(unsigned int hour,unsigned int mnt,unsigned int scd){
	LCDcommand(0x80);
	LCDdata((hour/10)+48);
	LCDdata((hour%10)+48);
	LCDdata(':');
	LCDdata((mnt/10)+48);
	LCDdata((mnt%10)+48);
	LCDdata(':');
	LCDdata((scd/10)+48);
	LCDdata((scd%10)+48);
}


void showdate(unsigned int day,unsigned int mon,unsigned int yr){
	LCDcommand(0xC0);
	LCDdata((day/10)+48);
	LCDdata((day%10)+48);
	LCDdata('/');
	LCDdata((mon/10)+48);
	LCDdata((mon%10)+48);
	LCDdata('/');
	LCDyr(yr);
}
void showday(unsigned int day){
	  signed char *ptr=week[day];
	  while(*ptr)
			LCDdata(*ptr++);
}
