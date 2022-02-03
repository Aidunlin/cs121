/*
  Programmer: Aidan Linerud
  Assignment: PA 4
  Description: Implements the game of Craps
*/

#include "craps.h"

int main(void)
{
  srand((unsigned int) time(NULL));
  system("cls");
  printf("Welcome to Craps!\n");
  double initial_balance = get_valid_bank_balance();
  double balance = initial_balance;
  while (balance > 0)
  { // game loop
    system("cls");
    print_menu(balance);
    int menu_choice = get_menu_choice();
    if (menu_choice == 1)
    {
      double wager = get_valid_wager_amount(balance);
      int number_rolls = 0;
      int point = 0;
      int sum = 0;
      int result = NEITHER;
      while (result == NEITHER)
      { // roll loop
        int die1 = roll_die();
        int die2 = roll_die();
        sum = calculate_sum_dice(die1, die2);
        system("cls");
        print_roll_numbers(number_rolls + 1, die1, die2, sum);
        result = get_roll_result(sum, number_rolls, point);
        balance = adjust_bank_balance(balance, wager, result);
        chatter_messages(number_rolls, result, initial_balance, balance);
        ++number_rolls;
        point = sum;
        system("pause");
      } // end roll loop
    }
    else if (menu_choice == 2)
    {
      print_game_rules();
    }
    else if (menu_choice == 3)
    {
      printf("Goodbye!\n");
      break;
    }
  } // end game loop
  return 0;
}
