#include<lpc21xx.h>
#include"keypad.h"
/*unsigned char keypad_lut[4][4] = {7,8,9,11,
			                            4,5,6,12,
			                            1,2,3,13,
				                          10,0,14,15};*/
unsigned char keypad_lut[4][4] = {'7','8','9','/',
																	'4','5','6','*',
																	'1','2','3','-',
																	'C','0','=','+'};


//variables declaration
unsigned char rowval,colval,KeyC;
unsigned int c0,c1,c2,c3;
int keydetect(){
	  IODIR1 |= ((1<<ROW0)|(1<<ROW1)|(1<<ROW2)|(1<<ROW3));
	  IOCLR1 = ((1<<ROW0)|(1<<ROW1)|(1<<ROW2)|(1<<ROW3));
		//waiting for switch press
		//read the all columns status and any one of the column is 0 then switch is pressed
		while(1)
		{
			c0 = ((IOPIN1>>COL0)&1);
			c1 = ((IOPIN1>>COL1)&1);
			c2 = ((IOPIN1>>COL2)&1);
			c3 = ((IOPIN1>>COL3)&1);
			if((c0&c1&c2&c3) == 0)
				break;
		}
	//row identification process
		while(1)
		{
			//row0 identification
			
			//row0 making low
			IOCLR1 = (1<<ROW0);
			//remining rows making high
			IOSET1 = ((1<<ROW1)|(1<<ROW2)|(1<<ROW3));
			//if any one of the column value is 0 then row value is 0 then no need to check other rows
			c0 = ((IOPIN1>>COL0)&1);
			c1 = ((IOPIN1>>COL1)&1);
			c2 = ((IOPIN1>>COL2)&1);
			c3 = ((IOPIN1>>COL3)&1);
			if((c0&c1&c2&c3) == 0)
			{
				rowval = 0;
				break;
			}
			//row1 identification

			//row1 making low
			IOCLR1 = (1<<ROW1);
			//remining rows making high
			IOSET1 = ((1<<ROW0)|(1<<ROW2)|(1<<ROW3));
			//if any column value is 0 then row value is 1 then no need to check other rows
			c0 = ((IOPIN1>>COL0)&1);
			c1 = ((IOPIN1>>COL1)&1);
			c2 = ((IOPIN1>>COL2)&1);
			c3 = ((IOPIN1>>COL3)&1);
			if((c0&c1&c2&c3) == 0)
			{
				rowval = 1;
				break;
			}
			
			//row2 identification

			//row2 making low
			IOCLR1 = (1<<ROW2);
			//remining rows making high
			IOSET1 = ((1<<ROW0)|(1<<ROW1)|(1<<ROW3));
			//if any column value is 0 then row value is 2 then no need to check other rows
			c0 = ((IOPIN1>>COL0)&1);
			c1 = ((IOPIN1>>COL1)&1);
			c2 = ((IOPIN1>>COL2)&1);
			c3 = ((IOPIN1>>COL3)&1);
			if((c0&c1&c2&c3) == 0)
			{
				rowval = 2;
				break;
			}

			//row3 identification

			//row3 making low
			IOCLR1 = (1<<ROW3);
			//remining rows making high
			IOSET1 = ((1<<ROW0)|(1<<ROW1)|(1<<ROW2));
			//if any column value is 0 then row value is 3
			c0 = ((IOPIN1>>COL0)&1);
			c1 = ((IOPIN1>>COL1)&1);
			c2 = ((IOPIN1>>COL2)&1);
			c3 = ((IOPIN1>>COL3)&1);
			if((c0&c1&c2&c3) == 0)
			{
				rowval = 3;
				break;
			}
		}

	//columns identification process
	//if col0 status is low then column value is 0
	if(((IOPIN1>>COL0)&1) == 0)
		colval = 0;
	//else if col1 status is low then column value is 1
	else if(((IOPIN1>>COL1)&1) == 0)
		colval = 1;
	//else if col2 status is low then column value is 2
	else if(((IOPIN1>>COL2)&1) == 0)
		colval = 2;
	//else if col3 status is low then column value is 3
	else if(((IOPIN1>>COL3)&1) == 0)
		colval = 3;

	//waiting for switch release
	//read the all columns status and any one of the column is 0 then switch is pressed so wait here until switch is released
	while(1)
	{
		c0 = ((IOPIN1>>COL0)&1);
		c1 = ((IOPIN1>>COL1)&1);
		c2 = ((IOPIN1>>COL2)&1);
		c3 = ((IOPIN1>>COL3)&1);
		if((c0&c1&c2&c3) != 0)
			break;
	}
	//collect the pressed switch equivalent value from defined keypad lookup table and display it on any o/p device	
	KeyC = keypad_lut[rowval][colval];
	return KeyC;
}
