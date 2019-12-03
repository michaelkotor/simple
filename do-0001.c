#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

#define N 32

void menu();
int** input_array(int* length, int* heigth);
void print_array(int length, int width, int** array);

void first_task(int n, int m, int **a);
void change_str();

static void print_swap_array(int length, int width, int** array);
static char* convert(char* str, int size); 

int main()
{
    setlocale(LC_ALL, "rus");
    menu();
    return 0;
}

 
void menu()
{
    int choise = 0;
    int** array = NULL;
    int length = -1;
    int width = -1;
    int one_more_time  = 0;
    do
    {
        printf("Выбери действие из списк.\n"
            "1.Ввести новый массив (динамический)\n"
            "2.Проверить, все ли строки матрицы содержат"
            " хотя бы один отрицательный элемент. Если да,"
            " то изменить знаки всех элементов матрицы на"
            " обратные.\n3.Вывод массива\n4.Преобразовать "
            "строку, состоящую только из прописных букв, в"
            " строку, состоящий из прописных и строчных букв.\n"
            "5.Выход\n");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            array = input_array(&length, &width);
            break;
        case 2:
            first_task(length, width, array);
            break;
        case 3:
            print_array(length, width, array);
            break;
        case 4:
            change_str();
            break;
        case 5:
            return;
            break;
        }

        printf("\nWould you like to countinue? YES - 1, NO - 0\n");
        scanf("%d", &one_more_time);
    } while (one_more_time > 0);
}
 

int** input_array(int* length_to_change, int* width_to_change)
{
    printf("Enter length\n");
    scanf("%d", length_to_change);

    printf("Enter width\n");
    scanf("%d", width_to_change);

    if( *length_to_change < 1 || *width_to_change < 1) 
    {
        printf("Size must be normal!\n");
        return NULL;
    }

    int length = *length_to_change;
    int width = *width_to_change;
    
    int** array = (int**) malloc(length * sizeof(int*));
    
    for (int i = 0; i < length; i++)  // цикл по строкам
    {
        *(array + i) = (int*) malloc(width * sizeof(int));
        for (int j = 0; j < width; j++)  // цикл по столбцам
        {
            scanf("%d", (*(array + i) + j));
        }
    }
    return array;
}

void print_array(int length, int width, int** array)
{
    if(array == NULL)
    {
        printf("You should first initialize your array!\n");
        return;
    }
    for (int i = 0; i < length; i++)  // цикл по строкам
    {
        for (int j = 0; j < width; j++)  // цикл по столбцам
        {
            printf("%5d", *(*(array + i) + j));
        }
        printf("!\n");
    }

    printf("\nI finished!!!\n");
}

 

void first_task(int length, int width, int** array)
{
    if(array == NULL)
    {
        printf("You need first initialize your array!");
        return;
    }
    int in_each_line = 0;
    for (int i = 0; i < length; i++) 
    {
        for (int j = 0; j < width; j++)
        {
            if (*(*(array + i) + j) < 0) {
                in_each_line++;
                break;
            }
        }
            
    }
    printf("%d\n", in_each_line);

    if(in_each_line == length) {
        printf("YES\n");
        print_swap_array(length, width, array);
    }
    else printf("Не все строки матрицы содержат хотя бы один отрицательный элемент");
}

static void print_swap_array(int length, int width, int** array)
{
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            printf("%5d", -*(*(array + i) + j));
        }
        printf("\n");
    }
}
 

void change_str()
{
    printf("Enter the maximum size of your string\n");
    int size;
    scanf("%d", &size);

    //clean buffer after scanf
    while ((getchar()) != '\n'); 

    char* str = (char*) calloc(size + 2, sizeof(char));

    printf("\nEnter the string\n");

    fgets(str, size + 1, stdin);

    //clean buffer after fgets
    while ((getchar()) != '\n'); 

    str = convert(str, size + 1);
    
    printf("%s", str);
}

static char* convert(char* str, int size)
{
    int was_dot = 0;
    for (int i = 0; i < size; ++i)
    {
        if(*(str + i) == '.')
        {
            was_dot = 1;
        } 
        else
        {
            if(was_dot == 1)
            {
                char temp = *(str + i);
                *(str + i) = toupper(temp);
                was_dot = 0;
            }
        }
    }
    return str;
}