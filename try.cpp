#include <stdio.h>
#include <stdlib.h>

int main() 
{
	char* string = (char*) malloc(50 * sizeof(char));
	//fgetpos(string);
	int c = fgetc(stdin);
	printf("%d\n", c);
	return 0;
}