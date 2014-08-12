/* 
 * Name:        	Keegan Mullaney
 * Date:        	04/26/2003
 * Description: 	Make a table on the console screen with incomes from  $20,000 through $80,000 as row labels 
 *					   and loans from $1000 through $9000 as column labels. Use repetition and conditional execution
 *					   to create the table for when to approve the loan (yes), ask the supervisor (ask), 
 *					   and don't approve the loan (no).
 */

#include <stdio.h>
#define RANGE1 30000		   /* Here we want to specify the upper limit of each income bracket */
#define RANGE2 50000
#define RANGE3 90000
#define LOAN1LOW 2000		/* The loan amount ranges will assist us in comparing with the different incomes */
#define LOAN1HIGH 4000
#define LOAN2LOW 3000		/* These loan ranges are the rules for determining when to approve the loan */
#define LOAN2HIGH 5000
#define LOAN3LOW 5000
#define LOAN3HIGH 8000

int main (void) 
{
	int loan_amount, income;
	
	printf ("Loan Approval Table For Junior Loan Officer\n\n");
	printf ("yes = you can approve\nask = check with supervisor\nno  = no approval\n\n");
	printf ("\t\t\t Loan Amount\n");
	printf ("income  ");
	
	for (loan_amount = 1000; loan_amount <= 9000; loan_amount += 1000)
		printf("$%4d ",loan_amount);	   /* The for loop will generate a row of loan amounts for the heading */

	for (income = 20000; income <= 80000; income += 10000)
	{	printf("\n$%6d   ",income);		/* The income loop must be the outer loop to compare with 
										          * loan amounts line by line */
	
		for (loan_amount = 1000; loan_amount <= 9000; loan_amount += 1000)
		{								         /* Now we can loop the loan amounts and compare to incomes */
			if (income >= 0 && income < RANGE1)
			{							         /* This is for incomes in range 1 */
				if (loan_amount < LOAN1LOW)
					printf ("%-6s","yes");
				else 
				if (loan_amount >= LOAN1LOW && loan_amount < LOAN1HIGH)
					printf ("%-6s","ask");
				else 
					printf ("%-6s","no");
			}

			if (income >= RANGE1 && income < RANGE2)
			{							         /* This is for incomes in range 2 */
				if (loan_amount < LOAN2LOW)
					printf ("%-6s","yes");
				else
				if (loan_amount >= LOAN2LOW && loan_amount < LOAN2HIGH)
					printf ("%-6s","ask");
				else
					printf ("%-6s","no");
			}

			if (income >= RANGE2 && income < RANGE3)
			{							         /* This is for incomes in range 3 */
				if (loan_amount < LOAN3LOW)
					printf ("%-6s","yes");
				else
				if (loan_amount >= LOAN3LOW && loan_amount < LOAN3HIGH)
					printf ("%-6s","ask");
				else
					printf ("%-6s","no");
			}
		}
	}
		
	return 0;
}
