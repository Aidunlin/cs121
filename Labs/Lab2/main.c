/***********************************************************
* Programmer: Aidan Linerud
* Class: CptS 121, Fall 2021
* Programming Assignment: Lab 2
* Date: 9/10/21
* Description: Bisecting, BMI, and BSC
***********************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

/* Perpendicular bisector */
void task1()
{
  printf("\nPerpendicular bisector\n");

  // Prompt user for coordinates of two points
  double x1, y1, x2, y2;
  printf("\nEnter coordinates for point 1: ");
  scanf("%lf%lf", &x1, &y1);
  printf("\nEnter coordinates for point 2: ");
  scanf("%lf%lf", &x2, &y2);

  // Compute slope between points
  double slope = (y2 - y1) / (x2 - x1);

  // Compute midpoint coordinates
  double x_mid = (x1 + x2) / 2;
  double y_mid = (y1 + y2) / 2;

  // Compute slope of perpendicular bisector
  double bisector_slope = -1 / slope;

  // Compute y-intercept of perpendicular bisector
  double y_intercept = y_mid - bisector_slope * x_mid;

  // Output labels of original two points and perpendicular bisector equation
  printf("\nOriginal points: (%lf, %lf) and (%lf, %lf)\n", x1, y1, x2, y2);
  printf("\nPerpendicular bisector: y = %lfx + %lf\n", bisector_slope, y_intercept);
}


/* Body mass index */
void task2()
{
  printf("\nBMI calculator\n");

  // Prompt user for weight (lb) and height (ft)
  double weight, height;
  printf("\nEnter weight (lb) and height (ft): ");
  scanf("%lf%lf", &weight, &height);

  // Convert height to inches
  double height_inches = height * 12;

  // Calculate BMI
  double bmi = (weight / pow(height_inches, 2)) * 703;

  // Output BMI
  printf("\nBMI: %lf\n", bmi);
}


/* BCS scores */
void task3()
{
  printf("\nBCS scores\n");

  // Prompt user for harris poll, coaches poll, and computer ranking
  int harris_input, coaches_input;
  double computer_input;
  printf("\nEnter the team's score for the Harris Poll (between 1 and 2850): ");
  scanf("%d", &harris_input);
  printf("\nEnter the team's score for the Coaches Poll (between 1 and 1475): ");
  scanf("%d", &coaches_input);
  printf("\nEnter the team's computer ranking (between 0 and 1): ");
  scanf("%lf", &computer_input);

  // Calculate polls
  double harris_poll = (double)harris_input / 2850;
  double coaches_poll = (double)coaches_input / 1475;

  // Output results of polls
  printf("\nHarris Poll: %lf, Coaches Poll: %lf\n", harris_poll, coaches_poll);

  // Compute BCS score
  double bcs = (harris_poll + coaches_poll + computer_input) / 3;

  // Display BCS total
  printf("\nBCS Score: %lf\n", bcs);
}


int main(void)
{
  printf("Lab 2\n");

  task1();
  task2();
  task3();

  return 0;
}
