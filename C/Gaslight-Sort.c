#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include "Gaslight-Sort.h"

//11 + 1
#define BUFFER_LENGTH 12
//gets numbers from the user
//if the user enters anything that isn't a sane number it reprompts input
//if the number is larger than INT_MAX/INT_MIN it reprompts as well as if no numbers are inputted
int getUserNumbers(const char* message){
	//static buffer because if this was dynamic someone would enter 3825828582888670487306376637060376730686303603726
	//and I don't wanna spend the time dealing with their lunacy
	char input [BUFFER_LENGTH];
	int valid = 0;
	long convertedNumber = 0;
	while(!valid){
		printf("%s", message);
		fgets(input, BUFFER_LENGTH, stdin);
		char* newLineSpot = NULL;
		//searches in reverse just to be a little faster
		if((newLineSpot = strrchr(input, '\n')) == NULL){
			int data = '\0';
			while((data = getchar()) != '\n' && data != EOF);
		}else{
			//this way length will return 0
			*newLineSpot = '\0';
		}

		if(strlen(input) == 0){
			puts("Can't be nothing bozo");
			valid = 0;
		}else{
			char* end = NULL;
			convertedNumber = strtol(input, &end, 10);
			if(*end == '\0'){
				if(convertedNumber > INT_MAX)
					puts("Number too big bozo");
				else if(convertedNumber < INT_MIN)
					puts("Number too small bozo");
				else
					valid = 1;
			}else{
				puts("Enter an actual number bozo");
			}
		}

		if(valid == 0){
			memset(input, '\0', BUFFER_LENGTH);
			convertedNumber = 0;
			valid = 0;
		}
	}

	//truncates to the size of int
	return convertedNumber;
}

//method that prompts the user to enter numbers into what they foolishly allocated
void insertNumbers(int* arrayOfNums, int totalInputs){
	int a = 0;
	int howManyMore = totalInputs;
	for(; a < totalInputs; ++a){
		printf("Enter a number for index %d (%d positions left)\n", a, howManyMore--);
		arrayOfNums[a] = getUserNumbers("Enter the number for the index\n-> ");
		printf("\n");
	}
}

bool isSorted(int *array){
	return true;
}

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
		puts("Still sorted he he");

	free(needsToBeSorted);
	return 0;
}
