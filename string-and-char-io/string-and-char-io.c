/* 
 * Name:        	Keegan Mullaney
 * Date:        	05/28/2003
 * Description: 	Outputs a text file that randomly generates a letter with user inputs for recipient and sender using strings.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define WIDTH 81

/* function prototypes */
void  getNames (char recipient[], char sender[]);
void  getWords (int wordCount[], char nouns[][WIDTH], char verbs[][WIDTH], char adjectives[][WIDTH]);
void  writeLetter(char sender[], char recipient[], int wordCount[], char nouns[][WIDTH], char verbs[][WIDTH], char adjectives[][WIDTH]);

int main(void) 
{
	/* initializing arrays and pointer variables */
	char recipient[20],sender[20],nouns[10][WIDTH],verbs[10][WIDTH],adjectives[10][WIDTH];
	int wordCount[3];
		
	getNames (recipient,sender);					      /* function calls using arrays */
	getWords (wordCount,nouns,verbs,adjectives);
	writeLetter (sender,recipient,wordCount,nouns,verbs,adjectives);
	
	return 0;
}

/* function definitions */
void  getNames (char recipient[], char sender[])	/* Gets the name of the recipient and sender. */
{
	char *aa = "Enter the recipient's name and press enter. ";
	char *bb = "Enter the sender's name and press enter. ";
	char *cc = "The letter is done. It is saved as letter.txt";
	
	printf ("This program will create a randomly generated letter.\n\n");
	printf ("%s",aa);
//	gets (recipient);
	recipient="Keegan";
	putchar ('\n');
	printf ("%s",bb);
//	gets (sender);
	sender="Adriana";
	putchar ('\n');
	putchar ('\n');
	puts (cc);
}

void  getWords (int wordCount[], char nouns[][WIDTH], char verbs[][WIDTH], char adjectives[][WIDTH])
/* Opens the words.txt file, reads the counts and words for each category and closes the file. */
{
	char n[20],v[20],a[20];
	int i,k;
	
	FILE *wordFile;
	wordFile = fopen ("words.txt","r");			      /* open file for reading */
	if (wordFile == NULL)
		{
			printf ("Error opening file words.txt");
			exit(0);
		}

	fgets (n,2,wordFile);							      /* wordCount[0] holds the number of nouns */
	wordCount[0] = atoi (n);						      /* atoi converts a string with numerical digits to an integer */
	
	for (i=0; i <= wordCount[0]; i++)
		{											            /* remove the '\n' in fgets and store nouns in nouns[i] array */
			fgets (nouns[i],WIDTH,wordFile);
			k = strlen(nouns[i]) - 1;
			nouns[i][k] = '\0';
		}
	
	fgets (v,2 + wordCount[0],wordFile);			   /* wordCount[1] holds the number of verbs */
	wordCount[1] = atoi (v);
	
	for (i=0; i < wordCount[1]; i++)
		{
			fgets (verbs[i],WIDTH,wordFile);
			k = strlen(verbs[i]) - 1;
			verbs[i][k] = '\0';
		}
	
	fgets (a,3 + wordCount[0] + wordCount[1],wordFile);	/* wordCount[2] holds the number of adjectives */
	wordCount[2] = atoi (a);
	
	for (i=0; i < wordCount[2]; i++)
		{
			fgets (adjectives[i],WIDTH,wordFile);
			k = strlen(adjectives[i]) - 1;
			if (i != wordCount[2] - 1)
				adjectives[i][k] = '\0';
		}	

	fclose (wordFile);
}

void  writeLetter(char sender[], char recipient[], int wordCount[], char nouns[][WIDTH], char verbs[][WIDTH], char adjectives[][WIDTH])
/* Opens template.txt for reading and letter.txt for writing. Copies each character from pgm7Template.txt to letter.txt, 
 * replacing special codes as follows:
 *     <r>  is replaced by the name of the recipient
 *     <s>  is replaced by the name of the sender
 *     <n>  is replaced by a noun (randomly selected)
 *     <v>  is replaced by a verb (randomly selected)
 *     <a>  is replaced by an adjective (randomly selected)
 * Closes all files.
 */
{
	char letter[WIDTH],a[25][WIDTH];
	int j,k,p;
	
	FILE *letterFile;
	FILE *outfile;

	letterFile = fopen ("template.txt","r");	      /* open file for reading */
	if (letterFile == NULL)
		{
			printf ("Error opening file template.txt\n");
			exit(0);
		}
	outfile = fopen ("letter.txt","w");				   /* open file for writing */

	j = 0;
	while (fgets (a[j],WIDTH,letterFile) != NULL) j++;
	fclose (letterFile);	
	
	letterFile = fopen ("template.txt","r");
	if (letterFile == NULL)
		{
			printf ("Error opening file template.txt\n");
			exit(0);
		}
	while (!feof (letterFile))
		{
			fgets (letter,WIDTH,letterFile);
			k = 0;
			while (letter[k] != '\0')
				{
					if (letter[k] == '<')
						{
							if (letter[k+1] == 'r') 
								fputs (recipient, outfile);

							if (letter[k+1] == 's') 
								fputs (sender, outfile);
							
							if (letter[k+1] == 'n')
								{
									p = rand() % wordCount[0];
									if (p == 0) p += 4;
									fputs (nouns[p], outfile);
								}
							if (letter[k+1] == 'v')
								{
									p = rand() % wordCount[1];
									if (p == 0) p += 2;
									fputs (verbs[p], outfile);
								}
							if (letter[k+1] == 'a')
								{
									p = rand() % wordCount[2];
									if (p == 0) p += 3;
									fputs (adjectives[p], outfile);
								}
							k += 3;
						}
					else	
						{
							fputc (letter[k], outfile);
							k++;
						}
				}
		}
	fclose (letterFile);
	fclose (outfile);
}
