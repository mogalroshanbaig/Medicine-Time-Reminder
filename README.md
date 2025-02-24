# Medicine Time Reminder

## Overview
The Medicine Time Reminder is a real-time clock (RTC) and alarm-based reminder system developed using the LPC2124 microcontroller. This project is designed to alert users to take their medicine on time through a user-friendly interface.

## Features
- **Initial Display of Rules**: Displays key functions for 2-3 seconds at startup, with '=' as the enter key and 'C' for backspace.
- **Menu Navigation**: Use Switch 1 to access the menu for editing the RTC and setting the medicine time.
- **Time and Date Display**: Displays time in h:m:s format, day at the end of the first row, and date in day/month/year format along with medicine time in h:m format at the end of the second row.
- **Changeable Options**: Allows users to change time, date, and medicine time via the menu.
- **Alarm Functionality**: Activates buzzer and displays "take medicine" message when the medicine time matches the real-time.
- **Reset Functionality**: Pressing Switch 2 clears the message, resets the display to show the current time, date, day, and medicine time, and turns off the buzzer.

## Improved User Interface
Enhanced interface for a more intuitive and user-friendly experience.

## Technologies Used
- **Microcontroller**: LPC2124
- **Languages**: C, Embedded C
- **Tools**: KEIL uVision, Proteus for simulation
- **Peripherals**: LCD, Keypad, Pushbuttons, LEDs, Buzzer

## Getting Started
### Prerequisites
- LPC2124 microcontroller
- LCD display
- Keypad
- Pushbuttons
- LEDs
- Buzzer
- KEIL uVision
- Proteus for simulation

### Installation
 Clone the repository:
   ```bash
   git clone https://github.com/mogalroshanbaig/Medicine-Time-Reminder.git
