#include <stdio.h>
#include <stdlib.h>

void put_char(char* string, int size, char to_save);

void clean(char* string_work_with, int start, int size);

bool is_number(char to_check);

int main()
{
	int n = 50;
	char* string = (char*) malloc(n * sizeof(int));
	char temp;
	for(int i = 0; i < n; i++)
	{
		temp = getchar();
		if(temp == 10)
		{
			n = i;
			break;
		}
		put_char(string, i, temp);
		
	}
	clean(string, 0, n);
	//printf("%s\n", string);
	
	return 0;
}

void put_char(char* string, int size, char to_save)
{
	*(string + size * sizeof(char)) = to_save;
}

void clean(char* string, int start, int size) 
{
	//char* new_string = (char*) malloc(size * sizeof(char));
	//printf("RESULT\n");
	for(char i = start; i < size; i++)
	{
		if(string[i] == '.' && i < size - 2) 
		{
			char first = string[i + 1];
			if(is_number(first)) 
			{
				printf("%c", first);
			}
			char second = string[i + 2];
			if(is_number(second)) 
			{
				printf("%c", second);
			}
			if(is_number(first) && is_number(second))
			{
				char where_to_start = string[i + 3];
				i = i + 3;
				while(!is_number(where_to_start))
				{
					where_to_start = string[i];
					i++;
				}
				clean(string, i, size);
			}
		} else {
			printf("%c", string[i]);
		}
		
	}
}

bool is_number(char to_check) 
{
	if(to_check >= 48 && to_check <= 57)
	{
		return true;
	}
	return false;
}


