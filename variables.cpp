#include <stdio.h>

extern int externVariable = 9;
int global = 10;


typedef long long int LL;

void cal(int arg) {
	printf("%d\n", arg * arg);
}

int main(void) {
	const int constInt =  32;
	char charSymbol = 'G';
	extern int z;
	LL syperType = 1000000;
	printf("This is the value of the constant variable 'constInt': %d\n", constInt); 
    printf("'charSymbol' is a char variable. Its value is %c\n",charSymbol); 
    printf("'syperType' is a long long int variable. Its value is %lld\n", syperType); 
    printf("These are the values of the extern variables 'externVariable' and 'global'"
    " respectively: %d and %d\n", externVariable, global); 
  
    externVariable = 2;
    global = 5;

    printf("These are the modified values of the extern variables"
    " 'externVariable' and 'global' respectively: %d and %d\n", externVariable, global); 
  
    // using a static variable 
    printf("The value of static variable 'someStatic' is NOT initialized to 5 after the "
            "first iteration! See for yourself :)\n"); 
  
  	while (externVariable > 0) 
    { 
        static int someStatic = 5; 
        someStatic++; 
        // printing value at each iteration 
        printf("The value of someStatic is %d\n",someStatic); 
        externVariable--; 
    } 
  
    // print square of 5 
    cal(5);  
    return 0; 
}
