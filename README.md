# Medicine-Time-Reminder
#Overview
->The Medicine Time Reminder is a real-time clock (RTC) and alarm-based reminder system developed using the LPC2124 microcontroller. This project is designed to alert users to take their medicine on time through a user-friendly interface.

#Features
->Initial Display of Rules: For 2-3 seconds at startup, the system displays the rules indicating which key is for what purpose. The '=' key is used as the enter key, and 'C' is used for backspace.
->Menu Navigation: Switch 1 is used to access the menu for editing the RTC and setting the medicine time.
->Time and Date Display: The current time is displayed in the format h:m:s. The day is displayed at the end of the first row. The second row displays the date in the format day/month/year, and the medicine time in the format h:m.

#Technologies Used
Microcontroller: LPC2124
Languages: C, Embedded C
Tools: KEIL uVision, Proteus for simulation
Peripherals: LCD, Keypad, Pushbuttons, LEDs, Buzzer

#Improved User Interface
The interface has been enhanced to be more user-friendly, making it easier for users to navigate and set alarms.
->Changeable Options: All time and date options are changeable upon selecting the menu options.
->Alarm Functionality: When the set medicine time matches the real-time, the buzzer is activated, and the message "take medicine" is displayed.
->Reset Functionality: Pressing Switch 2 clears the message, resets the display to show the current time, date, day, and medicine time, and turns off the buzzer.
