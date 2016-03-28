/* 
 * Name:        	Keegan Mullaney
 * Date:        	04/15/2003
 * Description: 	Program reads from a text file and uses math.h library and pow() funtion to calculate future values 
 *					   given present value, interest rate, inflation rate, and number of years. The result is then
 *					   printed out to the console.
 */

#include <stdio.h>
#include <math.h>	/* for the pow function to work the math.h library must be included */
/* in linux, link to the math library with: gcc main.c -lm */
/* can also specify an output filename with: gcc -o file-input-with-math main.c -lm */

int main(void)
{
	float years1,years2,years3,years4;
	
	double present_value1,present_value2,present_value3,present_value4,interest_rate1,interest_rate2,interest_rate3,
	interest_rate4,inflation_rate1,inflation_rate2,inflation_rate3,inflation_rate4,future_value1,future_value2,
	future_value3,future_value4,future_value5,future_value6,future_value7,future_value8;

	FILE *inptr;                                 /* pointer takes program to fopen function */
	
	inptr = fopen ("data.txt","r");              /* fopen() opens data file for program to scan */
	if (inptr == NULL)                           /* if fopen doesn't work, this if statement will help to notify us of problem */
	{
		printf("Error opening data file.\n");
		return 1;                                 /* return 1 will exit program */
	}
	fscanf(inptr,"%lf %lf %f %lf %lf %f %lf %lf %f %lf %lf %f",
		&present_value1,&interest_rate1,&years1,
		&present_value2,&interest_rate2,&years2,
		&present_value3,&interest_rate3,&years3,
		&present_value4,&interest_rate4,&years4); /* fscanf() scans file for data */
	fclose(inptr);                               /* fclose() closes data file */
	
	inflation_rate1 = interest_rate1;
	inflation_rate2 = interest_rate2;
	inflation_rate3 = interest_rate3;
	inflation_rate4 = interest_rate4;
	
	future_value1 = present_value1 * pow((1 + interest_rate1/100.),years1);       /* Compound Interest Equation */
	future_value2 = present_value1 * pow((1 + inflation_rate1/100.),-1*years1);   /* Inflation Equation */
	future_value3 = present_value2 * pow((1 + interest_rate2/100.),years2);       /* all rates converted from % to decimal */
	future_value4 = present_value2 * pow((1 + inflation_rate2/100.),-1*years2);
	future_value5 = present_value3 * pow((1 + interest_rate3/100.),years3);
	future_value6 = present_value3 * pow((1 + inflation_rate3/100.),-1*years3);
	future_value7 = present_value4 * pow((1 + interest_rate4/100.),years4);
	future_value8 = present_value4 * pow((1 + inflation_rate4/100.),-1*years4);

	printf("Value of money with and without investment.\n\n");
	printf("$%.2lf at %.1lf%% interest  for %.0f years yields $ %.2lf\n",
		present_value1,interest_rate1,years1,future_value1);
	printf("$%.2lf at %.1lf%% inflation for %.0f years yields $ %.2lf\n\n",
		present_value1,inflation_rate1,years1,future_value2);
	printf("$%.2lf at %.1lf%% interest  for %.0f years yields $ %.2lf\n",
		present_value2,interest_rate2,years2,future_value3);
	printf("$%.2lf at %.1lf%% inflation for %.0f years yields $ %.2lf\n\n",
		present_value2,inflation_rate2,years2,future_value4);
	printf("$%.2lf at %.1lf%% interest  for %.0f years yields $ %.2lf\n",
		present_value3,interest_rate3,years3,future_value5);
	printf("$%.2lf at %.1lf%% inflation for %.0f years yields $ %.2lf\n\n",
		present_value3,inflation_rate3,years3,future_value6);
	printf("$%.2lf at %.1lf%% interest  for %.0f years yields $ %.2lf\n",
		present_value4,interest_rate4,years4,future_value7);
	printf("$%.2lf at %.1lf%% inflation for %.0f years yields $ %.2lf\n",
		present_value4,inflation_rate4,years4,future_value8);

	return 0;
}
