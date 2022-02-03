/* Programmer: Aidan Linerud
Description: Set of functions I use often */

#ifndef AIDANLIB_H
#define AIDANLIB_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum bool
{
    FALSE,
    TRUE
} Bool;

/* Clears the console */
void clearConsole();

/* Pauses the console */
void pauseConsole();

/* Returns an integer from the user */
int getIntInput();

/* Returns an integer clamped between two values */
int clampInt(int x, int a, int b);

/* Creates an integer array with custom size and default values */
void initializeIntArray(int arr[], int size, int value);

/* Sequentially prints every character from a file to the terminal */
void printFile(char *fileName);

/* Prints a string to the console and a file */
void printLog(FILE *logFile, char *message);

/* Prints a string (with an int value) to the console and a file */
void printLogInt(FILE *logFile, char *message, int value, char *suffix);

/* Exists to make a simplified random seed function */
void seedRand();

/* Returns a random integer between (inclusively) two values */
int randInt(int minValue, int maxValue);

/* Swaps two integers in memory via pointers */
void swapInt(int *value1, int *value2);

/* Returns two integers closest to the half of a value
Ex: splitting 5 returns 2 and 3, splitting 6 returns 3 and 3 */
void splitInt(int value, int *split1, int *split2);

/* Sorts an array using bubble sort
Post: Directly updates the array */
void bubbleSort(int arr[], int size);

/* Sorts an array using selection sort
Post: Directly updates the array */
void selectionSort(int arr[], int size);

/* Gets the sum of a specific value in an integer array */
int getArraySumOf(int arr[], int size, int value);

/* Gets the sum of all the values in an integer array */
int getArraySum(int arr[], int size);

#endif
