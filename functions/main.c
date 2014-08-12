/* 
 * Name:        	Keegan Mullaney
 * Date:        	05/01/2003
 * Description: 	Functions to create a horizontal, vertical line of characters and a filled, and empty box.
 *					   Program then uses these functions to draw a picture.
 */

#include <stdio.h>
#include <conio.h>
#define BLACK 0
#define DARKBLUE 1
#define DARKGREEN 2
#define DARKCYAN 3
#define DARKRED 4
#define DARKMAGENTA 5
#define DARKYELLOW 6
#define DARKWHITE 7
#define GREY 8
#define BLUE 9
#define GREEN 10
#define CYAN 11
#define RED 12
#define MAGENTA 13
#define YELLOW 14
#define WHITE 15

void horzLine(int x, int y, int length, char sym, int color);    			   /* horzLine() prototype */
void vertLine(int x, int y, int length, char sym, int color);    			   /* vertLine() prototype */
void boxFilled(int x, int y, int width, int height, char sym, int color);	/* boxFilled() prototype */ 
void boxOpen(int x, int y, int width, int height, char sym, int color);		/* boxOpen() prototype */ 


int main(void)
{
	int b;
	horzLine (5, 1, 10, '*', RED);    			/* horzLine() function call */
	
	vertLine (1, 1, 5, '#', GREEN);    			/* vertLine() function call */
	
	boxFilled (18, 1, 5, 4, '=', MAGENTA);		/* boxFilled() function call */ 
	
	boxOpen (30, 1, 5, 4, '+', BLUE);			/* boxOpen() function call */ 

/*********************************************************/
			/* business drawing section */	
	
	vertLine (5, 10, 14, '|', WHITE);
	horzLine (5, 23, 70, '_', WHITE);
	
	for (b = 0; b < 13; b = 2 + b)
		horzLine (4, 21 - b, 1, '_', WHITE);
	
	for (b = 0; b < 13; b = 2 + b)
		horzLine (3, 21 - b, 1, '$', WHITE);
	
	for (b = 0; b < 68; b = 2 + b)
		vertLine (73 - b, 24, 1, '|', WHITE);
	
	boxFilled (6, 10, 69, 13, '.', BLUE);
	
	boxOpen (5, 6, 70, 3, '*', BLUE);
	_gotoxy(6,7);
	_textcolor(YELLOW);
	printf("----------------------------STOCK CHART-----------------------------");

	horzLine (6, 20, 10, '_', YELLOW);
	vertLine (16, 16, 5, '|', YELLOW);
	horzLine (17, 15, 5, '_', YELLOW);
	vertLine (22, 16, 2, '|', YELLOW);
	horzLine (23, 17, 10, '_', YELLOW);
	vertLine (33, 18, 4, '|', YELLOW);
	horzLine (34, 21, 10, '_', YELLOW);
	vertLine (44, 17, 5, '|', YELLOW);
	horzLine (45, 16, 20, '_', YELLOW);
	
	for (b = 0; b < 5; ++b)									      /*************************/
	horzLine (66 + 2 * b - 1, 15 - b, 1, '_', YELLOW);		/*                       */ 
															            /* draws a diagonal line */	
	for (b = 0; b < 6; ++b)									      /*                       */
	vertLine(65 + 2 * b - 1, 16 - b, 1, '|', YELLOW);		/*************************/
	
	return 0;
}

void horzLine(int x, int y, int length, char sym, int color)    	/* horzLine() definition */
{
	int i;
	
	_gotoxy(x, y);		   /* _gotoxy() function puts cursor and specific x and y coordinates on output screen */
	_textcolor(color);	/* _textcolor() changes the color of text on output screen based on numbers 0 - 15 */
	
	for (i = 0; i < length; ++i)
		printf("%c",sym);
	fflush(stdout);		/* fflush(stdout) forces characters on the output screen (like a refresh for placeholders) */
}

void vertLine(int x, int y, int length, char sym, int color)    	/* vertLine() definition */
{
	int i;
	
	_textcolor(color);

	for (i = 0; i < length; ++i)
	{
		_gotoxy(x, i + y);
		printf("%c",sym);
	}
	fflush(stdout);
}

void boxFilled(int x, int y, int width, int height, char sym, int color)	/* boxFilled() definition */ 
{
	int a;
	
	for (a = 0; a < height; ++a)
		horzLine(x , a + y, width, sym, color);
	
	fflush(stdout);
}

void boxOpen(int x, int y, int width, int height, char sym, int color)		/* boxOpen() definition */ 
{
	boxFilled(x, y, width, height, sym, color);
	boxFilled(1 + x, 1 + y, width - 2, height - 2, ' ', color);
}
