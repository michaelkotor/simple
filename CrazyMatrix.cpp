#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int length, width, height;
int* test_data;

int**** createCrazy() 
{
	int**** matrix = (int****) malloc(length * sizeof(int***));
	int count = 0;
	for (int i = 0; i < length; ++i)
	{
		*(matrix + i) = (int***)malloc(width * sizeof(int**));
		for (int j = 0; j < width; ++j)
		{
			*(*(matrix + i) + j) = (int**)malloc(height * sizeof(int*));
			for(int k = 0; k < height; ++k)
			{
				
				*(*(*(matrix + i) + j) + k) = test_data + count++;
			}
		}
	}
	return matrix;
}

void init() 
{
	test_data = (int*) malloc(length * width * height * sizeof(int));
	for(int i = 0; i < length * width * height; i++) 
	{
		*(test_data + i) = rand() % 100;
	}
}

void show(int**** matrix) 
{
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < width; ++j)
		{		
			for(int k = 0; k < height; ++k)
			{
				
				printf("%3d", *(*(*(*(matrix + i) + j) + k)));
			}
			printf("\n");
		}
		printf("\n");
		printf("New Laywer!\n");
		printf("\n");
	}
	
}

int main() 
{
	srand(time(NULL));
	length = 5;
	width = 6;
	height = 7;
	init();
	int**** m = createCrazy();
	show(m);
	printf("Michael was here!\n");
	return 0;
}
