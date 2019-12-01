#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#define N 32
void menu()
int vvod_mas(int **a)
void vivod_mas(int n, int m, int **a)
int 1zadanie(int n, int m, int **a)
int 2zadanie()

int main()
{
    setlocale(LC_ALL, "rus");
    int menu();

    getchar();
    return 0;
}




void menu()
{
    int a;
    do
    {
        printf("Выбери действие из списка\n1.Ввести новый массив (динамический)\n2.Проверить, все ли строки матрицы содержат хотя бы один отрицательный элемент. Если да, то изменить знаки всех элементов матрицы на обратные.\n3.Вывод массива\n4.Преобразовать строку, состоящую только из прописных букв, в строку, состоящий из прописных и строчных букв.\n5.Выход\n");
        scanf_s("%d", &a);
        switch (a)
        {
        case 1:vvod_mas(int n, int m, int **a);
            break;
        case 2:1zadanie(int n, int m, int **a);
            break;
        case 3:vivod_mas(int n, int m, int **a);
            break;
        case 4:2zadanie();
            break;
        case 5:exit(1);
            break;
        }

    } while (a>5 || a<1);

}
int vvod_mas(int n, int m, int **a)
{
    int **a;  // указатель на указатель на строку элементов
int i, j, n, m;
    printf("Введите количество строк: ");
scanf_s("%d", &n);
printf("Введите количество столбцов: ");
scanf_s("%d", &m);
// Выделение памяти под указатели на строки
a = (int**)malloc(n * sizeof(int*));
// Ввод элементов массива
for (i = 0; i<n; i++)  // цикл по строкам
{
    // Выделение памяти под хранение строк
    a[i] = (int*)malloc(m * sizeof(int));
    for (j = 0; j<m; j++)  // цикл по столбцам
    {
        printf("a[%d][%d] = ", i, j);
        scanf_s("%d", &a[i][j]);
    }
}
return(**a);
}

void vivod_mas(int n, int m, int **a)
{
int **a;  // указатель на указатель на строку элементов
int i, j, n, m;
// Вывод элементов массива

    for (i = 0; i < n; i++)  // цикл по строкам
    {
        for (j = 0; j < m; j++)  // цикл по столбцам
        {
            a[i][j] = -a[i][j];
            printf("%5d ", a[i][j]); // 5 знакомест под элемент массива
        }
        printf("\n");
    }
}

int 1zadanie(int n, int m, int **a)
{
    int b = 1;
    for (int i = 0; i < n && b; i++) {
        b = 0;
        for (int j = 0; j < m; j++)
            if (a[i][j] < 0) {
                b = 1;
                break;
            }
    }
    if (b == 1) {


            printf_s("можно выводить массив");
    }

    else printf_s("Не все строки матрицы содержат хотя бы один отрицательный элемент");
}

int 2zadanie()
{
    setlocale(LC_ALL, "rus");
    char s[32];
    printf("\nвведи строку\n");
    gets(s);
    for (int i = 0; s[i];)
    {
        if (s[i++] == '.')
        {
            while (s[i] == ' ') i++;
            s[i] = toupper(s[i]);
        }
    }
    printf("%s", s);


}
