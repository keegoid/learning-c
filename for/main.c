/* 
 * Name:        	Keegan Mullaney
 * Date:
 * Description: 	practice with for loops
 */

#include <stdio.h>

int main(void) 
{
	float x;
	char p;
	int k,j;
	
	for (x = 2.5; x <= 3.3; x += 0.15) 
	
	printf("%0.1f  ", x);
	printf("\n\n");

	for (p = 'D'; p < 'H'; p++) 
	
	printf("%c  ", p);
	printf("\n\n");
	
	for (k = 1, j = 0; k <= 5; k++, j += k)
	
	printf("%d  ", j + k);
	printf("\n");
	
	return 0;
}
