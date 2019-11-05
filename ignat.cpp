#include <stdio.h>
#include <stdlib.h>

void get_comparison_value(int* pointer_to_comparison_value)
{
  printf("\nInput x\n");

  scanf("%d", pointer_to_comparison_value);
}

void get_initial_dimension(int* pointer_to_initial_dimension)
{
  printf("\nInput n (size of ur matrix is n*2n)\n");

  scanf("%d", pointer_to_initial_dimension);
}

int** init_matrix(int initial_dimension)
{
  int height = initial_dimension, width = 2 * initial_dimension;
  int** matrix = (int**) malloc(height * sizeof(int*));
  for(int i = 0; i < height; i++)
  {
    *(matrix + i) = (int*) malloc(width * sizeof(int));
  }
  return matrix;
}

void get_matrix(int** matrix, int initial_dimension)
{
  int height = initial_dimension, width = 2 * initial_dimension;

  printf("\nInput ur matrix\n");

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      printf("\nMt[%d][%d]=", i + 1, j + 1);
      scanf("%d", (*(matrix + i) + j));
    }
  }
}

void print_matrix(int** matrix, int initial_dimension)
{
  int height = initial_dimension, width = 2 * initial_dimension;

  printf("\nUr matrix:\n");

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      printf("%3d", *(*(matrix + i) + j));
    }
    printf("\n");
  }
}

int* init_array(int initial_dimension)
{
  int size = 2 * initial_dimension * initial_dimension;
  int* arr = (int*)malloc(size * sizeof(int));
  return arr;
}

void convert(int** mat, int* arr, 
  int initial_dimension, int comparison_value)
{
  int height = initial_dimension; 
  int width = 2 * initial_dimension;
  int size = 2 * initial_dimension * initial_dimension;
  int counter = 0;

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (*(*(mat + i) + j) > comparison_value)
      {
        arr[counter++] = 1;
      }
      else
      {
        arr[counter++] = 0;
      }
    }
  }
}

void print_array(int *arr, int initial_dimension)
{
  int size = 2 * initial_dimension * initial_dimension;

  printf("\nUr array\n");
  for (int i = 0; i < size; i++)
  {
    printf("%2d", arr[i]);
  }
}

int main()
{
  int** matrix;
  int* array;
  int comparison_value = 0, initial_dimension = 0;

  get_comparison_value(&comparison_value);
  get_initial_dimension(&initial_dimension);

  matrix = init_matrix(initial_dimension);

  get_matrix(matrix, initial_dimension);
  print_matrix(matrix, initial_dimension);

  array = init_array(initial_dimension);

  convert(matrix, array, initial_dimension, comparison_value);

  print_array(array, initial_dimension);
  
  free(mat);
  free(array);
  return 0;
}