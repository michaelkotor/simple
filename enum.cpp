#include <stdio.h>
#include <stdlib.h>


enum State {
	Working = 0,
	Failing = 1,
	Warning = 2,
	Exit = 3
};

enum Week {
	Monday = 1, Tuesday, Wensday = 40, Thirsday, Friday, Saturday, Sunday 
};

enum Week days;
enum State Michael;

int main(void) {
	const int size = 10;
	int array[size];
	for(int i = Working; i <= Exit; i++) {
		printf("%d\n", i);
	}

	for(int i = Monday; i <= Sunday; i++) {
		printf("%d\n", i);
	}
	return 0;
}