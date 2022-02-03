/*
  Programmer: Aidan Linerud
  Class: CptS 121, Fall 2021
  Programming Assignment: PA 3
  Date: September 17, 2021
  Description: Collects student data from a file,
    does various calculations on that data,
    and outputs the results to another file.
*/

#include "gpa.h"

/*
  Reads and returns a double from an input file.
  Preconditions:
    - the file must be opened
    - the file contains at least one real number
  Postconditions:
    - the file stream reader is moved after the scanned double
*/
double read_double(FILE* infile)
{
  double result = 0;
  fscanf(infile, "%lf", &result);
  return result;
}

/*
  Reads and returns an integer from an input file.
  Preconditions:
    - the file must be opened
    - the file contains at least one real number
  Postconditions:
    - the file stream reader is moved after the scanned integer
*/
int read_integer(FILE* infile)
{
  int result = 0;
  fscanf(infile, "%d", &result);
  return result;
}

/*
  Returns the sum of five doubles as a double.
  Preconditions: none
  Postconditions: none
*/
double calculate_sum(double number1, double number2, double number3, double number4, double number5)
{
  return number1 + number2 + number3 + number4 + number5;
}

/*
  Returns the mean by dividing the sum (double) by the number of items (int).
  Preconditions:
    - if the number of items is 0, returns -1
  Postconditions: none
*/
double calculate_mean(double sum, int number)
{
  if (number == 0)
  {
    return -1;
  }
  else
  {
    return sum / number;
  }
}

/*
  Returns the deviation (double) between a double and a mean (double).
  Preconditions: none
  Postconditions: none
*/
double calculate_deviation(double number, double mean)
{
  return number - mean;
}

/*
  Returns the variance (double) of 5 deviations (double).
  Preconditions: none
  Postconditions: none
*/
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
{
  double sum = pow(deviation1, 2) + pow(deviation2, 2) + pow(deviation3, 2) + pow(deviation4, 2) + pow(deviation5, 2);
  return calculate_mean(sum, number);
}

/*
  Returns the standard deviation (double) of a variance value (double).
  Preconditions:
    - if variance is < 0, the result will be undefined
  Postconditions: none
*/
double calculate_standard_deviation(double variance)
{
  return sqrt(variance);
}

/*
  Returns the maximum value (double) of five doubles.
  Preconditions: none
  Postconditions: none
*/
double find_max(double number1, double number2, double number3, double number4, double number5)
{
  double max = number1;
  if (number2 > max)
  {
    max = number2;
  }
  if (number3 > max)
  {
    max = number3;
  }
  if (number4 > max)
  {
    max = number4;
  }
  if (number5 > max)
  {
    max = number5;
  }
  return max;
}

/*
  Returns the minimum value (double) of five doubles.
  Preconditions: none
  Postconditions: none
*/
double find_min(double number1, double number2, double number3, double number4, double number5)
{
  double min = number1;
  if (number2 < min)
  {
    min = number2;
  }
  if (number3 < min)
  {
    min = number3;
  }
  if (number4 < min)
  {
    min = number4;
  }
  if (number5 < min)
  {
    min = number5;
  }
  return min;
}

/*
  Prints a double to an output file.
  Preconditions:
    - the file must be opened and writeable
  Postconditions:
    - the number will be truncated to the hundredths place
*/
void print_double(FILE* outfile, double number)
{
  fprintf(outfile, "%.2lf\n", number);
}
