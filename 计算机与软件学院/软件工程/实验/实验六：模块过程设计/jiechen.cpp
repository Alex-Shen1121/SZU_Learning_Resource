// jiechen.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

#define MAX_NUM 1000
#define STORE_SIZE 3000

int main(int argc, char *argv[])
{
	int result[STORE_SIZE];
	int num;

	printf("Please input an integer between 0 and %d:", MAX_NUM);
	scanf("%d", &num);
	if (num < 0)
		num = 0;
	if (num > MAX_NUM)
		num = MAX_NUM;

	// Initialize the result
	for (int i = 0; i < STORE_SIZE; i++)
	{
		result[i] = 0;
	}

	// Set the last key
	result[0] = 1;

	// Begin compute the result
	for (int j = 1; j <= num; j++)
	{
		// Times each key with the new number
		for (int i = 0; i < MAX_NUM; i++)
		{
			result[i] *= j;
		}

		// We will add the
		for (int i = 0; i < STORE_SIZE; i++)
		{
			if (result[i] >= 10)
			{
				// Add the result of 10 times to the high key
				result[i + 1] = result[i] / 10;

				// Get the value of current key.
				result[i] = result[i] % 10;
			}
		}
	}

	// print the result
	for (int i = STORE_SIZE - 1; i >= 0; i--)
	{
		printf("%d", result[i]);
	}
	printf("\n");

	return 0;
}
