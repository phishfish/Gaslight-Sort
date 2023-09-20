#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//11 + 1
#define BUFFER_LENGTH 12

//gets numbers from the user
//if the user enters something that is not a 0-9 it simply skips it
//all the numbers inputted concatonate together
//if the number is larger than INT_MAX it reprompts as well as if no numbers are inputted
int getUserNumbers(const char* message){
	//static buffer because if this was dynamic someone would enter 3825828582888670487306376637060376730686303603726
	//and I don't wanna spend the time dealing with their lunacy
	char buffer [BUFFER_LENGTH] = "";
	int data = '\0';
	int count = 0;
	long number = 0;
	int validInput = 0;
	while(!validInput){
		printf("%s", message);
		//take input
		while((data = getchar()) != '\n' && data != EOF && count < BUFFER_LENGTH - 1){
			if(data >= '0' && data <= '9')
				buffer[count++] = data;
			else if(data == '-' && buffer[0] == '\0')
				buffer[count++] = '-';
		}

		buffer[count] = '\0';

		//clears buffer
		if(data != '\n')
			while((data = getchar()) != '\n' && data != EOF);

		//validation
		if(strlen(buffer) == 0){
			puts("Enter an actual number bozo");
		}else{
			char* end = NULL;
			number = strtol(buffer, &end, 10);
			if(*end == '\0'){
				if(number > INT_MAX)
					puts("Number too big bozo");
				else if(number < INT_MIN)
					puts("Number too small bozo");
				else
					validInput = 1;
			}
		}

		if(validInput == 0){
			count = 0;
			number = 0;
			memset(buffer, '\0', BUFFER_LENGTH);
		}
	}//end while

	//truncates to the size of int
	return number;
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

bool isSorted(int *array)
{
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
	return 0;
}
