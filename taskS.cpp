#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size;
	int result_size;
	
	char str1[20] = "1123";
	printf("string lenght = ");
	scanf("%d", &size);

	char* str = (char*) calloc(size, sizeof(char));

	//printf("enter string: ");
	//rewind(stdin);
	char* temp = fgets(str1, 20, stdin);
	
	printf("\nyour string:\n");
	printf("%s",str1); 
	return 0;
}