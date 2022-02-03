#ifndef CALC_H
#define CALC_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

double read_double(FILE *infile);
double get_average(double num1, double num2, double num3, double num4, double num5);
double get_high(double num1, double num2, double num3, double num4, double num5);
double get_low(double num1, double num2, double num3, double num4, double num5);
void display_numbers(double num1, double num2, double num3, double num4, double num5);
void display_menu(void);
double do_operation(int choice);

#endif
