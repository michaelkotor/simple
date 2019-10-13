#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** create(int n, int m);
void print(int** matrix, int n, int m);
void custom_sort(int** matrix, int n, int m);
void another_sort(int** matrix, int n, int m);
int* createSingle(int n, int m);
void printSingle(int* matrix, int n, int m);

int main(void) {
	srand(time(NULL));
	int n = 4, m = 5;
	int* matrix = createSingle(n, m);
	printSingle(matrix, n ,m);

	/*
	while(true) {
		printf("Enter n:\n");
		scanf("%d", &n);
		printf("Enter m:\n");
		scanf("%d", &m);
		int** matrix = create(n, m);
		print(matrix, n, m);
		custom_sort(matrix, n, m);
		print(matrix, n, m);
		printf("Enter 0 if you want to terminate:\n");
		int temp;
		scanf("%d", &temp);
		if(temp == 0) {
			return 0;
		}
	}
	*/
	return 0;
}

int** create(int n, int m) 
{
	int** matrix = (int**) malloc(n * sizeof(int*));
	if(matrix == NULL) {
		printf("no extra memory");
		return NULL;
	}
	for (int i = 0; i < n; ++i)
	{
		*(matrix + i) =  (int*) malloc(m * sizeof(int));
		if(*(matrix + i) == NULL) {
			printf("no extra memory");
			return NULL;
		}
		for(int j = 0; j < m; j++) {
			*(*(matrix + i) + j) = rand() % 100;
		}
	}
	return matrix;
}

void print(int** matrix, int n, int m) 
{
	for(int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%3d", *(*(matrix + i) + j));
		}
		printf("\n");
	}
	printf("%s\n", "------------");	
}

void custom_sort(int** matrix, int n, int m) 
{
	for (int i = 0; i < n; ++i)
	{
		if(i % 2 == 0) {
			for(int j = 0; j < m; j++)
			 {
				for (int k = j; k < m - 1; k++)
				{
					if(matrix[i][k] > matrix[i][k + 1]) {
						int temp = matrix[i][k];
						matrix[i][k] = matrix[i][k + 1];
						matrix[i][k + 1] = temp;
					}
				}
			}
		}
		else 
		{
			for(int j = 0; j < m; j++)
			 {
				for (int k = j; k < m - 1; k++)
				{
					if(matrix[i][k] < matrix[i][k + 1]) {
						int temp = matrix[i][k];
						matrix[i][k] = matrix[i][k + 1];
						matrix[i][k + 1] = temp;
					}
				}
			}
		}
	}
}

int* createSingle(int n, int m) 
{
	int* matrix = (int*) malloc(n * m * sizeof(int));
	for(int i = 0; i < n * m; i += m) 
	{
		for (int j = 0; j < m; ++j)
		{
			*(matrix + i + j) = rand() % 100;
		}
	}
	return matrix;
}

void printSingle(int* matrix, int n, int m) 
{
	for(int i = 0; i < n * m; i += m) 
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%3d", *(matrix + i + j));
		}
		printf("\n");
	}
}