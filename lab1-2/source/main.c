#include<stdio.h>
#include<stdlib.h>
#define I 5 
#define R 10

void r(int i, int res);
void highestRating();
void lowestRating();
float aver(int i);
void displayresults();

int res[I][R];
const char *topics[I] = { "Global Warming","The Economy","War","Health Care","Education" };
int main(void)
{
	int res;
	int i;
	do
	{
		printf("Please rate the following topics on a scale from 1 - 10"
			"\n 1= least important,10 = most important\n");
		for (i = 0; i < I; i++)
		{
			do
			{
				printf("%s", topics[i]);
				printf("?");
				scanf_s("%d", &res);
			} while (res < 1 || res>10);
			r(i, res);
		}
		printf("Enter 1 to stop, Enter 0 to rate the issues again.");
		scanf_s("%d", &res);
	} while (res != 1);
	displayresults();
	system("pause");
	return 0;
}
void r(int issue, int rating)
{
	res[issue][rating - 1]++;
}
void highestRating()
{
	int highRating = 0;
	int highTopic = 0;
	int i;
	int j;
	for (i = 0; i < I; i++)
	{
		int topicRating = 0;
		for (j = 0; j < R; j++)
		{
			topicRating += res[i][j] * (j + 1);
		}
		if (highRating < topicRating)
		{
			highRating = topicRating;
			highTopic = i;
		}
	}
	printf("THE HIGHEST TATED TOPIC WAS ");
	printf("%s", topics[highTopic]);
	printf("WITH A TOTAL RATING OF %d\n", highRating);
}
void lowestRating()
{
	int lowRating ;
	int lowTopic = 0;
	int i;
	int j;
	for (i = 0; i < I; i++)
	{
		int topicRating = 0;
		for (j = 0; j < R; j++)
		{
			topicRating += res[i][j] * (j + 1);
		}
		if (i==0)
		{
			lowRating = topicRating;
		}
		if (lowRating >topicRating)
		{
			lowRating = topicRating;
			lowTopic = i;
		}
	}
	printf("THE LOWEST TATED TOPIC WAS ");
	printf("%s", topics[lowTopic]);
	printf("WITH A TOTAL RATING OF %d\n", lowRating);
}
float aver(int i)
{
	float total = 0;
	int counter = 0;
	int j;
	for (j = 0; j < R; j++)
	{
		if (res[i][j] != 0)
		{
			total += res[i][j] * (j + 1);
			counter += res[i][j];
		}
	}
	return total / counter;
}
void displayresults()
{
	int i;
	int j;
	printf("%20s", "Topic");
	for (i = 1; i <= R; i++)
	{
		printf("%4d", i);
	}
	printf("%20s\n", "Average Rating");
	for (i = 0; i < I; i++)
	{
		printf("%20s", topics[i]);
		for (j = 0; j < R; j++)
		{
			printf("%4d", res[i][j]);
		}
		printf("%20.2f\n", aver(i));
	}
	highestRating();
	lowestRating();
}
