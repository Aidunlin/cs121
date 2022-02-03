/* Programmer: Aidan Linerud
Description: Set of functions I use often */

#include "aidanlib.h"

/* Clears the console */
void clearConsole()
{
    system("cls");
}

/* Pauses the console */
void pauseConsole()
{
    system("pause");
}

/* Returns an integer from the user */
int getIntInput()
{
    int input;
    printf("\n> ");
    scanf("%d", &input);
    return input;
}

/* Returns an integer clamped between two values */
int clampInt(int x, int a, int b)
{
    int result = x;
    if (a > result)
    {
        result = a;
    }
    if (b < result)
    {
        result = b;
    }
    return result;
}

/* Creates an integer array with custom size and default values */
void initializeIntArray(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = value;
    }
}

/* Sequentially prints every character from a file to the terminal */
void printFile(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    char c = '\0';
    while (!feof(file))
    {
        fscanf(file, "%c", &c);
        putchar(c);
    }
    fclose(file);
}

/* Prints a string to the console and a file */
void printLog(FILE *logFile, char *message)
{
    printf("%s", message);
    fprintf(logFile, "%s", message);
}

/* Prints a string (with an int value) to the console and a file */
void printLogInt(FILE *logFile, char *message, int value, char *suffix)
{
    printf("%s: %d%s", message, value, suffix);
    fprintf(logFile, "%s: %d%s", message, value, suffix);
}

/* Exists to make a simplified random seed function */
void seedRand()
{
    srand((unsigned int)time(NULL));
}

/* Returns a random integer between (inclusively) two values */
int randInt(int minValue, int maxValue)
{
    return rand() % (maxValue + 1 - minValue) + minValue;
}

/* Swaps two integers in memory via pointers */
void swapInt(int *value1, int *value2)
{
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}

/* Returns two integers closest to the half of a value
EX: splitting 5 returns 2 and 3, splitting 6 returns 3 and 3 */
void splitInt(int value, int *split1, int *split2)
{
    *split1 = value / 2;
    *split2 = value - *split1;
}

/* Sorts an array using bubble sort
Post: Directly updates the array */
void bubbleSort(int arr[], int size)
{
    for (int pass = 0; pass < size - 1; pass++)
    {
        for (int i = 0; i < size - pass - 1; i++)
        {
            int isOrdered = arr[i + 1] > arr[i];
            if (!isOrdered)
            {
                swapInt(&arr[i], &arr[i + 1]);
            }
        }
    }
}

/* Sorts an array using selection sort
Post: Directly updates the array */
void selectionSort(int arr[], int size)
{
    for (int pass = 1; pass < size; pass++)
    {
        int maxIndex = 0;
        for (int i = 1; i <= size - pass; i++)
        {
            if (arr[maxIndex] < arr[i])
            {
                maxIndex = i;
            }
        }
        swapInt(&arr[maxIndex], &arr[size - pass]);
    }
}

/* Gets the sum of a specific value in an integer array */
int getArraySumOf(int arr[], int size, int value)
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

/* Gets the sum of all the values in an integer array */
int getArraySum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
