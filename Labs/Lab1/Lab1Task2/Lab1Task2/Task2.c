/***********************************************************
* Programmer: Aidan Linerud
* Class: CptS 121, Fall 2021; Lab Section 15
* Programming Assignment: Lab1Task2
* Date: September 3, 2021
* Description: Perform operations on user-inputted numbers
***********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>



// Add int1 and int2
void task_a1(int num1, int num2)
{
  int sum = num1 + num2;
  printf("Addition: %d + %d = %d\n", num1, num2, sum);
}

// Subtract float1 from float2
void task_a2(double num1, double num2)
{
  double diff = num2 - num1;
  printf("Subtraction: %lf - %lf = %lf\n", num2, num1, diff);
}

// Multiply int1 by float2
void task_a3(int num1, double num2)
{
  int prod = num1 * num2;
  printf("Multiplication: %d * %lf = %d\n", num1, num2, prod);
}

// Divide int1 by int2, getting both integer and FP result
void task_a4(int num1, int num2)
{
  double quot = (double)num1 / num2;
  printf("Division: %d / %d = %d, %lf\n", num1, num2, (int)quot, quot);
}

// Divide int1 by float2, getting both integer and FP result
void task_a5(int num1, double num2)
{
  double quot = num1 / num2;
  printf("Division 2: %d / %lf = %d, %lf\n", num1, num2, (int)quot, quot);
}

// Divide float-casted int1 by int2
void task_a6(int num1, int num2)
{
  int quot = (double)num1 / num2;
  printf("Division 3: %d / %d = %lf\n", num1, num2, quot);
}

// Mod float1 by float2
void task_a7(double num1, double num2)
{
  int mod = (int)num1 % (int)num2;
  printf("Mod: %lf mod %lf = %d\n", num1, num2, mod);
}

// Check if int1 and int2 are even/odd
void task_a8(int num1, int num2)
{
  int check1 = num1 % 2;
  int check2 = num2 % 2;
  printf("Checks: %d is %d, %d is %d\n", num1, check1, num2, check2);
}


// Various math operations
void task_a(void)
{
  printf("\nVarious math operations\n");

  int int1, int2;
  double float1, float2;

  printf("Enter two integer values: ");
  scanf("%d%d", &int1, &int2);

  printf("Enter two floating-point values: ");
  scanf("%lf%lf", &float1, &float2);

  task_a1(int1, int2);
  task_a2(float1, float2);
  task_a3(int1, float2);
  task_a4(int1, int2);
  task_a5(int1, float2);
  task_a6(int1, int2);
  task_a7(float1, float2);
  task_a8(int1, int2);
}



// Ohm's law
void task_b(void)
{
  printf("\nOhm's law\n");

  int voltage, current, resistance;

  printf("Enter the current value: ");
  scanf("%d", &current);

  printf("Enter the resistance value: ");
  scanf("%d", &resistance);

  // Ohm's law: V = IR
  voltage = current * resistance;
  printf("Voltage: %d\n", voltage);
}


// Joule's law
void task_c(void)
{
  printf("\nJoule's law\n");

  int power, voltage, resistance;

  printf("Enter the voltage value: ");
  scanf("%d", &voltage);

  printf("Enter the resistance value: ");
  scanf("%d", &resistance);

  // Joule's law: P = (V^2)/R
  power = pow(voltage, 2) / resistance;
  printf("Power: %d\n", power);
}


// Third-order polynomial
void task_d(void)
{
  printf("\nThird-order polynomial\n");

  int y, x, a, b, c, d;
  double part_a, part_b, part_c, part_d;

  printf("Enter the value for x: ");
  scanf("%d", &x);

  printf("Enter the value for a: ");
  scanf("%d", &a);

  printf("Enter the value for b: ");
  scanf("%d", &b);

  printf("Enter the value for c: ");
  scanf("%d", &c);

  printf("Enter the value for d: ");
  scanf("%d", &d);

  // Third-order contains four parts
  part_a = 3 * a * pow(x, 3);
  part_b = ((double)1 / 4) * b * pow(x, 2);
  part_c = 10 * c * x;
  part_d = -5 * d;

  y = part_a + part_b + part_c + part_d;
  printf("y: %d\n", y);
}


// Circle magic
void task_e(void)
{
  printf("\nCircle magic\n");

  const double PI = 3.14159265;
  double circumference, radius;

  printf("Enter the radius: ");
  scanf("%lf", &radius);

  circumference = 2 * PI * radius;
  printf("Circumference: %lf\n", circumference);
}



int main(void)
{
  printf("Welcome to Task 2\n");

  task_a();
  // task_b();
  // task_c();
  // task_d();
  // task_e();

  return 0;
}
