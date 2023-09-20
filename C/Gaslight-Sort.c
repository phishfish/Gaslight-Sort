#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Gaslight-Sort.h"

int main(void)
{
	int numInts;
	int tempInt;

	printf("How many integers to be sorted?\n");
	scanf("%d", &numInts);

	int *intArray = malloc(numInts * sizeof(int));

	for (int i = 0; i < numInts; i++)
	{
		printf("Please enter an integer: ");
		scanf("%d", &tempInt);
		intArray[i] = tempInt;
	}

	while (isSorted(intArray))
	{
		printf("It is sorted\n");
	}
	
	return 0;
}
