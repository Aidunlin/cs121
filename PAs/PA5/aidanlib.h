/*
	Programmer: Aidan Linerud
	Description: Set of functions I use often
*/

#ifndef AIDANLIB_H
#define AIDANLIB_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	Prints a custom message and pauses the console
*/
void pause_console(char* message);

/*
	Returns an integer from the user
*/
int get_int_input(void);

/*
	Creates an integer array with custom size and default values
*/
void init_int_array(int arr[], int size, int value);

/*
	Sequentially prints every character from a file to the terminal
*/
void print_file(char* file_name);

/*
	Exists to make a simplified random seed function
*/
void seed_rand(void);

/*
	Returns a random integer between (inclusively) two values
*/
int rand_int(int max_value, int min_value);

/*
	Swaps two integers in memory via pointers
*/
void swap_int(int* value1, int* value2);

/*
	Returns two integers closest to the half of a value
	EX: splitting 5 returns 2 and 3, splitting 6 returns 3 and 3
*/
void split_int(int value, int* split1, int* split2);

/*
	Returns an integer clamped between two values
*/
int clamp_int(int value, int min, int max);

/*
	Sorts an array using bubble sort
	Post: Directly updates the array
*/
void bubble_sort(int arr[], int size);

/*
	Sorts an array using selection sort
	Post: Directly updates the array
*/
void selection_sort(int arr[], int size);

/*
	Gets the sum of a specific value in an integer array
*/
int get_array_sum_of(int arr[], int size, int value);

/*
	Gets the sum of all the values in an integer array
*/
int get_array_sum(int arr[], int size);

#endif
