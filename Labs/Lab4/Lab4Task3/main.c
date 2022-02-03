#include "calc.h"

int main(void)
{
  FILE *infile = fopen("input.txt", "r");

  double num1 = read_double(infile);
  double num2 = read_double(infile);
  double num3 = read_double(infile);
  double num4 = read_double(infile);
  double num5 = read_double(infile);

  fclose(infile);

  display_numbers(num1, num2, num3, num4, num5);
  printf("\n");
  display_menu();

  int choice = 0;
  scanf("%d", &choice);

  double output = do_operation(choice, num1, num2, num3, num4, num5);
  printf("%lf\n", output);

  return 0;
}
