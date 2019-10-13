#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void myStart(void) __attribute__ ((constructor));
void myEnd(void) __attribute__ ((destructor));

int* p;

int main(int argc, char const *argv[])
{
	FILE* file = fopen("text.docx", "w");
	if(file == NULL) 
  { 
    printf("\n could not open file "); 
    getchar(); 
    exit(1); 
  }  
	fprintf(file, "%s", "Geeks for Geeks"); 
	return 0;
}

void myStart(void) {
	p = (int*) malloc(10 * sizeof(int));
}

void myEnd(void) {
	free(p);
}