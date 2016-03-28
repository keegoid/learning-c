/* 
  Name:        	Keegan Mullaney
  Date:        	06/02/2003
  Description: 	Takes a binary file, reads its data based on user input and returns it in a struct
 */

// for Linux
#include "../conio.h"

// for MS-DOS
//#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
//#include <curses.h>

#define ARRAYSIZE 20

typedef struct city_t				/* types */
	{
		char name[ARRAYSIZE];		/* city name */
		char state[3];				   /* state two-letter abbreviation */
		double revenue;				/* 2000 revenue from all sources in millions */
		int population;				/* 2000 population in thousands */
	}	city_t;

/* function prototypes */
int read_print_data (struct city_t *rec1,struct city_t *rec2,struct city_t *rec3,struct city_t *rec4,struct city_t *rec5,struct city_t *rec6,
					 struct city_t *rec7,struct city_t *rec8,struct city_t *rec9,struct city_t *rec10,struct city_t *rec11,struct city_t *rec12,
					 struct city_t *rec13,struct city_t *rec14,struct city_t *rec15,struct city_t *rec16,struct city_t *rec17,struct city_t *rec18,
					 struct city_t *rec19,struct city_t *rec20,struct city_t *record);
int user_input (struct city_t *modify,int count);
void write_data (struct city_t *rec1,struct city_t *rec2,struct city_t *rec3,struct city_t *rec4,struct city_t *rec5,struct city_t *rec6,
				 struct city_t *rec7,struct city_t *rec8,struct city_t *rec9,struct city_t *rec10,struct city_t *rec11,struct city_t *rec12,
				 struct city_t *rec13,struct city_t *rec14,struct city_t *rec15,struct city_t *rec16,struct city_t *rec17,struct city_t *rec18,
				 struct city_t *rec19,struct city_t *rec20,struct city_t *modify,struct city_t *record,int num,int length);


int main(void) 
{
	int b,c;
	struct city_t r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15,r16,r17,r18,r19,r20,a,d;
	
	/* function call to read_print_data */
	c = read_print_data (&r1,&r2,&r3,&r4,&r5,&r6,&r7,&r8,&r9,&r10,&r11,&r12,&r13,&r14,&r15,&r16,&r17,&r18,&r19,&r20,&d);
	
	/* function call to user_input */
	b = user_input (&a,c);

	/* function call to write_data */
	write_data (&r1,&r2,&r3,&r4,&r5,&r6,&r7,&r8,&r9,&r10,&r11,&r12,&r13,&r14,&r15,&r16,&r17,&r18,&r19,&r20,&a,&d,b,c);

	return 0;
}	

/* reads binary data from file without using fseek (but I could easily have used it) */
int read_print_data (struct city_t *rec1,struct city_t *rec2,struct city_t *rec3,struct city_t *rec4,struct city_t *rec5,struct city_t *rec6,
			   	 	 struct city_t *rec7,struct city_t *rec8,struct city_t *rec9,struct city_t *rec10,struct city_t *rec11,struct city_t *rec12,
					 struct city_t *rec13,struct city_t *rec14,struct city_t *rec15,struct city_t *rec16,struct city_t *rec17,struct city_t *rec18,
					 struct city_t *rec19,struct city_t *rec20,struct city_t *record)
{
	int i = 0;
	
	FILE *outfile;		/* open binary file for reading and writing */
	if ((outfile = fopen ("cityinfo.dat", "rb+")) == NULL)
		{
			printf ("Binary file cityinfo.dat cannot be opened.\n");
			exit (1);
		}
	printf ("rec: Name\t\tState\tPopulation(1000s)\tRevenue(millions)\n");
	printf ("---- ----\t\t-----\t-----------------\t-----------------\n");
	while (fread (record,  sizeof (struct city_t), 1, outfile) != 0)	/* each time through loop, record gets written over with new data */
		{																/* variable record is only used for printing, not writing or reading */
			printf ("   %d %-18s\t%c%c%c\t%17.2lf\t\t  %7d\n",i+1,record->name,record->state[0],record->state[1],record->state[2],
					record->revenue,record->population);
			i++;
		}
	rewind (outfile);
	
	/* this method allows for modification of any single record within the file while still keeping other records in memory */
	while (1)		/* storing every record in memory up to 20 records and break when end of records is reached */
		{
			if (fread (rec1,  sizeof (struct city_t), 1, outfile) == 0) break;
			if (fread (rec2,  sizeof (struct city_t), 1, outfile) == 0) break;
			if (fread (rec3,  sizeof (struct city_t), 1, outfile) == 0) break;
			if (fread (rec4,  sizeof (struct city_t), 1, outfile) == 0) break;
			if (fread (rec5,  sizeof (struct city_t), 1, outfile) == 0) break;
			if (fread (rec6,  sizeof (struct city_t), 1, outfile) == 0) break;
			if (fread (rec7,  sizeof (struct city_t), 1, outfile) == 0) break;
			if (fread (rec8,  sizeof (struct city_t), 1, outfile) == 0) break;
			if (fread (rec9,  sizeof (struct city_t), 1, outfile) == 0) break;
			if (fread (rec10, sizeof (struct city_t), 1, outfile) == 0) break;
			if (fread (rec11, sizeof (struct city_t), 1, outfile) == 0) break;
			if (fread (rec12, sizeof (struct city_t), 1, outfile) == 0) break;
			if (fread (rec13, sizeof (struct city_t), 1, outfile) == 0) break;
			if (fread (rec14, sizeof (struct city_t), 1, outfile) == 0) break;
			if (fread (rec15, sizeof (struct city_t), 1, outfile) == 0) break;
			if (fread (rec16, sizeof (struct city_t), 1, outfile) == 0) break;
			if (fread (rec17, sizeof (struct city_t), 1, outfile) == 0) break;
			if (fread (rec18, sizeof (struct city_t), 1, outfile) == 0) break;
			if (fread (rec19, sizeof (struct city_t), 1, outfile) == 0) break;
			if (fread (rec20, sizeof (struct city_t), 1, outfile) == 0) break;
			else break;
		}
	fclose (outfile);
	
	return i;		/* returns the count, i, of number of records */
}

/* Gets user input */
int user_input (struct city_t *modify,int count)	
{
	int cities;
	char aa[25] = "New city name: ";
	char bb[25] = "Two letter state code: ";
	char cc[25] = "Revenue (in million $): ";
	char dd[25] = "Population (in 1000's): ";

	printf ("\nFile contains %d records\n",count);
	printf ("\nWhich record do you want to edit (1 - %d): ",count);
//	scanf ("%d",&cities);
	cities=1;
	printf ("\n%s",aa);
//	getchar ();				/* getchar() must be used here to capture the extra '\n' */
//	gets (modify->name);
//	modify->name=PDX2;
	printf ("%s",bb);
//	scanf ("%c%c",&modify->state[0],&modify->state[1]);	/* the structure pointer operator must be used to acces structure members in function */
	modify->state[0] = 'O';
	modify->state[1] = 'R';
	modify->state[2] = ' ';	/* stores a space character in the last array member for state */
	printf ("%s",cc);
//	scanf ("%lf",&modify->revenue);
	modify->revenue = 100000;
	printf ("%s",dd);
//	scanf ("%d",&modify->population);
	modify->population = 10000;
	putchar ('\n');

	return cities;			/* return cities will return the record number to be modified so it can be passed to another function */
}

/* writes binary file with new user input data and prints out final data */
void write_data (struct city_t *rec1,struct city_t *rec2,struct city_t *rec3,struct city_t *rec4,struct city_t *rec5,struct city_t *rec6,
				 struct city_t *rec7,struct city_t *rec8,struct city_t *rec9,struct city_t *rec10,struct city_t *rec11,struct city_t *rec12,
				 struct city_t *rec13,struct city_t *rec14,struct city_t *rec15,struct city_t *rec16,struct city_t *rec17,struct city_t *rec18,
				 struct city_t *rec19,struct city_t *rec20,struct city_t *modify,struct city_t *record,int num,int length)
{
	int i = 0;
	
	FILE *outfile;	/* opens binary file for writing and reading */
	if ((outfile = fopen ("cityinfo.dat", "rb+")) == NULL)
		{
			printf ("Binary file cityinfo.dat cannot be opened.\n");
			exit (1);
		}


/* This section performs the same function that the fseek() function would...except it now writes the new binary file without writing over *
 * data stored in memory. Except for the modified structure data, the others will be unchanged (rec1,rec2...).							   *
 */
	if (length >= 1)			/* if the number of cities in the file is greater than or equal to 1, then do this */
		{
			if (num == 1)		/* if the user has chosen to modify the first record, then do this */
				fwrite (modify, sizeof (struct city_t), 1, outfile); /* write the user modified data to the file */
			else if (num != 1)										 /* if the user has not selected record 1, then do this */
				fwrite (rec1, sizeof (struct city_t), 1, outfile);	 /* write the already stored in memory data from rec1 to file */
		}															 /* even if the record has not changed */
	if (length >= 2)
		{
			if (num == 2)
				fwrite (modify, sizeof (struct city_t), 1, outfile);
			else if (num != 2)
				fwrite (rec2, sizeof (struct city_t), 1, outfile);
		}
	if (length >= 3)
		{
			if (num == 3)
				fwrite (modify, sizeof (struct city_t), 1, outfile);
			else if (num != 3)
				fwrite (rec3, sizeof (struct city_t), 1, outfile);
		}
	if (length >= 4)
		{
			if (num == 4)
				fwrite (modify, sizeof (struct city_t), 1, outfile);
			else if (num != 4)
				fwrite (rec4, sizeof (struct city_t), 1, outfile);
		}
	if (length >= 5)
		{
			if (num == 5)
				fwrite (modify, sizeof (struct city_t), 1, outfile);
			else if (num != 5)
				fwrite (rec5, sizeof (struct city_t), 1, outfile);
		}
	if (length >= 6)
		{
			if (num == 6)
				fwrite (modify, sizeof (struct city_t), 1, outfile);
			else if (num != 6)
				fwrite (rec6, sizeof (struct city_t), 1, outfile);
		}
	if (length >= 7)
		{
			if (num == 7)
				fwrite (modify, sizeof (struct city_t), 1, outfile);
			else if (num != 7)
				fwrite (rec7, sizeof (struct city_t), 1, outfile);
		}
	if (length >= 8)
		{
			if (num == 8)
				fwrite (modify, sizeof (struct city_t), 1, outfile);
			else if (num != 8)
				fwrite (rec8, sizeof (struct city_t), 1, outfile);
		}
	if (length >= 9)
		{
			if (num == 9)
				fwrite (modify, sizeof (struct city_t), 1, outfile);
			else if (num != 9)
				fwrite (rec9, sizeof (struct city_t), 1, outfile);
		}
	if (length >= 10)
		{
			if (num == 10)
				fwrite (modify, sizeof (struct city_t), 1, outfile);
			else if (num != 10)
				fwrite (rec10, sizeof (struct city_t), 1, outfile);
		}
	if (length >= 11)
		{
			if (num == 11)
				fwrite (modify, sizeof (struct city_t), 1, outfile);
			else if (num != 11)
				fwrite (rec11, sizeof (struct city_t), 1, outfile);
		}
	if (length >= 12)
		{
			if (num == 12)
				fwrite (modify, sizeof (struct city_t), 1, outfile);
			else if (num != 12)
				fwrite (rec12, sizeof (struct city_t), 1, outfile);
		}
	if (length >= 13)
		{
			if (num == 13)
				fwrite (modify, sizeof (struct city_t), 1, outfile);
			else if (num != 13)
				fwrite (rec13, sizeof (struct city_t), 1, outfile);
		}
	if (length >= 14)
		{
			if (num == 14)
				fwrite (modify, sizeof (struct city_t), 1, outfile);
			else if (num != 14)
				fwrite (rec14, sizeof (struct city_t), 1, outfile);
		}
	if (length >= 15)
		{
			if (num == 15)
				fwrite (modify, sizeof (struct city_t), 1, outfile);
			else if (num != 15)
				fwrite (rec15, sizeof (struct city_t), 1, outfile);
		}
	if (length >= 16)
		{
			if (num == 16)
				fwrite (modify, sizeof (struct city_t), 1, outfile);
			else if (num != 16)
				fwrite (rec16, sizeof (struct city_t), 1, outfile);
		}
	if (length >= 17)
		{
			if (num == 17)
				fwrite (modify, sizeof (struct city_t), 1, outfile);
			else if (num != 17)
				fwrite (rec17, sizeof (struct city_t), 1, outfile);
		}
	if (length >= 18)
		{
			if (num == 18)
				fwrite (modify, sizeof (struct city_t), 1, outfile);
			else if (num != 18)
				fwrite (rec18, sizeof (struct city_t), 1, outfile);
		}
	if (length >= 19)
		{
			if (num == 19)
				fwrite (modify, sizeof (struct city_t), 1, outfile);
			else if (num != 19)
				fwrite (rec19, sizeof (struct city_t), 1, outfile);
		}
	if (length >= 20)
		{
			if (num == 20)
				fwrite (modify, sizeof (struct city_t), 1, outfile);
			else if (num != 20)
				fwrite (rec20, sizeof (struct city_t), 1, outfile);
		}

	fclose (outfile);

	if ((outfile = fopen ("cityinfo.dat", "rb+")) == NULL)
		{
			printf ("Binary file cityinfo.dat cannot be opened.\n");
			exit (1);
		}
//	_clrscr ();		/* clear the io screen */
//	_gotoxy (0,0);	/* move cursur to top left position */
	
	printf ("rec: Name\t\tState\tPopulation(1000s)\tRevenue(millions)\n");
	printf ("---- ----\t\t-----\t-----------------\t-----------------\n");

	while (fread (record,  sizeof (struct city_t), 1, outfile) != 0) /* print out modified data to io screen */
		{
			printf ("   %d %-18s\t%c%c%c\t%17.2lf\t\t  %7d\n",i+1,record->name,record->state[0],record->state[1],record->state[2],
					record->revenue,record->population);
			i++;
		}
	printf ("\nFile contains %d records",length);
		
	fclose (outfile);
}
