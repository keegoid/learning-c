/* 
 * Name:        	Keegan Mullaney
 * Date:        	
 * Description: 	practice with colors
 */

#include <stdio.h>
#include <conio.h>    /* for MS-DOS */

int main(void) 
{
	int i;

	for(i = 0; i < 16; ++i)		/* print # chars in 16 colors on first line */
	{							
		_gotoxy(i, 0);
		_textcolor(i);
		printf("#");
	}
	fflush(stdout);				/* force any char in output (console) buffer to screen */
	_textcolor(0);			      /* set the text color to black */

	for(i = 0; i < 16; ++i)		/* print black #'s with 16 background colors on 3rd line*/
	{
		_gotoxy(i, 2);
		_textbackground(i);
		printf("#");
	}
	fflush(stdout);				/* flush the buffer of remaining characters */

	for(i = 0; i < 16; ++i)		/* print a space with 16 background colors on 5th line*/
	{
		_gotoxy(i, 4);
		_textbackground(i);
		printf(" ");
	}
	fflush(stdout);
	
	return 0;
}
