/* Programmer: Aidan Linerud
Assignment: PA 6
Description: Simulates the game of Battleship */

#include "battleship.h"

int main()
{
    seedRand();
    int menuInput = MENU_NONE;
    while (1)
    {
        clearConsole();
        puts("BATTLESHIP");
        puts("1) Play");
        puts("2) Rules");
        puts("3) Exit");
        menuInput = getIntInput();
        if (menuInput == MENU_PLAY)
        {
            Player human = initPlayer();
            Player computer = initPlayer();
            int setupResult = setupGame(&human, &computer);
            if (setupResult == SETUP_QUIT)
            {
                continue;
            }
            int gameResult = playGame(&human, &computer);
            pauseConsole();
            endGame(gameResult, &human, &computer);
            pauseConsole();
        }
        else if (menuInput == MENU_RULES)
        {
            clearConsole();
            printFile("rules.txt");
            pauseConsole();
        }
        else if (menuInput == MENU_EXIT)
        {
            puts("Goodbye!");
            break;
        }
    }
    return 0;
}
