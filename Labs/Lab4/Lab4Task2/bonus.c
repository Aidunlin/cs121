#include "bonus.h"

double check_and_get_bonus(char * name, double amount)
{
  char response = '\0';
  printf("%s ? (y/n) ", name);
  scanf(" %c", &response);
  if (response == 'y')
  {
    return amount;
  }
  return 0;
}
