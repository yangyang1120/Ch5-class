#include<stdio.h>
#include<stdlib.h>
#define S 3
#define E 4

void mini(int g[][E], int pupils, int tests);
void maxi(int g[][E], int pupils, int tests);
void aver(int g[][E], int pupils, int tests);
void printfArray(int g[][E], int pupils, int tests);
void printfMenu(void);

int main()
{
	void(*processGrades[4])(int[][E], int, int)
		= { printfArray, mini, maxi, aver };
	int c = 0;
	int sg[S][E] = { {77,68,86,73},{96,87,89,78},{70,90,86,81} };

	while (c != 4)
	{
		do
		{
			printfMenu();
			scanf_s("%d", &c);
		} while (c < 0 || c>4);
		if (c != 4)
		{
			(*processGrades[c])(sg, S, E);
		}
		else
		{
			printf("Program Ended.\n");
		}
	}
	system("pause");
	return 0;
}

void mini(int g[][E], int pupils, int tests)
{
	int i;
	int j;
	int lowg = 100;
	for (i = 0; i <= pupils - 1; i++)
	{
		for (j = 0; j <= tests - 1; j++)
		{
			if (g[i][j] < lowg)
			{
				lowg = g[i][j];
			}
		}
	}
	printf("\n\tThe lowest grade is %d\n", lowg);
}
void maxi(int g[][E], int pupils, int tests)
{
	int i;
	int j;
	int highg = 0;
	for (i = 0; i <= pupils - 1; i++)
	{
		for (j = 0; j <= tests - 1; j++)
		{
			if (g[i][j] > highg)
			{
				highg = g[i][j];
			}
		}
	}
	printf("\n\tThe highest grade is %d\n", highg);
}
void aver(int g[][E], int pupils, int tests)
{
	int i;
	int j;
	int total;
	printf("\n");
	for (i = 0; i <= pupils - 1; i++)
	{
		total = 0;
		for (j = 0; j <= tests - 1; j++)
		{
			total += g[i][j];
		}
		printf("\tThe average for student %d id %.1f\n", i + 1, (double)total / tests);

	}
}
void printfArray(int g[][E], int pupils, int tests)
{
	int i;
	int j;
	printf("\n\t            [0]  [1]  [2]  [3]");
	for (i = 0; i <= pupils - 1; i++)
	{
		printf("\n\tstudentGrade[%d]", i);
		for (j = 0; j <= tests - 1; j++)
		{
			printf("%-7d", g[i][j]);
		}
	}
	printf("\n");
}
void printfMenu(void)
{
	printf("\n\tEnter a choice:\n"
		   "\t 0 Print the array of grade\n"
		   "\t 1 Find the minimum grade\n"
		   "\t 2 Find the maximum grade\n"
		   "\t 3 Print the axerage on all"
		   "tests for each student \n"
		   "\t 4 End program\n"
		   "\t?");
}

