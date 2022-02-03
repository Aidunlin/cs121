#include <stdio.h>
#include <math.h>

void task1(void)
{
  FILE *salaries_file = fopen("salaries.txt", "r");
  double sum = 0;
  while (!feof(salaries_file))
  {
    double payment = 0;
    fscanf(salaries_file, "%lf", &payment);
    sum += payment;
  }
  fclose(salaries_file);
  if (sum < 15000) printf("l\n");
  else if (sum <= 200000) printf("m\n");
  else printf("h\n");
  system("pause");
}

void task2(void)
{
  double sum = 0;
  int count_values = 0;
  FILE *data_file = fopen("data.txt", "r");
  while (!feof(data_file))
  {
    double value = 0;
    fscanf(data_file, "%lf", &value);
    sum += value;
    ++count_values;
  }
  fclose(data_file);
  FILE *output_file = fopen("output.txt", "w");
  double average = sum / count_values;
  fprintf(output_file, "%lf", average);
  fclose(output_file);
  printf("task 2 done (check output.txt). ");
  system("pause");
}

int read_integer(FILE *file)
{
  int result = 0;
  fscanf(file, "%d", &result);
  return result;
}

void store_integer(FILE *file, int value)
{
  fprintf(file, "%d", value);
}

int greatest_common_divisor(int a, int b)
{
  int number1 = abs(a);
  int number2 = abs(b);
  int remainder;
  while (1)
  {
    remainder = number1 % number2;
    if (remainder == 0) break;
    number1 = number2;
    number2 = remainder;
  }
  return number2;
}

void task3(void)
{
  FILE *input_file = fopen("data.txt", "r");
  int a = read_integer(input_file);
  int b = read_integer(input_file);
  fclose(input_file);
  int gcd = greatest_common_divisor(a, b);
  FILE *output_file = fopen("output.txt", "w");
  store_integer(output_file, gcd);
  fclose(output_file);
  printf("task 3 done (check output.txt). ");
  system("pause");
}

void task4(void)
{
  FILE *data_file = fopen("data.txt", "r");
  double value = 0;
  fscanf(data_file, "%lf", &value);
  double highest = value, lowest = value;
  for (; !feof(data_file); )
  {
    fscanf(data_file, "%lf", &value);
    if (value > highest) highest = value;
    if (value < lowest) lowest = value;
  }
  fclose(data_file);
  printf("highest = %lf\nlowest = %lf\n", highest, lowest);
}

int main(void)
{
  task1();
  task2();
  task3();
  task4();
  return 0;
}
