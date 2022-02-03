#include <stdio.h>
#include <math.h>

#define FIRST_RATE 7.99
#define SECOND_RATE 1.99

int readIntFrom(FILE *file)
{
  int result = 0;
  fscanf(file, "%d", &result);
  return result;
}

double readDoubleRom(FILE *file)
{
  double result = 0;
  fscanf(file, "%lf", &result);
  return result;
}

void writeDoubleTo(FILE *file, double value)
{
  fprintf(file, "%.2lf\n", value);
}

void charges(double hours, double *totalCharge, double *averageCostPerHour)
{
  double total = 0;
  if (hours < 10)
  {
    total += FIRST_RATE;
  }
  else
  {
    total += FIRST_RATE;
    total += (hours - 10) * SECOND_RATE;
  }
  *totalCharge = total;
  *averageCostPerHour = total / hours;
}

double roundMoney(double money)
{
  return roundl(money * 100) / 100;
}

int main()
{
  FILE *inputFile = fopen("task1input.txt", "r");
  int month = readIntFrom(inputFile);
  int year = readIntFrom(inputFile);
  int customer = readIntFrom(inputFile);
  double hours = readDoubleRom(inputFile);
  fclose(inputFile);

  double totalCharge = 0;
  double averageCostPerHour = 0;
  charges(hours, &totalCharge, &averageCostPerHour);
  totalCharge = roundMoney(totalCharge);
  averageCostPerHour = roundMoney(averageCostPerHour);

  FILE *outputFile = fopen("task1output.txt", "w");
  writeDoubleTo(outputFile, totalCharge);
  writeDoubleTo(outputFile, averageCostPerHour);
  fclose(outputFile);

  return 0;
}
