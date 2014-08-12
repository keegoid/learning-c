/* 
 * Name:        	Keegan Mullaney
 * Date:
 * Description:   practice with arrays and for loops
 */

#include <stdio.h>

/*#define  VAL   5

void func (int inArray[],int aSize);

int main(void) 
{ /* main start 
	int  myarray[] = { 4, 10, 3, 7, 2 };
	int  n;
	func(myarray, VAL);
	for ( n = 0;  n < 5;  n++ )
			printf( "%3d", myarray[n]);
	return 0;
} /* main end 


void func (int  inArray[],int aSize )
{
	int n;
	for ( n = 0; n < aSize; n++ )
	   if ( inArray[n] < VAL)
		inArray[n] = VAL;
	return;
}
*/
int main(void) {
	int a[] = {3,21,8,42,100,213,45,105,43};
	int k;
	for(k = 0; k < 9; k++) {
		if (a[k] % 2 == 0)
			printf(" %d", a[k]);
	}
	printf("\n");
	for(k = 0; k < 9; k++) {
		if (a[k] % 2 != 0)
			printf(" %d", a[k]);
	}
	printf("\n");
	return 0;
}
