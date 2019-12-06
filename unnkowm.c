#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int main()
{
    setlocale(LC_ALL, "rus");
    int value = 0, b=0, tmp, pos, size;
    int a[4][4] = { -2, -3, 3, 6, -4, 3, 8, -6, -6, -5, -3, -6, 3, -2, 6, -5 };
    int summ[4];
    printf_s("исходная матрица:\n");
    for (int i = 0; i<4; i++)  // цикл по строкам
    {
        printf_s("|");
        for (int j = 0; j<4; j++) // цикл по столбцам
        {
            printf("%3d", a[i][j]);
        }
        printf_s("|");
        printf("\n"); // перевод на новую строку
 
    }
    printf_s("\n");
 
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if ((a[i][j]<0) && (a[i][j] % 2 == 0))
                sum += a[i][j]; //сумма четных элементов
        }
          //элементы массива sum соответствуют строкам исходного массива a
        summ[i] = sum;
    
 
    printf_s("измененная матрица:\n");
    for (int i = 0; i<4; i++)  // цикл по строкам
    {
        printf_s("|");
        for (int j = 0; j<4; j++) // цикл по столбцам
        {
            printf("%3d", a[i][j]);
        }
        printf_s("|");
        printf("\n"); // перевод на новую строку
 
    }
 
    getchar();
    return 0;
}