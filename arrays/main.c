/* 
 * Name:        	Keegan Mullaney
 * Date:        	05/18/2003
 * Description: 	Creates a building or moving animation on the output screen
 */

// for Linux
#include "../conio.h"

// for MS-DOS
//#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <time.h>
#include <ctype.h>

#define NUMROWS 3
#define NUMCOLS 3
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

/* function prototypes */
void readData(char drawVals[NUMROWS][NUMCOLS], char blankVals[NUMROWS][NUMCOLS]);
void drawFigure(int x, int y, char drawVals[NUMROWS][NUMCOLS]);
void pause(int pauseTime);
void eraseFigure(int x, int y, char blankVals[][NUMCOLS]);
void animate(char drawVals[NUMROWS][NUMCOLS], char blankVals[NUMROWS][NUMCOLS]);

int main(void) 
	{
		char drawVals[NUMROWS][NUMCOLS], blankVals[NUMROWS][NUMCOLS];
		readData(drawVals,blankVals);
		animate(drawVals,blankVals);
		return 0;
	}

/*******************FUNCTION DEFINITIONS*************************/

void readData(char drawVals[][NUMCOLS], char blankVals[][NUMCOLS])
	{
		int i,j;
		char k;
		FILE *fp;
		fp = fopen ("data6bus.txt","r");
		if (fp == NULL)									/* if fopen doesn't work, this if statement will let us know */
			{
				printf("Error opening data file!\n");
				exit (1);								   /* exit (1) will exit program */
			}
		else
			{
				for (i = 0; i < NUMROWS; i++)			/* nested for loop assigns characters to each point in array  */
					{
						for (j = 0; j < NUMCOLS; j++)
							{							      /* fgetc() scans the file for characters and stores a different */
								k = fgetc (fp);			/* one in k each time through the loop. */
								if (iscntrl (k)) j--;	/* if fgetc encounters a new line, then we don't want to store  */
														      /* it in the variable k. */
								else					      /* each individual location in the array will be given the value */
									{					      /* of k each time through the loop. */
										drawVals[i][j] = k;
										blankVals[i][j]	= ' ';				
									}
							}
					}
			}
		fclose (fp);
	}

void drawFigure(int x, int y, char drawVals[][NUMCOLS])
	{
		int i,j;
		for (i = 0; i < NUMROWS; i++)
			{
				_gotoxy(x,y+i);
				for (j = 0; j < NUMCOLS; j++)
					printf("%c",drawVals[i][j]);
			}
		fflush (stdout);
	}

void eraseFigure(int x, int y, char blankVals[][NUMCOLS])
	{
		int i,j;
		for (i = 0; i < NUMROWS; i++)
			{
				_gotoxy(x,y+i);
				_textcolor(BLACK);
				for (j = 0; j < NUMCOLS; j++)
					printf("%c",blankVals[i][j]);
			}
		fflush (stdout);
	}

void pause(int pauseTime)
	{
		pauseTime = clock() + pauseTime;
 		while(clock() < pauseTime) 		/* wait pauseTime msec */
			;
	}

void animate(char drawVals[][NUMCOLS], char blankVals[][NUMCOLS])
	{
	
	/***************************MOVING AND BUILDING ANIMATION**************************/
		
		int i,j,k,m=0,n=24;
		for (i = 0; i <= 24; i++)							/* loops whole process creating 25 columns of figures */
			{
				m += 3;
				n -= 3;
				for (j = 0; j <= 78 - m; j++)				/* loops figures across screen at every x coordinate */
					{										      /* each loop becomes smaller by m or 1 set of arrows */
						if (i < 4)
							_textcolor(CYAN);
						else if ((i >= 4) && (i < 11))
							_textcolor(MAGENTA);
						else if ((i >= 11) && (i < 18))
							_textcolor(CYAN);
						else
							_textcolor(MAGENTA);
						for (k = j; k <= j; k++)			/* draws figure at specified x,y coordinates */
							{
								if (m < 24)
									{
										drawFigure(k,m-3,drawVals);
										drawFigure(k,n,drawVals);
									}
								if ((m >= 24) && (m <= 45))
									{
										drawFigure(k,m-24,drawVals);
										drawFigure(k,n+21,drawVals);
									}
								if ((m > 45) && (m <= 66))
									{
										drawFigure(k,m-45,drawVals);
										drawFigure(k,n+42,drawVals);
									}
								if ((m >= 66) && (m <= 75))
									{
										drawFigure(k,m-66,drawVals);
										drawFigure(k,n+63,drawVals);
									}
							}
								pause(5);
						for (k = j-3; k <= j-3; k++)		/* erases each figure after 5 msec */
							{								      /* erases to j-3 each time leaving one set of arrows */
								if (m < 24)
									{
										eraseFigure(k,m-3,blankVals);	
										eraseFigure(k,n,blankVals);
									}
								if ((m >= 24) && (m <= 45))
									{
										eraseFigure(k,m-24,blankVals);
										eraseFigure(k,n+21,blankVals);
									}
								if ((m > 45) && (m <= 66))
									{
										eraseFigure(k,m-45,blankVals);
										eraseFigure(k,n+42,blankVals);
									}
								if ((m >= 66) && (m <= 75))
									{
										eraseFigure(k,m-66,blankVals);
										eraseFigure(k,n+63,blankVals);
									}
							}
					}
			}
		_gotoxy(0,0);
	}
