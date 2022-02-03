/***********************************************************
* Programmer: Aidan Linerud
* Class: CptS 121, Fall 2021
* Programming Assignment: PA 2
* Date: September 13, 2021
* Description: Perform various equations on user inputs,
*   now with fancy-shmancy 3-file structure and functions
***********************************************************/

#include "equations.h"

/* Calculates total series resistance */
int calculate_series_resistance(int r1, int r2, int r3)
{
	return r1 + r2 + r3;
}

/* Calculates total sales tax */
double calculate_total_sales_tax(double sales_tax_rate, double item_cost)
{
	return sales_tax_rate * item_cost;
}

/* Calculates right rectangular pyramid volume */
double calculate_volume_pyramid(double l, double w, double h)
{
	return (l * w * h) / 3;
}

/* Calculates parallel resistance */
double calculate_parallel_resistance(int r1, int r2, int r3)
{
	// Parameters are type-casted to prevent imprecise integer division
	return 1 / ( 1 / (double)r1 + 1 / (double)r2 + 1 / (double)r3 );
}

/* Encodes character */
char encode_character(char plain_char, int shift)
{
	return (plain_char - 'a') + 'A' - shift;
}

/* Calculates distance between two points */
double calculate_distance_between_points(double x1, double y1, double x2, double y2)
{
	return sqrt( pow(x1 - x2, 2) + pow(y1 - y2, 2) );
}

/*
 Evaluates a general equation
 * Returns inf if parameter 'a' is not odd
*/
double evaluate_general_equation(double x, double y, double z, int a)
{
	// Force double division for precision
	return y / ((double)3 / 17) - z + x / (a % 2) + PI;
}
