#include <stdio.h>
#include <math.h>

#define FIRST_YEAR 1984

void revenue(int t, double *R)
{
  *R = 203.265 * pow(1.071, (double)t);
}

void predict(int value, int *year)
{
  FILE *outputFile = fopen("task2output.txt", "w");
  int yearIncrementor = 0;
  double revenueCheck = 0;

  while (1)
  {
    // Get the revenue of the year
    revenue(yearIncrementor, &revenueCheck);
    
    // Output the year and its revenue to the file
    fprintf(outputFile, "%d: %lf\n", yearIncrementor + FIRST_YEAR, revenueCheck);
    
    // Stop if we've reached the input value
    if (revenueCheck >= value)
      break;
    
    // Otherwise increment to the next year
    yearIncrementor++;
  }

  fclose(outputFile);
  *year = yearIncrementor + FIRST_YEAR;
}

int main()
{
  int year = 0;
  predict(1000000, &year);

  // FILE *outputFile = fopen("task2output.txt", "w");
  // for (int i = FIRST_YEAR; i <= year; i++)
  // {
  //   double revenueValue = 0;
  //   revenue(i - FIRST_YEAR, &revenueValue);
  //   fprintf(outputFile, "%d: %lf\n", i, revenueValue);
  // }
  // fclose(outputFile);

  return 0;
}
