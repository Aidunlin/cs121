#include <stdio.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

typedef struct occurrences
{
	int num_occurrences;
	double frequency;
} Occurrences;

/* (#1) Copies at most n characters from source to end of destination array */
char* my_str_n_cat(char* destination, char* source, int n);

/* (#2) Returns the index of the target value, or -1 if it does not exist in sorted_values */
int binary_search(int sorted_values[], int target, int n);

/* (#3) Sorts an array of strings alphabetically */
void bubble_sort(char* strings[], int n);

/* (#4) Recursively determines and returns whether a string is a palindrome */
int is_palindrome(char* string, int length);

/* (#5) Recursively determines and returns the sum of all primes from 2 to n */
int sum_primes(unsigned int n);

/* (#6) Determines the frequency of each character in a string,
returning the max number of occurrences of any character and the corresponding character */
void maximum_occurences(char string[], Occurrences occurrences[26], int* int_ptr, char* char_ptr);

/* (#7) Determines the max number of consecutive integers in a 2D array,
returning the address of the start of the consecutive sequence and the number of consecutive integers */
void max_consecutive_integers(signed int int_array[][5], int rows, int columns, signed int** start_ptr, signed int* count_ptr);
