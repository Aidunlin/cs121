/*
  Programmer: Aidan Linerud
  Class: CptS 121, Fall 2021
  Programming Assignment: PA 3
  Date: September 17, 2021
  Description: Collects student data from a file,
    does various calculations on that data,
    and outputs the results to another file.
*/

// Guard code
#ifndef GPA_H
#define GPA_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

/*
  Reads and returns a double from an input file.
  Preconditions:
    - the file must be opened
    - the file contains at least one real number
  Postconditions:
    - the file stream reader is moved after the scanned double
*/
double read_double(FILE* infile);

/*
  Reads and returns an integer from an input file.
  Preconditions:
    - the file must be opened
    - the file contains at least one real number
  Postconditions:
    - the file stream reader is moved after the scanned integer
*/
int read_integer(FILE* infile);

/*
  Returns the sum of five doubles as a double.
  Preconditions: none
  Postconditions: none
*/
double calculate_sum(double number1, double number2, double number3, double number4, double number5);

/*
  Returns the mean by dividing the sum (double) by the number of items (int).
  Preconditions:
    - if the number of items is 0, returns -1
  Postconditions: none
*/
double calculate_mean(double sum, int number);

/*
  Returns the deviation (double) between a double and a mean (double).
  Preconditions: none
  Postconditions: none
*/
double calculate_deviation(double number, double mean);

/*
  Returns the variance (double) of 5 deviations (double).
  Preconditions: none
  Postconditions: none
*/
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);

/*
  Returns the standard deviation (double) of a variance value (double).
  Preconditions:
    - if variance is < 0, the result will be undefined
  Postconditions: none
*/
double calculate_standard_deviation(double variance);

/*
  Returns the maximum value (double) of five doubles.
  Preconditions: none
  Postconditions: none
*/
double find_max(double number1, double number2, double number3, double number4, double number5);

/*
  Returns the minimum value (double) of five doubles.
  Preconditions: none
  Postconditions: none
*/
double find_min(double number1, double number2, double number3, double number4, double number5);

/*
  Prints a double to an output file.
  Preconditions:
    - the file must be opened and writeable
  Postconditions:
    - the number will be truncated to the hundredths place
*/
void print_double(FILE* outfile, double number);

#endif
