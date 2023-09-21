#include <stdio.h>
#include <stdlib.h>
#include "Gaslight-Sort.h"

//11 + 1
#define BUFFER_LENGTH 12

int main(void)
{
	int numInts;
	while((numInts = getUserNumbers("How many integers do you want\n-> ")) <= 0){
		puts("Number has to be greater than zero bozo");
	}
	printf("%d\n", numInts);

	int* needsToBeSorted = malloc(numInts * sizeof(int));
	insertNumbers(needsToBeSorted, numInts);

	for(int p = 0; p < numInts; ++p){
		printf("index %d is %d\n", p, needsToBeSorted[p]);
	}

	if(isSorted(needsToBeSorted))
		puts("This is sorted");
	else
		puts("This is not sorted");

	return 0;
}
