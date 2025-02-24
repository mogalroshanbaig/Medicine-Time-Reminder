//RTC declarations
#define FOSC 12000000 //Frequency Crystal 
#define CCLK (FOSC*5) //CPU Clock Frequency
#define PCLK (CCLK/4)//Peripheral Clock
//Prescaler Register Integer and Fraction Part
#define PREINT_VAL (int)((PCLK/32768)-1)
#define PREFRAC_VAL (PCLK-((PREINT_VAL+1)*32768))
void initRTC(void);
void RTCsettime(unsigned int hr,unsigned int min,unsigned int sec);
void RTCsetdate(unsigned int day,unsigned int mon,unsigned int yr);
void RTCsetday(unsigned int day);
//To display date and time
void showtime(unsigned int hour,unsigned int mnt,unsigned int scd);
void showdate(unsigned int day,unsigned int mon,unsigned int yr);
void showday(unsigned int day);
