/***********************************************************
* Programmer: Aidan Linerud
* Class: CptS 121, Fall 2021
* Programming Assignment: PA 2
* Date: September 13, 2021
* Description: Perform various equations on user inputs,
*   now with fancy-shmancy 3-file structure and functions
***********************************************************/

/* --- EXTRA NOTE ---
  I use functions in main.c here to easily test specific equations.
  The actual equation functions are declared and defined in the correct files,
  but I prefer this method of compartmentalizing each part of the assignment.
*/

#include "equations.h"

/* 1) Series resistance */
void equation1(void)
{
  int r1, r2, r3, result;
  printf("\n1) Series resistance\n");

  printf("Enter 3 resistance values: ");
  scanf("%d%d%d", &r1, &r2, &r3);

  result = calculate_series_resistance(r1, r2, r3);
  printf("Series resistance: %d + %d + %d = %d\n", r1, r2, r3, result);
}

/* 2) Sales tax */
void equation2(void)
{
  double sales_tax_rate, item_cost, result;
  printf("\n2) Sales tax\n");

  printf("Enter sales tax rate THEN item cost: ");
  scanf("%lf%lf", &sales_tax_rate, &item_cost);

  result = calculate_total_sales_tax(sales_tax_rate, item_cost);
  printf("Sales tax: %.3lf * %.3lf = %.3lf\n", sales_tax_rate, item_cost, result);
}

/* 3) Pyramid volume */
void equation3(void)
{
  double l, w, h, result;
  printf("\n3) Pyramid volume\n");

  printf("Enter pyramid length, width, THEN height: ");
  scanf("%lf%lf%lf", &l, &w, &h);

  result = calculate_volume_pyramid(l, w, h);
  printf("Pyramid volume: (%.3lf * %.3lf * %.3lf) / 3 = %.3lf\n", l, w, h, result);
}

/* 4) Parallel resistance */
void equation4(void)
{
  int r1, r2, r3;
  double result;
  printf("\n4) Parallel resistance\n");

  printf("Enter 3 resistance values: ");
  scanf("%d%d%d", &r1, &r2, &r3);

  result = calculate_parallel_resistance(r1, r2, r3);
  printf("Parallel resistance: 1 / ( 1 / %d + 1 / %d + 1 / %d ) = %.3lf\n", r1, r2, r3, result);
}

/* 5) Character encoding */
void equation5(void)
{
  char plain_char, result;
  int shift;
  printf("\n5) Character encoding\n");

  printf("Enter plaintext character THEN shift value: ");
  scanf(" %c %d", &plain_char, &shift);

  result = encode_character(plain_char, shift);
  printf("Character encoding: ('%c' - 'a') + 'A' - %d = '%c'\n", plain_char, shift, result);
}

/* 6) Distance between points */
void equation6(void)
{
  double x1, y1, x2, y2, result;
  printf("\n6) Distance between points\n");

  printf("Enter point 1's x and y coords, THEN point 2's x and y coords: ");
  scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);

  result = calculate_distance_between_points(x1, y1, x2, y2);
  printf("Distance between two points: square root of ( (%.3lf - %.3lf)^2 + (%.3lf - %.3lf)^2 ) = %.3lf\n", x1, y2, x2, y2, result);
}

/* 7) General equation */
void equation7(void)
{
  double x, y, z, result;
  int a;
  printf("\n7) General equation\n");

  printf("Enter x, y, z, THEN a: ");
  scanf("%lf%lf%lf%d", &x, &y, &z, &a);

  result = evaluate_general_equation(x, y, z, a);
  printf("General equation: %.3lf / (3/17) - %.3lf + %.3lf / (%d %% 2) + pi = %.3lf\n", x, y, z, a, result);
}

/* Sequentially runs every equation evaluator */
int main(void)
{
  printf("PA 2 by Aidan Linerud\n");

  // If I want to test a specific equation,
  // I can just toggle comment the ones I don't want to test
  equation1();
  equation2();
  equation3();
  equation4();
  equation5();
  equation6();
  equation7();

  printf("\nGoodbye!\n");
};
