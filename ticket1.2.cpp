#include <stdio.h>
#include <stdlib.h>

static int START_SIZE;

void put_char(char* string, char size, char to_save);

char* get_numbers(char* string, int size, char& link_of_new_size);

char* create_string(int size);

void print(char* string, int size);

int main()
{
	START_SIZE = 100;
	char* string = create_string(START_SIZE);
	char* answer;
	const char end = 10;
	char size = 0;
	char temp = 'a';
	printf("Enter your string. It can be up to 100"
		"characters and contains only numbers any spaces\n");

	while (true) 
	{
		temp = getchar();
		if (temp != end)
		{
			put_char(string, size, temp);
		}
		else
		{
			char new_size = 0;
			answer = get_numbers(string, size, new_size);
			print(answer, new_size);
			free(string);
			return 0;
		}
		size++;
	}
	return 0;
}

void put_char(char* string, char index, char to_save)
{
	*(string + index) = to_save;
}

char* get_numbers(char* string, int size, char& link_of_new_size)
{
	char* to_be_deleted = (char*) malloc(size * sizeof(char));
	char new_size = 0;
	for (char i = 0; i < size; i++)
	{
		char temp_char = *(string + i);
		if (temp_char != ' ')
		{
			*(to_be_deleted + new_size++) = temp_char;
			if (!((i < size) && (*(string + i + sizeof(char))) != ' '))
			{
				if(i > 0 && *(string + i) != ' ')
				*(to_be_deleted + new_size++) = '!';
			}
		} 
	}
	char* final = (char*) malloc(sizeof(char) * new_size);
	for(char i = 0; i < new_size; i++) 
	{
		*(final + i) = *(to_be_deleted + i);
	}
	link_of_new_size = new_size;
	return final;
}

char* create_string(int size) 
{
	char* to_be_returned = (char*) malloc(size * sizeof(char));
	return to_be_returned;
}

void print(char* string, int size) 
{
	for(char i = 0; i < size; i++) 
	{
		if(*(string + i) != '!') 
		{
			putchar(*(string + i));
		}
		else 
		{
			if(i > 0) 
			{
				if(*(string + i - 1) != '!')
				{
					printf("\n");
				}
			}
			
		}
		
	}
}

//номер 7 на 34