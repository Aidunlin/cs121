#include <stdio.h>
#include <stdlib.h>

#define MAX_INCORRECT_GUESSES 10
#define WORD_SIZE 5

int main()
{
  char word[WORD_SIZE + 1] = "hello";
  char guessed[WORD_SIZE + 1] = "*****";

  int incorrectGuesses = 0;
  while (incorrectGuesses < MAX_INCORRECT_GUESSES)
  {
    system("cls");
    char guess = '\0';
    printf("%s\n> ", guessed);
    scanf(" %c", &guess);

    // Check if player's guess is incorrect

    int isGuessCorrect = 0;
    for (int i = 0; i < WORD_SIZE; i++)
    {
      if (word[i] == guess)
      {
        isGuessCorrect = 1;
        guessed[i] = word[i];
      }
    }
    if (!isGuessCorrect)
    {
      incorrectGuesses++;
    }

    // Check if player has completely guessed word

    int isPlayerWon = 1;
    for (int i = 0; i < WORD_SIZE; i++)
    {
      if (word[i] != guessed[i])
      {
        isPlayerWon = 0;
        break;
      }
    }
    if (isPlayerWon)
    {
      break;
    }
  }

  // Print results

  system("cls");
  printf("It was '%s'\n", word);
  if (incorrectGuesses >= MAX_INCORRECT_GUESSES)
  {
    printf("YOU LOSE!\n");
  }
  else
  {
    printf("YOU WIN!\n");
  }
  printf("Incorrect guesses: %d/%d\n", incorrectGuesses, MAX_INCORRECT_GUESSES);

  return 0;
}

/*
  Write an interactive program that plays a game of hangman.
  Store the word to be guessed in successive elements of an array of individual characters called word (note: this is not a string!).
  The player must guess the letters belonging to word.
  The program should terminate when either all letters have been guessed correctly (the player wins),
  or a specified number of incorrect guesses have been made (the computer wins).
  Hint: use another array, guessed, to keep track of the solution so far.
  Initialize all elements of guessed to the '*' symbol.
  Each time a letter in word is guessed, replace the corresponding '*' in guessed with that letter.
*/
