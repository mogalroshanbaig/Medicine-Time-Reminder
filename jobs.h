//All declarations and definitions of mini project jobs(different tasks)
#define MENU_SW 30 //selecting PORT1.28 as the Switch1 port
#define BUZZ_SW 25//selecting PORT1.29 as the Switch2 i.e.Buzzer Switch
//JOB0
void modes(void);
//JOB1
void init_components(void);
void displaytime(void);
//JOB2
void displaymenu(void);
//JOB3
void displayString(char *);
void displayoptions_rtc(void);
void displayoptions_mt(void);
//JOB4
unsigned int ReadNum(void);
void display_menu_options(unsigned char);
void wronginput(void);
void back_rtc(void);
void set_keypress(void);
//JOB5
void setalarm(void);
void displayalarm(void);
void checkalarm(void);
void turn_off_alarm(void);
