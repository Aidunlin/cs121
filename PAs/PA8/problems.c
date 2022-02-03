#include "problems.h"

/* (#1) Copies at most n characters from source to end of destination array */
char* my_str_n_cat(char* destination, char* source, int n)
{
	int src_size = 0;
	char* src_char_ptr = source;
	while (*src_char_ptr != '\0')
	{
		src_size++;
		src_char_ptr++;
	}

	int dest_size = 0;
	char* dest_char_ptr = destination;
	while (*dest_char_ptr != '\0')
	{
		dest_size++;
		dest_char_ptr++;
	}

	for (int i = 0; i < n && i < src_size; i++)
	{
		*(destination + dest_size + i) = *(source + i);
	}

	return destination;
}

/* (#2) Returns the index of the target value, or -1 if it does not exist in sorted_values */
int binary_search(int sorted_values[], int target, int n)
{
	int left = 1;
	int right = n;
	int target_index = -1;
	int found = 0;
	int mid;
	while (!found && left <= right)
	{
		mid = (left + right) / 2;
		if (target == sorted_values[mid])
		{
			found = 1;
			target_index = mid;
		}
		else if (target < sorted_values[mid])
		{
			right = mid - 1;
		}
		else if (target > sorted_values[mid])
		{
			left = mid + 1;
		}
	}
	return target_index;
}

/* (#3) Sorts an array of strings alphabetically */
void bubble_sort(char* strings[], int n)
{
	int u = n;
	while (u > 1)
	{
		int c = 1;
		while (c < u)
		{
			if (strcmp(strings[c], strings[c - 1]) < 0)
			{
				char* temp_ptr = strings[c];
				strings[c] = strings[c - 1];
				strings[c - 1] = temp_ptr;
			}
			c++;
		}
		u--;
	}
}

/* (#4) Recursively determines and returns whether a string is a palindrome */
int is_palindrome(char* string, int length)
{
	if (length < 2)
	{
		return 1;
	}

	int left_index = 0;
	while (string[left_index] == ' ')
	{
		left_index++;
	}

	int right_index = length - 1;
	while (string[right_index] == ' ')
	{
		right_index--;
	}

	if (string[left_index] != string[right_index])
	{
		return 0;
	}
	else
	{
		return is_palindrome(string + 1, length - 2);
	}
}

/* (#5) Recursively determines and returns the sum of all primes from 2 to n */
int sum_primes(unsigned int n)
{
	if (n == 2)
	{
		return 2;
	}
	else
	{
		int is_prime = 1;
		for (int i = 2; i < n; i++)
		{
			if (n % i == 0)
			{
				is_prime = 0;
			}
		}
		if (is_prime)
		{
			return n + sum_primes(n - 1);
		}
		else
		{
			return sum_primes(n - 1);
		}
	}
}

/* (#6) Determines the frequency of each character in a string,
returning the max number of occurrences of any character and the corresponding character */
void maximum_occurences(char string[], Occurrences occurrences[26], int* int_ptr, char* char_ptr)
{
	int string_size = 0;
	while (*(string + string_size) != '\0')
	{
		string_size++;
	}

	for (int i = 0; i < string_size; i++)
	{
		char c = string[i];
		occurrences[c - 'a'].num_occurrences++;
		occurrences[c - 'a'].frequency = (double)occurrences[c - 'a'].num_occurrences / string_size;
	}

	for (int i = 0; i < 26; i++)
	{
		if (occurrences[i].num_occurrences > *int_ptr)
		{
			*int_ptr = occurrences[i].num_occurrences;
			*char_ptr = i + 'a';
		}
	}
}

/* (#7) Determines the max number of consecutive integers in a 2D array,
returning the address of the start of the consecutive sequence and the number of consecutive integers */
void max_consecutive_integers(signed int int_array[][5], int rows, int columns, signed int** start_ptr, signed int* count_ptr)
{
	int* current_value_ptr = &int_array[0][0];
	int count = 0;

	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			if (*current_value_ptr == int_array[row][column])
			{
				count++;
			}
			else
			{
				if (count > *count_ptr)
				{
					*count_ptr = count;
					*start_ptr = current_value_ptr;
				}
				current_value_ptr = &int_array[row][column];
				count = 1;
			}
		}
	}
}
