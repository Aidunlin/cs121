#include "poker.h"

int main()
{
    srand((unsigned int)time(NULL));

    int mainMenuChoice = 0;
    while (mainMenuChoice != 3)
    {
        clearConsole();
        printf("5-CARD-DRAW POKER\n");
        printf("1) Play\n");
        printf("2) Rules\n");
        printf("3) Exit\n");
        scanf("%d", &mainMenuChoice);

        if (mainMenuChoice == 1)
        {
            playGame();
        }
        else if (mainMenuChoice == 2)
        {
            displayRules();
        }
    }

    return 0;
}
