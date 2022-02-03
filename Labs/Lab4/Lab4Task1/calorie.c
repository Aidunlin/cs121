#include "calorie.h"

int get_activity_level(void)
{
  int choice = 0;
  printf("Activity levels:\n");
  printf("0. Sedentary (little to no exercise)\n");
  printf("1. Low activity\n");
  printf("2. Moderate activity\n");
  printf("3. High activity\n");
  printf("4. Extra activity\n");
  printf("What's your activity level? (0-4) ");
  scanf("%d", &choice);
  return choice;
}

double calculate_bmr(int gender, double weight_in_pounds, double height_in_feet, double age_in_years)
{
  double height_in_inches = height_in_feet * 12;
  if (gender == MAN)
  {
    return 66 + (6.23 * weight_in_pounds) + (12.7 * height_in_inches) - (6.8 * age_in_years);
  }
  else if (gender == WOMAN)
  {
    return 655 + (4.35 * weight_in_pounds) + (4.7 * height_in_inches) - (4.7 * age_in_years);
  }
  return 0;
}

double calculate_caloric_intake(double bmr, int activity_level)
{
  if (activity_level == SEDENTARY)
  {
    return bmr * 1.2;
  }
  else if (activity_level == LOW)
  {
    return bmr * 1.375;
  }
  else if (activity_level == MODERATE)
  {
    return bmr * 1.55;
  }
  else if (activity_level == HIGH)
  {
    return bmr * 1.725;
  }
  else if (activity_level == EXTRA)
  {
    return bmr * 1.9;
  }
  return 0;
}

double read_double(FILE *file)
{
  double result = 0;
  fscanf(file, "%lf", &result);
  return result;
}

int read_integer(FILE *file)
{
  int result = 0;
  fscanf(file, "%d", &result);
  return result;
}

void display_calories(double calories)
{
  printf("Total daily caloric intake: %.1lf\n", calories);
}
