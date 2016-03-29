/* 
 * Name:        	Keegan Mullaney
 * Date:
 * Description:   practice with time
 */
 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int ranTime, reactTime;
	
	ranTime = clock() + 1000 + rand() % 10000;
 	while(clock() < ranTime) /* wait 1 to 11 sec */
		;
	reactTime = clock();	/* start measuring time */
	printf("*");
	if(argc < 2)
		getchar();	/* wait for ENTER to be pressed */
	reactTime = clock() - reactTime; /* calculate the reaction time */
	printf("Your reaction time was %d msec", reactTime);
	
	return 0;
}
