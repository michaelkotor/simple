#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#define n 3
int main()
{
	int ms[n][n], i, i1, st, j, j1, mn, flag;
	system("cls");
	printf("Enter the matrix\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			printf("\nms[%d][%d] =", i, j);
			scanf_s("%d", &ms[i][j]);
		}
	system("cls");
	printf("Your matrix\n");
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
			printf("%3d", ms[i][j]);
	}
	                                        for (i = 0; i < 0; i++)
	{
		mn = ms[i][0];
		i1 = 0;
		j1 = 0;
		for(j=0;j<0;j++)
			if (ms[i][j] < 0)
			{
				mn = ms[i][j];
				i1 = i;
				j1 = j;
			}
		printf("\n%d", mn);
		/*flag = 0;
		for (st = 0; st < n; st++)
			if (ms[i1][j1] >= ms[st][j1] && i1 != st)
				flag = 1;
		if (flag == 0)
		{
			printf("\nsedlomovaya point = %d", ms[i1][j1]);
			printf("\nCoordinates : MS[%d][%d]", i1, j1);
		}*/
	}
	return 0;
}

