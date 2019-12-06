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
	char*** matrix;
	int length;
	int width;
	int max_length_of_str;
};

void print_matrixs(struct Matrix** matrixs, const InputValues* inputValues);
void fill_matrixs(struct Matrix** matrixs, const InputValues* inputValues);
int get_input_parameter(int index);
void get_input_data(struct InputValues* inputValues);
struct Matrix* allocate_memory_for_matrixs(struct InputValues* inputValues);
struct Matrix allocate_matrix(struct InputValues* inputValues);
char* input_str(int max_length_of_str, int counter);
char* get_all_words(const struct Matrix* matrix);
char* get_polindroms_from_words(char* const words);
void print_polinfroms(char* const polindroms);
void push_a_char_in_words(char* words, char to_be_pushed);
void push_in_dictionary(char* sentence, char* words, int limit);
int is_letter_or_blank(const char to_be_checked);
int length(char* dictionary);
int get_end_of_word(char* dictionary);
void push_char_in_polindrom(char** refer_to_polindroms, char to_be_pushed);
int check_if_word_is_polindrom(const char*  dictionary, int start, int end);
void push_word_to_polindroms(char** refer_to_polindroms, char* dictionary, int start, int end);
void print_polyndroms(char* const polindroms);

int main(void)
{
	struct InputValues* inputValues;

	get_input_data(inputValues);

	struct Matrix* matrixs = allocate_memory_for_matrixs(inputValues);

	fill_matrixs(&matrixs, inputValues);
	print_matrixs(&matrixs, inputValues);
	char* dictionary = get_all_words(matrixs);
	printf("-----------------------------------\n");
	printf("%s\n", dictionary);
	printf("-----------------------------------\n");
	char* polindroms = get_polindroms_from_words(dictionary);
	printf("-----------------------------------\n");
	print_polyndroms(polindroms);
	printf("-----------------------------------\n");
}

struct Matrix* allocate_memory_for_matrixs(struct InputValues* inputValues)
{
	struct Matrix* matrixs = (Matrix*) malloc(
		inputValues->number_of_matrixs * sizeof(Matrix[0]));
	for(int i = 0; i < inputValues->number_of_matrixs; ++i)
	{
		matrixs[i] = allocate_matrix(inputValues);
	}
	return matrixs;
}

char* get_all_words(const struct Matrix* matrix, const InputValues* inputValues)
{

	char* dictionary = (char*) malloc(inputValues->max_length_of_str * matrix.max_length_of_str
		* matrix.length * matrix.width * sizeof(dictionary[0]));
	for(int k = 0; k < InputValues->max_length_of_str; ++k)
	{
		for(int i = 0; i < matrix.length; ++i)
		{
			int j = 0;
			for(j = 0; j < matrix.width; ++j)
			{
				push_in_dictionary(matrix.matrix[i][j],
					dictionary, matrix.max_length_of_str);
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

int is_letter_or_blank(const char to_be_checked)
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

void print_matrixs(const struct Matrix** matrixs, const InputValues* inputValues)
{
	for(int k = 0; k < inputValues->number_of_matrixs; ++k)
	{
		printf("THIS IS START OF MATRIX:\n");
		int i = 0;
		for(i = 0; i < matrixs[k]->length; ++i)
		{
			int j = 0;
			for(j = 0; j < matrixs[k]->width; ++j)
			{
				printf("%s", matrixs[k]->matrix[i][j]);
			}
			printf("\n");
		}
		printf("THIS IS END OF MATRIX:\n");
	}
	
}

void fill_matrixs(struct Matrix** matrixs, const InputValues* inputValues)
{
	for(int k = 0; k < inputValues->number_of_matrixs; ++k)
	{
		int counter = 0;
		for(int i = 0; i < matrixs[k]->length; ++i)
		{
			int j = 0;
			for(j = 0; j < matrixs[k]->width; ++j)
			{
				//I am not sure, do I really need to allocate memore before writing str there
				//printf("%d %d\n", i, j);
				matrixs[k]->matrix[i][j] =
				 input_str(matrixs[k]->max_length_of_str, counter++);
			}
		}
	}
}

int get_input_parameter(int index)
{
	printf("Enter %d parameter\n", index);
	int temp;
	scanf("%d", &temp);
	return temp;
}

void get_input_data(struct InputValues* inputValues)
{
	inputValues->number_of_matrixs = get_input_parameter(1);
	inputValues->length = get_input_parameter(2);
	inputValues->width = get_input_parameter(3);
	inputValues->max_length_of_str = get_input_parameter(4);
}

struct Matrix allocate_matrix(struct InputValues* inputValues)
{
	struct Matrix matrix;
	matrix.matrix = (char***) malloc(inputValues -> length * sizeof(matrix.matrix[0]));
	
	if(matrix.matrix == NULL)
	{
		//TODO: somehow work with error
		//I am not able to return null
	}

	int i = 0;
	for(i = 0; i < inputValues->length; ++i)
	{
		matrix.matrix[i] = (char**)malloc(inputValues->width * sizeof(matrix.matrix[i][0]));
		if(matrix.matrix[i] == NULL)
		{

		}

		int j = 0;
		for(j = 0; j < inputValues->width; ++j)
		{
			//matrix.matrix[i][j] = (char*) malloc(inputValues -> max_length_of_str * sizeof(matrix.matrix[i][j][0]));
			if(matrix.matrix[i][j] == NULL)
			{

			}
		}
	}
	matrix.length = inputValues->length;
	matrix.width = inputValues->width;
	matrix.max_length_of_str = inputValues->max_length_of_str;
	return matrix;
}

char* input_str(int max_length_of_str, int counter)
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF) { }
	char* temp = (char*) malloc((max_length_of_str + 1) * sizeof(temp[0]));
	printf("Enter %d sentence with max_length %d\n", counter, max_length_of_str);
	fgets(temp, max_length_of_str + 1, stdin);
	return temp;
}

char* get_polindroms_from_words(char* const dictionary)
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

void push_char_in_polindrom(char** refer_to_polindroms, const char to_be_pushed)
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

int check_if_word_is_polindrom(const char* dictionary, int start, int end)
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