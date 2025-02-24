//All the definitions of different jobs(tasks)
#include<lpc21xx.h>
#include"lcd.h"
#include"rtc.h"
#include"jobs.h"
#include"keypad.h"
/*-----------------------JOB-0 DISPLAY MODES--------------------------------------------*/
char *mode="modes: ",*ent="=:enter",*bck="C:backspace",*swt1="sw1:set RTC|MT",*swt2="sw2:Stop Buzzer";
void modes(){
	LCDcommand(0x01);//Clear Lcd
	  LCDcommand(0x80);//Cursor at first row
	  displayString(mode);
	  LCDcommand(0x86);
	  displayString(ent);
	  LCDcommand(0xC0);
	  displayString(bck);
	  delay_ms(2000);
	  LCDcommand(0x01);
	  LCDcommand(0x01);//Clear Lcd
	  LCDcommand(0x80);//Cursor at first row
	  displayString(swt1);
	  LCDcommand(0xC0);
	  displayString(swt2);
	  delay_ms(2000);
	  LCDcommand(0x01);
}
/*--------------------------------------------------------------------------------------*/
/*-----------------------JOB-1 DISPLAY TIME ON THE LCD----------------------------------*/
void init_components(){
	initLCD();
  delay_ms(100);
  initRTC();
  RTCsettime(02,9, 00);
  RTCsetdate(00,00,25);
}
void displaytime(){
  // Display the time and date initially
    showtime(HOUR, MIN, SEC);
    showdate(DOM, MONTH, YEAR);
		LCDcommand(0x8D);//Position cursor to third position from last,1st row
		showday(DOW);
	  delay_ms(1);
}
/*-----------------------------------------------------------------------------------------*/

/*--------------------------JOB-2 DISPLAY MAIN MENU ON LCD---------------------------------*/
char *rtcedit="1.RTC Edit";
char *mtupdate="2.M.T Update";
void displayString(char *str) {
	  while(*str)
		LCDdata(*str++);
    /*int i;
    for (i = 0; str[i] != '\0'; i++) {
        LCDdata(str[i]);
    }*/
}
void displaymenu(void){
	// Clear the screen
  LCDcommand(0x01);
  // Position cursor to 1st row
  LCDcommand(0x80);
  // Display the first string
  displayString(rtcedit);
  // Move to 2nd row
  LCDcommand(0xC0);
  // Display the second string
  displayString(mtupdate);
}
/*------------------------------------------------------------------------------------------*/
/*---------------------------JOB-3 KEYPAD CONNECTION AND OPTIONS DISPLAY--------------------*/
char *options="1.H 2.M 3.S 4.DM";
char *options1="5.MN 6.Y 7.DW8.E";
char *options2="Enter M.T:";
unsigned char options3[]="H:M:S ENTER:=";
void displayoptions_rtc(){
	// Clear the screen
  LCDcommand(0x01);
  // Position cursor to 1st row
  LCDcommand(0x80);
  // Display the first string
  displayString(options);
  // Move to 2nd row
  LCDcommand(0xC0);
  // Display the second string
  displayString(options1);
}
void displayoptions_mt(){
	// Clear the screen
  LCDcommand(0x01);
  // Position cursor to 1st row
  LCDcommand(0x80);
  // Display the first string
  //displayString(options2);
  // Move to 2nd row
  //LCDcommand(0xC0);
	//display second string
	//displayString(options3);
}
void display_menu_options(unsigned char key){
	  /*if(key=='1'){
			displayoptions_rtc();
		}else if(key=='2')
			displayoptions_mt();*/
	switch(key){
		case '1':
			displayoptions_rtc();
		break;
		case '2':
			displayoptions_mt();
		break;
		/*case '=':
			LCDcommand(0x01);
			displaytime();
		break;*/
	}
}
/*------------------------------------------------------------------------*/
/*----------------------JOB-4 SET TIME------------------------------------*/
static int result = 0;
unsigned char key;
unsigned int ReadNum(void)
{
	unsigned int KeyC,num=0;
	//LCDcommand(0x01);
	while(1)
	{
		KeyC = keydetect();
		if((KeyC>='0') && (KeyC<='9'))
		{
			LCDdata(KeyC);
			num = (num*10) + (KeyC-48);
		}
		else if(KeyC == 'C')//for backspace
		{
			if(num>0)
			{
				num = num/10;
				LCDcommand(0x10);//To shift cursor to left
				LCDdata(' ');
				LCDcommand(0x10);
			}
		}
		else if(KeyC == '=')//for enter
			break;
	}
	return num;	
}
void wronginput(void)
{
	LCDcommand(0x01);
	LCDcommand(0x80);
	displayString("WRONG INPUT");
	delay_ms(300);
	LCDcommand(0xC0);
	displayString("ENTER AGAIN");
  delay_ms(300);
	LCDcommand(0x01);
	result=ReadNum();
}

void back_rtc(){
	displayoptions_rtc();
	delay_ms(100);
	set_keypress();
}
void set_keypress(){
	  key=keydetect();
    switch(key){
        case '1'://set hour
            // Clear the screen
            LCDcommand(0x01);
            // Position cursor to 1st row
            LCDcommand(0x80);
				    displayString("Enter hr:");
				    LCDcommand(0xC0);//cursor to 2nd row
            // Set hour (enter two digits)
            result=ReadNum(); // Convert char to int for ones place
				    if(result>23){
							wronginput();
						}
            HOUR = result;
				    back_rtc();
            break;

        case '2'://set minute
             // Clear the screen
            LCDcommand(0x01);
            // Position cursor to 1st row
            LCDcommand(0x80);
				    displayString("Enter min:");
				    LCDcommand(0xC0);//cursor to 2nd row
            // Set Minute (enter two digits)
            result=ReadNum(); // Convert char to int for ones place
				    if(result>59){
							wronginput();
						}
            MIN = result;
				    back_rtc();
            break;

        case '3'://set second
             // Clear the screen
            LCDcommand(0x01);
            // Position cursor to 1st row
            LCDcommand(0x80);
				    displayString("Enter sec:");
				    LCDcommand(0xC0);//cursor to 2nd row
            // Set second (enter two digits)
            result=ReadNum(); // Convert char to int for ones place
				    if(result>59){
							wronginput();
						}
            SEC = result;
				    back_rtc();
            break;
        case '4': //DAY OF MONTH
					  // Clear the screen
            LCDcommand(0x01);
            // Position cursor to 1st row
            LCDcommand(0x80);
				    displayString("Enter DOM:");
				    LCDcommand(0xC0);//cursor to 2nd row
            // Set Day of month (enter two digits)
            result=ReadNum(); // Convert char to int for ones place
				    if(result>31){
							wronginput();
						}
            DOM= result;
				    back_rtc();
            break;

        case '5'://MONTH
					   // Clear the screen
            LCDcommand(0x01);
            // Position cursor to 1st row
            LCDcommand(0x80);
				    displayString("Enter Month:");
				    LCDcommand(0xC0);//cursor to 2nd row
            // Set month (enter two digits)
            result=ReadNum(); // Convert char to int for ones place
				    if(result>12){
							wronginput();
						}
            MONTH = result;
				    back_rtc();
            break;

        case '6'://YEAR
					   // Clear the screen
            LCDcommand(0x01);
            // Position cursor to 1st row
            LCDcommand(0x80);
				    displayString("Enter Year:");
				    LCDcommand(0xC0);//cursor to 2nd row
            // Set year (enter two digits)
            result=ReadNum(); // Convert char to int for ones place
            YEAR = result;
				    back_rtc();
            break;

        case '7'://DAY OF WEEK
					   // Clear the screen
            LCDcommand(0x01);
            // Position cursor to 1st row
            LCDcommand(0x80);
				    displayString("Enter DOW:(0-6)");
				    LCDcommand(0xC0);//cursor to 2nd row
            // Set hour (enter two digits)
            result=ReadNum(); // Convert char to int for ones place
				    if(result>6){
							wronginput();
						}
            DOW = result;
				    back_rtc();
            break;

        case 'C':
					  LCDcommand(0x01);
				    displayoptions_rtc();
					  break;
    }
}

/*------------------------------------------------------------------------------------*/
/*----------------------------JOB-5 SETTING MEDICINE ALARM-----------------------------*/
char *msg="Take Medicine",*opthr="Enter hr:",*optm="Enter min:",*opts="Enter sec:";
static int alarmhr=2,alarmmin=50,alarmsec=10;
extern int alarmtriggered;
void displayalarm(){
	LCDcommand(0xC9);
	LCDdata('M');
	LCDdata('-');
	LCDdata((alarmhr/10)+48);
	LCDdata((alarmhr%10)+48);
	LCDdata(':');
	LCDdata((alarmmin/10)+48);
	LCDdata((alarmmin%10)+48);
}
void setalarm(){
	LCDcommand(0x01);
	LCDcommand(0x80);
	displayString(opthr);
	LCDcommand(0xC0);
	alarmhr=ReadNum();
	delay_ms(100);
	LCDcommand(0x01);
	LCDcommand(0x80);
	displayString(optm);
	LCDcommand(0xC0);
	alarmmin=ReadNum();
	LCDcommand(0x01);
	LCDcommand(0x80);
	displayString(opts);
	LCDcommand(0xC0);
	alarmsec=ReadNum();
}

// Function to check alarm
void checkalarm() {
	  IODIR1 |= (1 << 24); // Set LED pin as output
    if (HOUR == alarmhr && MIN == alarmmin && SEC == alarmsec) {
        // Turn on LED
        IOSET1 = (1 << 24); // Turn on LED
			  LCDcommand(0x01);//clear screen
			  LCDcommand(0x80);//cursor to first row
			  displayString(msg);
        alarmtriggered = 1; // Set alarm triggered flag
    }
}

// Function to turn off the alarm
void turn_off_alarm() {
    IOCLR1 = (1 << 24); // Turn off LED
	  LCDcommand(0x01);//clear screen
    alarmtriggered = 0; // Reset alarm triggered flag
}
/*--------------------------------------------------------------------------------*/
