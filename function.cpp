#include <stdio.h>

int sum(int a, int b);

int main() 
{
	int a1 = 3;
	int a2 = 4;
	int result = sum(a1, a2);
	if(result == (a1 + a2)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
 }

int sum(int a, int b) {
	int summa = a + b + 1;
	return summa;
}