#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void**** freeMatrix(void**** matrix, int length, int width);
void**** callocMatrix(int length, int width, int height,
	size_t item_sz, int* test_data);
void show(void**** matrix, int length, int width, int height, int* test_data);
int* create_test_data(int length, int width, int height) ;
void**** remake(void**** matrix, int length, int width, int height,
	int level, int new_size, int* test_data);
void**** create_new(void**** old_matrix,
	int new_length, int new_width, int new_height, int* test_data);


int main() 
{
	int length = 5, width = 6, height = 7;
	int* test_data = create_test_data(length, width, height);
	void**** m = callocMatrix(length, width, height, sizeof(int*), 
		test_data);
	printf("\n");
	show(m, length, width, height, test_data);
	//freeMatrix((void****)m, length, width);
	m = create_new(m, 1,2,3, test_data);
	printf("YES\n");
	show(m, 1, 2, 3, test_data);
	
	return 0;
}


void**** create_new(void**** old_matrix, int new_length, int new_width, int new_height, int* test_data)
{
	void**** new_matrix = (void****)malloc(new_length * sizeof(void***));
	int count = 0;
	for (int i = 0; i < new_length; ++i)
	{
		*(new_matrix + i) = (void***)malloc(new_width * sizeof(void**));
		for (int j = 0; j < new_width; ++j)
		{
			*(*(new_matrix + i) + j) = (void**)malloc(new_height * sizeof(void*));
			for(int k = 0; k < new_height; ++k)
			{
				*(*(*(new_matrix + i) + j) + k) = (test_data + count++);
			}
		}
	}
	return new_matrix;
}

void**** remake(void**** matrix, int length, int width, int height, int level,
 int new_size, int* test_data) 
{
	int count = 0;
	if(level == 0) 
	{
		length = new_size;
		realloc(matrix, length * sizeof(void***));
	}
	for(int i = 0 ; i < length; i++) 
	{
		if(level == 1)
		{
			width = new_size;
			realloc(matrix, width * sizeof(void**));
		}
		for(int j = 0 ; j < width; j++)
		{
			if(level == 2)
			{
				height = new_size;
				realloc(matrix, height * sizeof(void*));
			}
			for (int k = 0; i < height; k++)
			{
				//*(*(*(matrix + i) + j) + k) = (test_data + count++);
			}
		}
	}
	return matrix;
}

int* create_test_data(int length, int width, int height) 
{
	int count = 0;
	int* test_data = (int*) malloc(length * width * height * sizeof(int));
	for(int i = 0; i < length * width * height; i++) 
	{
		*(test_data + i) = count++;
	}
	return test_data;
}

void show(void**** matrix, int length, int width, int height, int* test_data) 
{
	int count = 0;
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < width; ++j)
		{	
			for(int k = 0; k < height; ++k)
			{
				printf("%4d", *(test_data + count++));
			}
			printf("\n");
		}
		printf("\n");
		printf("New Laywer!\n");
		printf("\n");
	}
}

void**** freeMatrix(void**** matrix, int length, int width)
{
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			free(*(*(matrix + i) + j));
		}
		free(*(matrix + i));
	}
	free(matrix);
	return NULL;
}

void**** callocMatrix(int length, int width, int height, size_t item_sz, int* test_data)
{
	printf("I am taking memory!\n");
	void**** matrix = (void****)malloc(length * sizeof(void***));
	int count = 0;
	if(matrix != NULL) {
		for (int i = 0; i < length; ++i) {
			printf("I am taking memory!!\n");
			*(matrix + i) = (void***)malloc(width * sizeof(void**));
			if(*(matrix + i) != NULL) {
				for (int j = 0; j < width; ++j) {
					printf("I am taking memory!!!\n");
					*(*(matrix + i) + j) = (void**)malloc(height * sizeof(void*));
					if(*(*(matrix + i) + j) != NULL) {
						for(int k = 0; k < height; k++){
							*(*(*(matrix + i) + j) + k) = (test_data + count++);
							continue;
						}
						if(j == width - 1 && i == length - 1) return matrix;
						continue;
					}
					printf("I want to delete!!!\n");
					return freeMatrix(matrix, length, j);
				}
				continue;
			}
			printf("I want to delete!!\n");
			return freeMatrix(matrix, i, 0);
		}
	}
	printf("I want to delete!\n");
	return freeMatrix(matrix, 0, 0);
}



