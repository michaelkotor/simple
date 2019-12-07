#include <stdlib.h>
#include <stdio.h>

struct InputValues
{
	int number_of_matrixs;
	int length;
	int width;
	int max_length_of_str;
};

struct Matrix
{
	char*** table;
	int length;
	int width;
	int max_length_of_str;
};

void get_input_data(struct InputValues* inputValues);

int get_input_parameter(int index);

struct Matrix* allocate_memory_for_matrixs(struct InputValues* inputValues);
struct Matrix* allocate_matrix(struct InputValues* inputValues);

void fill_matrixs(struct Matrix** matrixs, InputValues* inputValues);

char* input_str(int max_length_of_str, int counter);

void print_matrixs(struct Matrix** matrixs, InputValues* inputValues);

char* get_all_words(struct Matrix* matrix, InputValues* inputValues);
char* get_polindroms_from_words(char* words);
void print_polinfroms(char* polindroms);
void push_a_char_in_words(char* words, char to_be_pushed);
void push_in_dictionary(char* sentence, char* words, int limit);
int is_letter_or_blank(char to_be_checked);
int length(char* dictionary);
int get_end_of_word(char* dictionary);
void push_char_in_polindrom(char** refer_to_polindroms, char to_be_pushed);
int check_if_word_is_polindrom(char*  dictionary, int start, int end);
void push_word_to_polindroms(char** refer_to_polindroms, char* dictionary, int start, int end);
void print_polyndroms(char* polindroms);

int main(void)
{
	struct InputValues input;
	struct InputValues* inputValues = &input;

	get_input_data(inputValues);
	
	struct Matrix* reallMatrixs = allocate_memory_for_matrixs(inputValues);
	struct Matrix** matrixs = &reallMatrixs;
	
	//print_matrixs(matrixs, inputValues);
	//fill_matrixs(matrixs, inputValues);
	
	// char* dictionary = get_all_words(matrixs, inputValues);
	// printf("-----------------------------------\n");
	// printf("%s\n", dictionary);
	// printf("-----------------------------------\n");
	// char* polindroms = get_polindroms_from_words(dictionary);
	// printf("-----------------------------------\n");
	// print_polyndroms(polindroms);
	// printf("-----------------------------------\n");
}

void get_input_data(struct InputValues* inputValues)
{

	inputValues->number_of_matrixs = get_input_parameter(1);
	inputValues->length = get_input_parameter(2);
	inputValues->width = get_input_parameter(3);
	//inputValues->max_length_of_str = get_input_parameter(4);
	inputValues->max_length_of_str = 40;
}

int get_input_parameter(int index)
{
	printf("Enter %d parameter\n", index);
	int temp;
	scanf("%d", &temp);
	return temp;
}

struct Matrix* allocate_memory_for_matrixs(struct InputValues* inputValues)
{
	printf("----------------------------------------\n");
	printf("Let's allocate memory for %d matrixs\n", inputValues->number_of_matrixs);
	printf("----------------------------------------\n");

	struct Matrix* matrixs = (Matrix*)
		calloc(inputValues->number_of_matrixs, sizeof(matrixs[0]));

	for(int i = 0; i < inputValues->number_of_matrixs; ++i)
	{
		printf("I allocate memory for %d matrix\n", i);
		//TODO: change
		{
			Matrix* temp = allocate_matrix(inputValues);
			InputValues input1 = {1, 2, 2, 0};
			print_matrixs(&temp,  &input1);
		}
		
		matrixs[i] = allocate_matrix(inputValues)[0];
	}
	return matrixs;
}

struct Matrix* allocate_matrix(struct InputValues* inputValues)
{
	struct Matrix reallMatrix;
	struct Matrix* matrix = &reallMatrix;

	matrix->table = (char***) calloc(inputValues->length, sizeof(matrix->table[0]));

	for(int i = 0; i < inputValues->length; ++i)
	{
		printf("Allocation memory for %d element\n", i);
		matrix->table[i] = (char**) calloc(inputValues->width, sizeof(matrix->table[i][0]));

		for(int j = 0; j < inputValues->width; ++j)
		{
			printf("I also allocate memory for str...\n");
			matrix->table[i][j] = (char*) calloc(matrix->max_length_of_str, sizeof(matrix->table[i][j][0]));
		}
	}

	matrix->length = inputValues->length;
	matrix->width = inputValues->width;
	matrix->max_length_of_str = inputValues->max_length_of_str;

	return matrix;
}

void fill_matrixs(struct Matrix** matrixs, InputValues* inputValues)
{
	printf("----------------------------------------\n");
	printf("Let's get string for matrixs\n");
	printf("----------------------------------------\n");

	for(int k = 0; k < inputValues->number_of_matrixs; ++k)
	{
		printf("I work with %d matrix\n", k);
		int counter = 0;
		for(int i = 0; i < inputValues->length; ++i)
		{
			for(int j = 0; j < inputValues->width; ++j)
			{
				//I am not sure, do I really need to allocate memore before writing str there
				printf("%d %d\n", i, j);
				matrixs[0]->table[i][j] =
				 input_str(matrixs[0]->max_length_of_str, counter++);
				 printf("I fell here\n");
			}
		}
	}
}

char* input_str(int max_length_of_str, int counter)
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF) { }
	char* temp = (char*) calloc(max_length_of_str + 1, sizeof(temp[0]));
	printf("Enter %d sentence with max_length %d\n", counter, max_length_of_str);
	fgets(temp, max_length_of_str + 1, stdin);
	return temp;
}

void print_matrixs(struct Matrix** matrixs, InputValues* inputValues)
{
	printf("----------------------------------------\n");
	printf("Let's print all the matrixs\n");
	printf("----------------------------------------\n");

	for(int k = 0; k < inputValues->number_of_matrixs; ++k)
	{
		printf("THIS IS START OF %d MATRIX:\n", k);

		for(int i = 0; i < matrixs[k]->length; ++i)
		{
			for(int j = 0; j < matrixs[k]->width; ++j)
			{
				printf("%s", matrixs[k]->table[i][j]);
			}
			printf("\n");
		}
		printf("THIS IS END OF MATRIX:\n");
	}
}



















char* get_all_words(struct Matrix* matrixs, InputValues* inputValues)
{

	char* dictionary = (char*) malloc(inputValues->max_length_of_str * 
		matrixs[0].max_length_of_str
		* matrixs[0].length * matrixs[0].width * sizeof(dictionary[0]));
	for(int k = 0; k < inputValues->max_length_of_str; ++k)
	{
		for(int i = 0; i < matrixs[k].length; ++i)
		{
			int j = 0;
			for(j = 0; j < matrixs[k].width; ++j)
			{
				push_in_dictionary(matrixs[k].table[i][j],
					dictionary, matrixs[k].max_length_of_str);
			}
		}
	}
	
	push_a_char_in_words(dictionary, '\0');
	return dictionary;
}

void push_in_dictionary(char* sentence, char* dictionary, int limit)
{
	int i = 0;
	for(i = 0; i < limit; ++i)
	{
		char temp = sentence[i];
		//printf("%c\n", temp);
		if(is_letter_or_blank(temp) > 0)
		{
			//printf("PUSHED\n");
			push_a_char_in_words(dictionary, temp);
		}
	}	
	push_a_char_in_words(dictionary, ' ');
}

int is_letter_or_blank(char to_be_checked)
{
	if(((to_be_checked >= 65 && to_be_checked <= 90) ||
		(to_be_checked >= 97 && to_be_checked <= 122))
		|| to_be_checked == 32)
	{
		return 1;
	}
	return 0;
}

void push_a_char_in_words(char* dictionary, char to_be_pushed)
{
	static int i;
	if(to_be_pushed == '\n') return;
	dictionary[i++] = to_be_pushed;
}

char* get_polindroms_from_words(char* dictionary)
{
	int size = length(dictionary);
	char* polindroms = (char*) 
		malloc(size * sizeof(polindroms[0]));

	printf("The length of dictionary is %d\n",
		size);

	char** refer_to_polindroms = &polindroms;

	int is_symbol_after_dot = 1;
	int i;
	for(i = 0 ; i < size; ++i)
	{
		char symbol = dictionary[i];
		if(symbol == ' ')
		{
			is_symbol_after_dot = 1;
			continue;
		}
		else
		{
			if(is_symbol_after_dot > 0)
			{
				is_symbol_after_dot = 0;
				int start = i;
				int end = get_end_of_word(dictionary + start + 1) + start;
				printf("The start id %d and the end is %d\n", start, end);

				if(check_if_word_is_polindrom(dictionary,
				 start, end + 1) > 0)
				{
					printf("---The word is polindroms!---\n");
					push_word_to_polindroms(refer_to_polindroms, dictionary, start, end);
					push_char_in_polindrom(refer_to_polindroms, '!');
				}
			}
			
		}
	}
	push_char_in_polindrom(refer_to_polindroms, '!');
	push_char_in_polindrom(refer_to_polindroms, '\0');
	return polindroms;
}

void push_word_to_polindroms(char** refer_to_polindroms, char* dictionary, int start, int end)
{
	int i; 
	printf("-----I want to push these word to polindroms!-----\n");

	for(int i = start; i < end; ++i)
	{
		printf("%c", dictionary[i]);
	}
	printf("\n");
	for(i = start; i <= end; ++i)
	{
		push_char_in_polindrom(refer_to_polindroms, dictionary[i]);
	}
}

void push_char_in_polindrom(char** refer_to_polindroms, char to_be_pushed)
{
	static int i;
	printf("Now the polindroms contains just \n%s\n", *refer_to_polindroms);
	printf("I push char %c to position %d\n", to_be_pushed, i);
	(*refer_to_polindroms)[i++] = to_be_pushed;
}

void print_polyndroms(char* polindroms)
{
	printf("THE POLINDROMS ARE\n");
	int size = length(polindroms);
	for(int i = 0; i < size; ++i)
	{
		char temp = polindroms[i];
		if(temp == '!')
		{
			printf("\n");
		}
		else
		{
			printf("%c", temp);
		}
		
	}
}

int length(char* to_be_count)
{
	int i = 0;
	while(to_be_count[i] != '\0'){i++;}
	return i;
}

/*
int length(char* dictionary)
{
	static int i;
	if(dictionary[i++] != '\0')
	{
		return length(dictionary);
	}
	return i;
}
*/

int get_end_of_word(char* word)
{
	int i = 0;
	while(word[0] != ' ' && word[0] != 0){
		word++;
		i++;
	}
	return i;
}

int check_if_word_is_polindrom(char* dictionary, int start, int end)
{
	printf("I want check if these word is polindroms\n");
	printf("----------------------------------\n");
	for(int i = start; i < end; i++)
	{
		printf("%c", dictionary[i]);
	}
	printf("\n----------------------------------\n");
	
	//printf("%s\n", dictionary + start);
	int i;
	for(i = start; i <= start + (end - start) / 2; ++i)
	{
		printf("I want to check, if %c is the same as %c\n", dictionary[i], dictionary[end - i - 1]);
		if(dictionary[i] != dictionary[end - i - 1])
		{
			printf("I found out, that the word is not a polindroms :-(\n");
			return 0;
		}
	}
	printf("---The word is polindroms!!! It MUST be int he answer---\n");
	return 1;
}