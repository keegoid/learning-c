/* 
 * Name:        	Keegan Mullaney
 * Date:        	04/12/2003
 * Description: 	a program to calculate the daily,weekly,monthly, and yearly net pay (after taxes of 15%).
 */

#include <stdio.h>
#define HOURLY_WAGE 9.5		/* #define is used to set constants usually capitalized and no ; */ 
#define WORK_WEEK 32		

int main(void) 
{
	float daily_pay,weekly_pay,monthly_pay,yearly_pay,daily_net_pay,	
	weekly_net_pay,monthly_net_pay,yearly_net_pay;  /* float variable are stored as 4 bits with 6 or 7 digits of precision */
	weekly_pay		= HOURLY_WAGE * WORK_WEEK;       /* work hours in a week is 32 */
	daily_pay		= weekly_pay / 4.0;              /* use decimal points when working with float type variables */
	                                                /* work hours in a day is 8 */
	yearly_pay		= weekly_pay * 52.0;             /* work weeks in a year is 52 */
	monthly_pay		= yearly_pay / 12.0;             /* work hours in a month is 1/12 work hours in a year */
	daily_net_pay	= daily_pay * 0.85;              /* taxes are a flat 15% of total gross pay */
	weekly_net_pay	= weekly_pay * 0.85;
	monthly_net_pay	= monthly_pay * 0.85;
	yearly_net_pay	= yearly_pay * 0.85;
	
	printf("As a temp earning $9.50/hour, I will take home:\n\n"
		   "in one day,   $%.2f,\nin one week,  $%.2f,\n"        /* %_._f means to format a float variable with a */
		   "in one month, $%.2f, and\nin one year,  $%.2f\n\n"   /* certain width and number of digits after decimal */
		   "after taxes.",daily_net_pay,weekly_net_pay,monthly_net_pay,yearly_net_pay);
	
	return 0;
}
