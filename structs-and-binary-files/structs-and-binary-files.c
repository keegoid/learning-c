/* 
  Name:        	Keegan Mullaney
  Date:        	06/02/2003
  Description: 	Takes a binary file, reads its data based on user input and returns it in a struct
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAYSIZE 20

typedef struct city_t				/* types */
	{
		char name[ARRAYSIZE];		/* city name */
		char state[3];				   /* state two-letter abbreviation */
		double revenue;				/* 2000 revenue from all sources in millions */
		int population;				/* 2000 population in thousands */
	}	city_t;

/* function prototypes */
int read_print_data (struct city_t *rec1,struct city_t *rec2,struct city_t *rec3,struct city_t *rec4,struct city_t *rec5,struct city_t *rec6,struct city_t *record);
int user_input (struct city_t *modify,int count);
void write_data (struct city_t *rec1,struct city_t *rec2,struct city_t *rec3,struct city_t *rec4,struct city_t *rec5,struct city_t *rec6,struct city_t *modify,struct city_t *record,int num,int length);


int main(int argc, char *argv[]) 
{
	int b,c;
	struct city_t r1,r2,r3,r4,r5,r6,a,d;
	
	/* function call to read_print_data */
	c = read_print_data (&r1,&r2,&r3,&r4,&r5,&r6,&d);
	
	if(argc < 2)
		b = user_input (&a,c); 	/* function call to user_input */

	/* function call to write_data */
	write_data (&r1,&r2,&r3,&r4,&r5,&r6,&a,&d,b,c);

	return 0;
}	

/* reads binary data from file without using fseek (but I could easily have used it) */
int read_print_data (struct city_t *rec1,struct city_t *rec2,struct city_t *rec3,struct city_t *rec4,struct city_t *rec5,struct city_t *rec6,struct city_t *record)
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
	scanf ("%d",&cities);
	printf ("\n%s",aa);
	getchar ();				/* getchar() must be used here to capture the extra '\n' */
	gets (modify->name);
	printf ("%s",bb);
	scanf ("%c%c",&modify->state[0],&modify->state[1]);	/* the structure pointer operator must be used to acces structure members in function */
	modify->state[2] = ' ';	/* stores a space character in the last array member for state */
	printf ("%s",cc);
	scanf ("%lf",&modify->revenue);
	printf ("%s",dd);
	scanf ("%d",&modify->population);
	putchar ('\n');

	return cities;			/* return cities will return the record number to be modified so it can be passed to another function */
}

/* writes binary file with new user input data and prints out final data */
void write_data (struct city_t *rec1,struct city_t *rec2,struct city_t *rec3,struct city_t *rec4,struct city_t *rec5,struct city_t *rec6,struct city_t *modify,struct city_t *record,int num,int length)
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
	printf ("\nFile contains %d records\n",length);
		
	fclose (outfile);
}
