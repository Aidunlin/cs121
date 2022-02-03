/***********************************************************
* Programmer: Aidan Linerud
* Class: CptS 121, Fall 2021
* Programming Assignment: PA 1
* Date: September 8, 2021
* Description: Perform various equations on user inputs
***********************************************************/

#include <stdio.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265359

/* Total series resistance */
void equation1()
{
  int R1, R2, R3, series_resistance;

  printf("\nTotal series resistance\n");

  printf("Enter resistor 1 value: ");
  scanf("%d", &R1);

  printf("Enter resistor 2 value: ");
  scanf("%d", &R2);

  printf("Enter resistor 3 value: ");
  scanf("%d", &R3);

  series_resistance = R1 + R2 + R3;
  printf("Total series resistance: %d\n", series_resistance);
}

/* Sales tax */
void equation2()
{
  double sales_tax_rate, item_cost, total_sales_tax;

  printf("\nSales tax\n");

  printf("Enter tax rate: ");
  scanf("%lf", &sales_tax_rate);

  printf("Enter item cost: ");
  scanf("%lf", &item_cost);

  total_sales_tax = sales_tax_rate * item_cost;
  printf("Sales tax: %lf\n", total_sales_tax);
}

/* Volume of a right rectangular pyramid */
void equation3()
{
  double l, w, h, volume_pyramid;

  printf("\nVolume of a right rectangular pyramid\n");

  printf("Enter length of base: ");
  scanf("%lf", &l);

  printf("Enter width of base: ");
  scanf("%lf", &w);

  printf("Enter height of pyramid: ");
  scanf("%lf", &h);

  volume_pyramid = (l * w * h) / 3;
  printf("Volume of a right rectangular pyramid: %lf\n", volume_pyramid);
}

/* Total parallel resistance */
void equation4()
{
  int R1, R2, R3;
  double parallel_resistance;

  printf("\nTotal parallel resistance\n");

  printf("Enter resistor 1 value: ");
  scanf("%d", &R1);

  printf("Enter resistor 2 value: ");
  scanf("%d", &R2);

  printf("Enter resistor 3 value: ");
  scanf("%d", &R3);

  parallel_resistance = 1 / (1 / (double)R1 + 1 / (double)R2 + 1 / (double)R3);
  printf("Total parallel resistance: %lf\n", parallel_resistance);
}

/* Character encoding */
void equation5()
{
  char plaintext_character, encoded_character;
  int shift;

  printf("\nCharacter encoding\n");

  printf("Enter plaintext character: ");
  scanf(" %c", &plaintext_character); // space before %c to prevent plaintext_character storing newline

  printf("Enter shift value: ");
  scanf("%d", &shift);

  encoded_character = (plaintext_character - 'a') + 'A' - shift;
  printf("Character encoding: %c\n", encoded_character);
}

/* Distance between two points */
void equation6()
{
  double x1, y1, x2, y2, distance;

  printf("\nDistance between two points\n");

  printf("Enter x1 value: ");
  scanf("%lf", &x1);

  printf("Enter y1 value: ");
  scanf("%lf", &y1);

  printf("Enter x2 value: ");
  scanf("%lf", &x2);

  printf("Enter y2 value: ");
  scanf("%lf", &y2);

  distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  printf("Distance between two points: %lf\n", distance);
}

/* General equation */
void equation7()
{
  int a;
  double x, y, z;

  printf("\nGeneral equation\n");

  printf("Enter value for a: ");
  scanf("%d", &a);

  printf("Enter value for x: ");
  scanf("%lf", &x);

  printf("Enter value for y: ");
  scanf("%lf", &y);

  printf("Enter value for z: ");
  scanf("%lf", &z);

  y = y / ((double)3 / 17) - z + x / (a % 2) + PI;
  printf("General equation: %lf\n", y);
}

int main(void)
{
  printf("PA 1 - Aidan Linerud\n");

  // Comment/uncomment out these functions to choose what to run
  equation1();
  equation2();
  equation3();
  equation4();
  equation5();
  equation6();
  equation7();
  
  return 0;
}
