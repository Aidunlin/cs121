/*
  Programmer: Aidan Linerud
  Assignment: PA 4
  Description: Implements the game of Craps
*/

#include "craps.h"

/*
  Prints the rules of "craps" from a text file
  Pre: rules.txt should exist
  Post: PAUSE is called
*/
void print_game_rules(void)
{
  system("cls");
  FILE *rules_file = fopen("rules.txt", "r");
  char c = '\0';
  while (!feof(rules_file))
  {
    fscanf(rules_file, "%c", &c);
    printf("%c", c);
  }
  fclose(rules_file);
  system("pause");
}

/*
  Prints the player's balance and menu options
  Pre: none
  Post: none
*/
void print_menu(double balance)
{
  printf("Bank balance: $%.2lf\n", balance);
  printf("1) Play a round\n");
  printf("2) View the rules\n");
  printf("3) Quit\n");
}

/*
  Prints the results of the roll
  Pre: none
  Post: none
*/
void print_roll_numbers(int roll_number, int die1, int die2, int sum)
{
  printf("Roll %d\n", roll_number);
  printf("- You rolled: %d, %d\n", die1, die2);
  printf("- Sum: %d\n", sum);
}

/*
  Gets the user's menu choice
  Returns: user's choice as an int
  Pre: none
  Post: none
*/
int get_menu_choice(void)
{
  int menu_choice;
  printf("> ");
  scanf("%d", &menu_choice);
  return menu_choice;
}

/*
  Prompts for an initial bank balance
  Returns: bank balance as a double
  Pre: none
  Post: none
*/
double get_bank_balance(void)
{
  double balance = 0;
  printf("To play, enter an initial bank balance:\n> ");
  scanf("%lf", &balance);
  return balance;
}

/*
  Repeatedly prompts for an initial bank balance
  Returs: valid bank balance as a double
  Pre: none
  Post: none
*/
double get_valid_bank_balance(void)
{
  double balance = 0;
  do
  {
    balance = get_bank_balance();
  } while (balance <= 0);
  return balance;
}

/*
  Prompts for a wager
  Returns: wager as a double
  Pre: none
  Post: none
*/
double get_wager_amount(void)
{
  double wager = 0;
  printf("Enter a wager:\n> ");
  scanf("%lf", &wager);
  return wager;
}

/*
  Checks if a wager is within the player's balance
  Returns: (as an int)
    - 1 if wager is greater than 0 and is at most balance
    - 0 otherwise
  Pre: none
  Post: none
*/
int check_wager_amount(double wager, double balance)
{
  return wager > 0 && wager <= balance;
}

/*
  Repeatedly prompts for a wager
  Returns: valid wager as a double
  Pre: none
  Post: none
*/
double get_valid_wager_amount(double balance)
{
  double wager = 0;
  do
  {
    wager = get_wager_amount();
  } while (check_wager_amount(wager, balance) == 0);
  return wager;
}

/*
  Rolls one die
  Returns: a random integer in [1, 6]
  Pre: srand(time(0)) should be called to generate a new seed
  Post: none
*/
int roll_die(void)
{
  return rand() % 6 + 1;
}

/*
  Returns: the sum of the values of two dice as an int
  Pre: none
  Post: none
*/
int calculate_sum_dice(int die1_value, int die2_value)
{
  return die1_value + die2_value;
}

/*
  Determines the result of the first dice roll
  Returns: (as an int)
    - 1 if the dice sum is 7 or 11 (player wins)
    - 0 if the dice sum is 2, 3, or 12 (player loses)
    - -1 otherwise
  Pre: none
  Post: none
*/
int is_win_loss_or_point(int sum_dice)
{
  if (sum_dice == 7 || sum_dice == 11)
    return WINS;
  else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
    return LOSES;
  else
    return NEITHER;
}

/*
  Determines the result of any successive dice roll
  Returns: (as an int)
    - 1 if the dice sum equals the point value (player wins)
    - 0 if the dice sum equals 7 (player loses)
    - -1 otherwise
  Pre: none
  Post: none
*/
int is_point_loss_or_neither(int sum_dice, int point_value)
{
  if (sum_dice == point_value)
    return WINS;
  else if (sum_dice == 7)
    return LOSES;
  else
    return NEITHER;
}

/*
  Determines the result of a dice roll
  Returns: (as an int)
    - 1 if the player wins
    - 0 if the player loses
    - -1 otherwise
  Pre: none
  Post: none
*/
int get_roll_result(int sum, int number_rolls, int point)
{
  if (number_rolls == 0)
    return is_win_loss_or_point(sum);
  else
    return is_point_loss_or_neither(sum, point);
}

/*
  Adjusts the bank balance depending on whether the player won, lost, or neither
  Retuns: adjusted bank balance as a double
  Pre: none
  Post: none
*/
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
{
  if (add_or_subtract == WINS)
    return bank_balance + wager_amount;
  else if (add_or_subtract == LOSES)
    return bank_balance - wager_amount;
  else
    return bank_balance;
}

/*
  Prints appropriate messages depending on the game's state
  Pre: none
  Post: none
*/
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{
  if (win_loss_neither == WINS)
  {
    printf("You won!\n");
    printf("Balance: $%.2lf\n", current_bank_balance);
  }
  else if (win_loss_neither == LOSES)
  {
    if (current_bank_balance <= 0)
      printf("You've busted! GAME OVER\n");
    else
      printf("You lost!\n");
    printf("Balance: $%.2lf\n", current_bank_balance);
  }
  else
  {
    printf("Rerolling...\n");
  }
}
