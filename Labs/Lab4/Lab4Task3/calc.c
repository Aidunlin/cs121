#include "calc.h"

double read_double(FILE *infile)
{
  double result = 0;
  fscanf(infile, "%lf", &result);
  return result;
}

double get_average(double num1, double num2, double num3, double num4, double num5)
{
  return (num1 + num2 + num3 + num4 + num5) / 5;
}

double get_high(double num1, double num2, double num3, double num4, double num5)
{
  double result = num1;
  if (num2 > result) result = num2;
  if (num3 > result) result = num3;
  if (num4 > result) result = num4;
  if (num5 > result) result = num5;
  return result;
}

double get_low(double num1, double num2, double num3, double num4, double num5)
{
  double result = num1;
  if (num2 < result) result = num2;
  if (num3 < result) result = num3;
  if (num4 < result) result = num4;
  if (num5 < result) result = num5;
  return result;
}

void display_numbers(double num1, double num2, double num3, double num4, double num5)
{
  printf("Numbers:\n");
  printf("%.3lf, %.3lf, %.3lf, %.3lf, %.3lf\n", num1, num2, num3, num4, num5);
}

void display_menu(void)
{
  printf("1. Average\n");
  printf("2. High value\n");
  printf("3. Low value\n");
  printf("\n");
  printf("Choose (1-3): ");
}

double do_operation(int choice, double num1, double num2, double num3, double num4, double num5)
{
  if (choice == 1) return get_average(num1, num2, num3, num4, num5);
  else if (choice == 2) return get_high(num1, num2, num3, num4, num5);
  else if (choice == 3) return get_low(num1, num2, num3, num4, num5);
}
