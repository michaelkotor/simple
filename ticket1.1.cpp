#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** create(int size);
void print(int ** matrix, int size);
void transprot_not_by_main(int** matrix, int size);
void transprot_not_by_main_by_do_while(int** matrix, int size);

int main() {
	srand(time(NULL));
	int size = 5;


	int** my_matrix = create(size);
	print(my_matrix, size);
	transprot_not_by_main(my_matrix, size);
	print(my_matrix, size);
	transprot_not_by_main_by_do_while(my_matrix, size);
	print(my_matrix, size);


	return 0;
}

int** create(int size) {
	int** matrix = (int**) malloc(sizeof(int*) * size);
	if(matrix == NULL) {
		return 0;
	}
	int count = 0;
	for(int i = 0; i < size; i++) {
		*(matrix + i) = (int*) malloc(sizeof(int) * size);
		for(int j = 0; j < size; j++) {
			*(*(matrix + i) + j) = count++;
		} 
	}
	return matrix;
}

void print(int** matrix, int size) {
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			printf("%3d", *(*(matrix + i) + j));
		}
		printf("\n");
	}
	for(int i = 0; i < size; i++) {
		printf("%s", "---");
	}
	printf("\n");
}

void transprot_not_by_main(int** matrix, int size) {
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if(i + j < size) {
				int temp = *(*(matrix + i) + j);
				*(*(matrix + i) + j) = *(*(matrix + size - i - 1) + size - j - 1);
				*(*(matrix + size - i - 1) + size - j - 1) = temp;
			}
		}		
	}
}

void transprot_not_by_main_by_do_while(int** matrix, int size) {
	int i = 0;
	int j = 0;
	do {
		do {
			if(i + j < size) {
				int temp = *(*(matrix + i) + j);
				*(*(matrix + i) + j) = *(*(matrix + size - i - 1) + size - j - 1);
				*(*(matrix + size - i - 1) + size - j - 1) = temp;
			}
			j++;
		} while(j < size - 1);
		i++;
	} while(i < size - 1);
}