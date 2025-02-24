#define RS 3
#define RW 5
#define EN 7
#define CMD 8
void LCDyr(unsigned int num);
void LCDcommand(unsigned char);
void LCDdata(unsigned char);
void initLCD(void);
void delay_ms(unsigned int);
