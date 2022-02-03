#include "calorie.h"

int main(void)
{
  printf("Calorie Calculator\n");

  FILE *infile = fopen("input.txt", "r");

  double age_in_years = read_double(infile);
  int gender = read_integer(infile);
  double weight_in_pounds = read_double(infile);
  double height_in_feet = read_double(infile);

  fclose(infile);

  int activity_level = get_activity_level();
  double bmr = calculate_bmr(gender, weight_in_pounds, height_in_feet, age_in_years);
  double calories = calculate_caloric_intake(bmr, activity_level);

  display_calories(calories);

  return 0;
}
