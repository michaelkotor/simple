#include <stdio.h> 
#include <stdlib.h>

int get_length(char* str, int limit);
char* input(int limit);
int get_limit();
void print(char* str);
bool is_number(char to_check);
void push(char* where_to_push, char what_to_push);
char* get_clean(char* str, int limit);


int main() 
{ 
	int limit = get_limit();
	char* str = input(limit);
  	print(str);
  	char* new_str = get_clean(str, limit);
  	print(new_str);
  	free(str);
  	free(new_str);
  	return 0;
} 

char* get_clean(char* str, int limit)
{
	int size = get_length(str, limit);
	char* result = (char*) malloc(size * sizeof(char));

	bool after_dot = false;
	int symbols_passed = 0;
	int index_after_dot = 0;
	//bool is_pass_now = false;

	for(char i = 0 ; i < size; i++)
	{
		char temp = *(str + i);

		if(temp == '.')
		{
			after_dot = true;
		}

		if(after_dot)
		{
			if(temp == '.')
			{
				push(result, temp);
				continue;
			}
			index_after_dot++;
			if(index_after_dot > 2)
			{
				if(is_number(temp)) 
				{
					symbols_passed++;
					continue;
				}
				else
				{
					push(result, temp);
					after_dot = false;
					index_after_dot = 0;
				}
			}
			else 
			{
				push(result, temp);
			}
		}
		else
		{
			push(result, temp);
		}
	}

	result = (char*) realloc(result, (size - symbols_passed) * sizeof(char));
	return result;
}

void push(char* where_to_push, char what_to_push)
{
	static int i;
	*(where_to_push + i++) = what_to_push;
}

bool is_number(char to_check) 
{
	if((to_check >= 48) && (to_check <= 57))
	{
		return 1;
	}
	return 0;
}

char* input(int limit)
{
	printf("%s\n", "put your str");
	char* str = (char*) calloc(limit + 2, sizeof(char));
	fgets(str, limit + 1, std::stdin);
  	return str;
}

int get_limit()
{
	int limit;
	printf("Enter the length of the string\n");
	scanf("%d", &limit);
	while ((getchar()) != '\n');
	return limit;
} 

int get_length(char* str, int limit) 
{
	int last_index = 0;
	while(*(str + last_index) != '\0')
	{
		last_index++;
	}
	if(last_index < limit)
	{
		return last_index - 1;
	}
	return last_index;
}

void print(char* str) 
{
	printf("Your str:\n");
	printf("%s", str);
}

//лаба номер 9, 10. страница 36