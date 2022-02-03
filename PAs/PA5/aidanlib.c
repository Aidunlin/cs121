/*
	Programmer: Aidan Linerud
	Description: Set of functions I use often
*/

#include "aidanlib.h"

/*
	Prints a custom message and pauses the console
*/
void pause_console(char* message)
{
	printf("%s\n", message);
	system("pause >nul");
}

/*
	Returns an integer from the user
*/
int get_int_input(void)
{
	int input;
	printf("\n> ");
	scanf("%d", &input);
	return input;
}

/*
	Creates an integer array with custom size and default values
*/
void init_int_array(int arr[], int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = value;
	}
}

/*
	Sequentially prints every character from a file to the terminal
*/
void print_file(char* file_name)
{
	FILE* file = fopen(file_name, "r");
	char c = '\0';
	while (!feof(file))
	{
		fscanf(file, "%c", &c);
		printf("%c", c);
	}
	fclose(file);
}

/*
	Exists to make a simplified random seed function
*/
void seed_rand(void)
{
	srand((unsigned int)time(NULL));
}

/*
	Returns a random integer between (inclusively) two values
*/
int rand_int(int min_value, int max_value)
{
	return rand() % (max_value + 1 - min_value) + min_value;
}

/*
	Swaps two integers in memory via pointers
*/
void swap_int(int* value1, int* value2)
{
	int temp = *value1;
	*value1 = *value2;
	*value2 = temp;
}

/*
	Returns two integers closest to the half of a value
	EX: splitting 5 returns 2 and 3, splitting 6 returns 3 and 3
*/
void split_int(int value, int* split1, int* split2)
{
	*split1 = value / 2;
	*split2 = value - *split1;
}

/*
	Returns an integer clamped between two values
*/
int clamp_int(int value, int min, int max)
{
	if (value < min)
	{
		value = min;
	}
	if (value > max)
	{
		value = max;
	}
	return value;
}

/*
	Sorts an array using bubble sort
	Post: Directly updates the array
*/
void bubble_sort(int arr[], int size)
{
	for (int pass = 0; pass < size - 1; pass++)
	{
		for (int i = 0; i < size - pass - 1; i++)
		{
			int is_ordered = arr[i + 1] > arr[i];
			if (!is_ordered)
			{
				swap_int(&arr[i], &arr[i + 1]);
			}
		}
	}
}

/*
	Sorts an array using selection sort
	Post: Directly updates the array
*/
void selection_sort(int arr[], int size)
{
	for (int pass = 1; pass < size; pass++)
	{
		int max_index = 0;
		for (int i = 1; i <= size - pass; i++)
		{
			if (arr[max_index] < arr[i])
			{
				max_index = i;
			}
		}
		swap_int(&arr[max_index], &arr[size - pass]);
	}
}

/*
	Gets the sum of a specific value in an integer array
*/
int get_array_sum_of(int arr[], int size, int value)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			sum += value;
		}
	}
	return sum;
}

/*
	Gets the sum of all the values in an integer array
*/
int get_array_sum(int arr[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}
