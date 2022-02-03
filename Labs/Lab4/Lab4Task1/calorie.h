#ifndef CALORIE_H
#define CALORIE_H

#define _CRT_SECURE_NO_WARNINGS

#define SEDENTARY 0
#define LOW 1
#define MODERATE 2
#define HIGH 3
#define EXTRA 4

#define MAN 0
#define WOMAN 1

#include <stdio.h>

int get_activity_level(void);
double calculate_bmr(int gender, double weight_in_pounds, double height_in_feet, double age_in_years);
double calculate_caloric_intake(double bmr, int activity_level);

double read_double(FILE *file);
int read_integer(FILE *file);

void display_calories(double calories);

#endif
