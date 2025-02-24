#include<lpc21xx.h>
#include"lcd.h"
#include"rtc.h"
#include"jobs.h"
#include"keypad.h"
unsigned char keyc,i;
int menu_displayed=0;
int alarmtriggered=0;
int main() {
    // Initialize LCD and RTC
    init_components();
	  //Modes
	  modes();
	  //delay_ms(1000);
    while (1) {
			  if(!alarmtriggered){
        displaytime();
			  displayalarm();
				}
        checkalarm();

        // Check if the menu switch is pressed (active-low switch)
        if ((IOPIN1 & (1 << MENU_SW)) == 0 && !menu_displayed) {
            displaymenu();
					  /* 1. RTC Edit
               2. M.T Update */
            menu_displayed = 1;
            while ((IOPIN1 & (1 << MENU_SW)) == 0); // Wait until the switch is released
					  //delay_ms(1000);
					
					  keyc = keydetect(); // Press the key to select menu
            display_menu_options(keyc);
					  /* 1. H 2. M 3. S 4. DM 5. MN 6. Y 7. DW 8. E */
            
            if (keyc == '1') {
                set_keypress();
							  LCDcommand(0x01);
            }else if (keyc == '2') {
                LCDcommand(0x01);
                setalarm();
            }
						//delay_ms(1000);
						LCDcommand(0x01);
            menu_displayed = 0; // Reset menu flag after setting time/alarm
        }

        // Check if the alarm switch is pressed to turn off the alarm
				while( alarmtriggered){
        if ((IOPIN1 & (1 << BUZZ_SW)) == 0) {
            turn_off_alarm();
            while ((IOPIN1 & (1 << BUZZ_SW)) == 0); // Wait until the switch is released
					  //delay_ms(1000);
        }
			}
    }

	}
