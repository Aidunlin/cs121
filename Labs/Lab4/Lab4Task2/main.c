#include "bonus.h"

int main(void)
{
  double total_bonus = 0;
  char response = '\0';

  printf("End-season bonus\n");

  total_bonus += check_and_get_bonus("All-Star Game appearance ($25,000)", 25000);
  total_bonus += check_and_get_bonus("Regular season MVP ($75,000)", 75000);
  total_bonus += check_and_get_bonus("World Series MVP ($100,000)", 100000);
  total_bonus += check_and_get_bonus("Gold Glove award ($50,000)", 50000);
  total_bonus += check_and_get_bonus("Silver Slugger award ($35,000)", 35000);
  total_bonus += check_and_get_bonus("Home run champ ($25,000)", 25000);
  total_bonus += check_and_get_bonus("Batting average champ ($25,000)", 25000);

  printf("Total bonus: $%.0lf\n", total_bonus);

  return 0;
}
