/*
  Programmer: Aidan Linerud
  Assignment: PA 4
  Description: Implements the game of Craps
*/

#ifndef CRAPS_H
#define CRAPS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WINS 1
#define LOSES 0
#define NEITHER -1

/*
  Prints the rules of "craps" from a text file
  Pre: rules.txt should exist
  Post: PAUSE is called
*/
void print_game_rules(void);

/*
  Prints the player's balance and menu options
  Pre: none
  Post: none
*/
void print_menu(double balance);

/*
  Prints the results of the roll
  Pre: none
  Post: none
*/
void print_roll_numbers(int roll_number, int die1, int die2, int sum);

/*
  Gets the user's menu choice
  Returns: user's choice as an int
  Pre: none
  Post: none
*/
int get_menu_choice(void);

/*
  Prompts for an initial bank balance
  Returns: bank balance as a double
  Pre: none
  Post: none
*/
double get_bank_balance(void);

/*
  Repeatedly prompts for an initial bank balance
  Returs: valid bank balance as a double
  Pre: none
  Post: none
*/
double get_valid_bank_balance(void);

/*
  Prompts for a wager
  Returns: wager as a double
  Pre: none
  Post: none
*/
double get_wager_amount(void);

/*
  Checks if a wager is within the player's balance
  Returns: (as an int)
    - 1 if wager is greater than 0 and is at most balance
    - 0 otherwise
  Pre: none
  Post: none
*/
int check_wager_amount(double wager, double balance);

/*
  Repeatedly prompts for a wager
  Returns: valid wager as a double
  Pre: none
  Post: none
*/
double get_valid_wager_amount(double balance);

/*
  Rolls one die
  Returns: a random integer in [1, 6]
  Pre: srand(time(0)) should be called to generate a new seed
  Post: none
*/
int roll_die(void);

/*
  Returns: the sum of the values of two dice as an int
  Pre: none
  Post: none
*/
int calculate_sum_dice(int die1_value, int die2_value);

/*
  Determines the result of the first dice roll
  Returns: (as an int)
    - 1 if the dice sum is 7 or 11 (player wins)
    - 0 if the dice sum is 2, 3, or 12 (player loses)
    - -1 otherwise
  Pre: none
  Post: none
*/
int is_win_loss_or_point(int sum_dice);

/*
  Determines the result of any successive dice roll
  Returns: (as an int)
    - 1 if the dice sum equals the point value (player wins)
    - 0 if the dice sum equals 7 (player loses)
    - -1 otherwise
  Pre: none
  Post: none
*/
int is_point_loss_or_neither(int sum_dice, int point_value);

/*
  Determines the result of a dice roll
  Returns: (as an int)
    - 1 if the player wins
    - 0 if the player loses
    - -1 otherwise
  Pre: none
  Post: none
*/
int get_roll_result(int sum, int number_rolls, int point);

/*
  Adjusts the bank balance depending on whether the player won, lost, or neither
  Retuns: adjusted bank balance as a double
  Pre: none
  Post: none
*/
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);

/*
  Prints appropriate messages depending on the game's state
  Pre: none
  Post: none
*/
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);

#endif
