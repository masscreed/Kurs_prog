#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>

int main(int argc, char *argv[])
{
	if (argc != 3){
		printf("Not enough arguments\n");
		return 2;
	}
	int num = test_atoi(argv[2]);
		
	if (num < 1){
		printf("Incorrect value\n");
		return 1;
	}
	if (!((equal_string (argv[1], "merge")) || 
	(equal_string (argv[1], "merge")))){
		printf("\nIncorrect arg 1\n");
		return -1;
	}
	int *array = malloc( sizeof(int) * num);
	
	srand(time(NULL));
	float start_time, end_time;
	int i;
	
	printf("Array:\n");
	for ( i = 0; i < num; ++i ){
		array[i] = rand() % 1000;
		printf("%d ", array[i]);
	}
	if ((equal_string (argv[1], "shell")) == 1){
		start_time = clock();
		shellsort(num, array);
		end_time = clock();
		
		printf("\nShell Sort :\n");
		for ( i = 0; i < num; i++ ){
			printf("%d ", array[i]);
		}
		printf("\n");
		printf("%.12f seconds\n", (end_time - start_time) / (CLOCKS_PER_SEC));
	}

	if ((equal_string (argv[1], "merge")) == 1){
		start_time = clock();
		mergesort(num, array);
		end_time = clock();
		
		printf("\nMerge Sort :\n");
		for ( i = 0; i < num; i++ ){
			printf("%d ", array[i]);
		}
		printf("\n");
		printf("%.12f seconds\n", (end_time - start_time) / (CLOCKS_PER_SEC));
	}

	free(array);
	array = NULL;
	return 0;
}