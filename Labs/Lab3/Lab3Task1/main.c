#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

/* Prompts the user for weight in pounds, and returns the weight */
double get_weight(void)
{
  double weight = 0;
  printf("Enter weight in pounds: ");
  scanf("%lf", &weight);
  return weight;
}

/* Prompts the user for height in feet, and returns the height */
double get_height(void)
{
  double height = 0;
  printf("Enter height in feet: ");
  scanf("%lf", &height);
  return height;
}

/* Converts the height of the user from feet to inches, and returns the height in inches */
double convert_feet_to_inches(double height_in_feet)
{
  return height_in_feet * 12;
}

/* Evaluates the BMI based on weight in pounds and height in inches, and returns the BMI */
double calculate_bmi(double weight_in_pounds, double height_in_feet)
{
  double height_in_inches = convert_feet_to_inches(height_in_feet);
  return (weight_in_pounds / pow(height_in_inches, 2)) * 703;
}

/* CUSTOM: Display the word that indicates the BMI's level */
char* get_indicator(double bmi)
{
  if (bmi < 18) return "underweight";
  else if (bmi < 25) return "healthy";
  else if (bmi < 30) return "overweight";
  else return "obese";
}

/* Display the resultant BMI value to the tenths place
/* CUSTOM: Also display the BMI indicator */
void display_bmi(double bmi)
{
  char* indicator = get_indicator(bmi);
  printf("BMI: %.1lf - %s\n", bmi, indicator);
}

int main(void)
{
  printf("TASK 1: BMI calculator\n");

  double weight_in_pounds = get_weight();
  double height_in_feet = get_height();
  double bmi = calculate_bmi(weight_in_pounds, height_in_feet);

  display_bmi(bmi);

  return 0;
}
