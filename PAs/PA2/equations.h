/***********************************************************
* Programmer: Aidan Linerud
* Class: CptS 121, Fall 2021
* Programming Assignment: PA 2
* Date: September 13, 2021
* Description: Perform various equations on user inputs,
*   now with fancy-shmancy 3-file structure and functions
***********************************************************/

// Guard code
#ifndef EQUATIONS_H
#define EQUATIONS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

/* Calculates total series resistance */
int calculate_series_resistance(int r1, int r2, int r3);

/* Calculates total sales tax */
double calculate_total_sales_tax(double sales_tax_rate, double item_cost);

/* Calculates right rectangular pyramid volume */
double calculate_volume_pyramid(double l, double w, double h);

/* Calculates parallel resistance */
double calculate_parallel_resistance(int r1, int r2, int r3);

/* Encodes character */
char encode_character(char plain_char, int shift);

/* Calculates distance between two points */
double calculate_distance_between_points(double x1, double y1, double x2, double y2);

/* 
 Evaluates a general equation
 * Returns inf if parameter 'a' is not odd
*/
double evaluate_general_equation(double x, double y, double z, int a);

#endif
