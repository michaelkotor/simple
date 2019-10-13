#include<stdio.h>
int main()
{
  const int size = 3;

  int matrix[size][size];

  printf("Enter matrix:\n");
  for (int i = 0; i < size; i++) 
  {
    for (int j = 0; j < size; j++) 
    {
      printf("matrix[%d][%d]=", i, j);
      scanf("%d", &matrix[i][j]);
    }
  }
  printf("Your matrix:\n");
  for (int i = 0; i < size; i++) 
  {
    for (int j = 0; j < size; j++)
    {
      printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  int min;
  int array[size];
  for (int i = 0; i < size;i++)  
  {
    min = matrix[i][0];
    for (int j = 0; j < size; j++)
    {
      if(i >= j) {
        if(matrix[i][j] < min) {
          min = matrix[i][j];
        }
      }
    }
    array[i] = min;
  }
  printf("Your array:\n");
  for (int i = 0; i < size; i++) {
    printf("%4d\n", array[i]);
  }
  return 0;
}