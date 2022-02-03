/* Programmer: Aidan Linerud
Assignment: PA 6
Description: Simulates the game of Battleship */

#include "battleship.h"

/* Creates and returns a new Stats */
Stats initStats()
{
    Stats stats;
    stats.totalHits = 0;
    stats.totalMisses = 0;
    stats.ratioHitsToMisses = 0.0;
    return stats;
}

/* Initializes a 2D board */
void initBoard(char board[][SIZE_BOARD])
{
    for (int y = 0; y < SIZE_BOARD; y++)
    {
        for (int x = 0; x < SIZE_BOARD; x++)
        {
            board[y][x] = CELL_EMPTY;
        }
    }
}

/* Creates and returns a new Ship */
Ship initShip(char shipCell, char *shipName, int shipSize)
{
    Ship ship;
    ship.cell = shipCell;
    ship.name = shipName;
    ship.size = shipSize;
    ship.hits = 0;
    ship.sunk = FALSE;
    return ship;
}

/* Creates and returns a new Player */
Player initPlayer()
{
    Player player;
    player.stats = initStats();
    initBoard(player.board);
    player.ships[0] = initShip(CELL_CARRIER, "Carrier", SIZE_CARRIER);
    player.ships[1] = initShip(CELL_BATTLESHIP, "Battleship", SIZE_BATTLESHIP);
    player.ships[2] = initShip(CELL_CRUISER, "Cruiser", SIZE_CRUISER);
    player.ships[3] = initShip(CELL_SUBMARINE, "Submarine", SIZE_SUBMARINE);
    player.ships[4] = initShip(CELL_DESTROYER, "Destroyer", SIZE_DESTROYER);
    return player;
}

/* Displays a 2D board */
void displayBoard(char board[][SIZE_BOARD], int hideShips)
{
    printf(" ");
    for (int i = 0; i < SIZE_BOARD; i++)
    {
        printf(" %d", i);
    }
    puts("");
    for (int y = 0; y < SIZE_BOARD; y++)
    {
        printf("%d", y);
        for (int x = 0; x < SIZE_BOARD; x++)
        {
            char cell = board[y][x];
            if (hideShips && cell != CELL_EMPTY && cell != CELL_HIT && cell != CELL_MISS)
            {
                printf(" %c", CELL_EMPTY);
            }
            else
            {
                printf(" %c", cell);
            }
        }
        puts("");
    }
}

/* Iteratively places a ship from a starting location if possible, returns if successful or not */
int placeShipIfValid(char board[][SIZE_BOARD], Ship ship, int axis, int x, int y)
{
    int validPlace = TRUE;
    for (int i = 0; i < ship.size; i++)
    {
        if (axis == AXIS_HORIZONTAL && board[y][x + i] != CELL_EMPTY || axis == AXIS_VERTICAL && board[y + i][x] != CELL_EMPTY)
        {
            validPlace = FALSE;
            break;
        }
    }
    if (validPlace)
    {
        for (int i = 0; i < ship.size; i++)
        {
            if (axis == AXIS_HORIZONTAL)
            {
                board[y][x + i] = ship.cell;
            }
            else if (axis == AXIS_VERTICAL)
            {
                board[y + i][x] = ship.cell;
            }
        }
    }
    return validPlace;
}

/* Asks for Player input to place a ship */
void placeShipManually(char board[][SIZE_BOARD], Ship ship)
{
    int foundPlace = FALSE;
    while (!foundPlace)
    {
        clearConsole();
        puts("SHIP SETUP");
        printf("%s (%d cells)\n", ship.name, ship.size);
        displayBoard(board, SHIPS_SHOW);
        puts("Enter an axis (0 for horizontal, 1 for vertical),");
        puts("then an x and y value that represents the");
        puts("top-most or left-most cell of the ship");
        printf("> ");
        int axis, x, y;
        scanf("%d %d %d", &axis, &x, &y);
        if (axis == AXIS_HORIZONTAL)
        {
            x = clampInt(x, 0, SIZE_BOARD - ship.size);
            y = clampInt(y, 0, SIZE_BOARD - 1);
        }
        else if (axis == AXIS_VERTICAL)
        {
            x = clampInt(x, 0, SIZE_BOARD - 1);
            y = clampInt(y, 0, SIZE_BOARD - ship.size);
        }
        else
        {
            continue;
        }
        foundPlace = placeShipIfValid(board, ship, axis, x, y);
        if (!foundPlace)
        {
            printf("Invalid location at %d, %d!\n", x, y);
            pauseConsole();
        }
    }
}

/* Consecutively place each ship with input from Player */
void placeShipsManually(Player *playerPtr)
{
    for (int i = 0; i < SHIP_COUNT; i++)
    {
        placeShipManually(playerPtr->board, playerPtr->ships[i]);
    }
}

/* Randomly places a ship */
void placeShipRandomly(char board[][SIZE_BOARD], Ship ship)
{
    int foundPlace = FALSE;
    while (!foundPlace)
    {
        int axis = randInt(AXIS_HORIZONTAL, AXIS_VERTICAL);
        int x, y;
        if (axis == AXIS_HORIZONTAL)
        {
            x = randInt(0, SIZE_BOARD - ship.size);
            y = randInt(0, SIZE_BOARD - 1);
        }
        else if (axis == AXIS_VERTICAL)
        {
            x = randInt(0, SIZE_BOARD - 1);
            y = randInt(0, SIZE_BOARD - ship.size);
        }
        else
        {
            continue;
        }
        foundPlace = placeShipIfValid(board, ship, axis, x, y);
    }
}

/* Consecutively places each ship for a Player randomly */
void placeShipsRandomly(Player *playerPtr)
{
    for (int i = 0; i < SHIP_COUNT; i++)
    {
        placeShipRandomly(playerPtr->board, playerPtr->ships[i]);
    }
}

/* Updates ship's hits counter and displays a message */
void hitShip(Ship *shipPtr, int currentPlayer, int x, int y)
{
    FILE *logFile = fopen(LOG_FILE, "a+");
    shipPtr->hits++;
    char *verb = "hit";
    if (shipPtr->hits >= shipPtr->size)
    {
        shipPtr->sunk = TRUE;
        verb = "SUNK";
    }
    if (currentPlayer == PLAYER_HUMAN)
    {
        printf("You %s computer's %s at %d, %d!\n", verb, shipPtr->name, x, y);
        fprintf(logFile, "You %s computer's %s at %d, %d!\n", verb, shipPtr->name, x, y);
    }
    else if (currentPlayer == PLAYER_COMPUTER)
    {
        printf("Computer %s your %s at %d, %d!\n", verb, shipPtr->name, x, y);
        fprintf(logFile, "Computer %s your %s at %d, %d!\n", verb, shipPtr->name, x, y);
    }
    fclose(logFile);
}

/* Determines if a location is a hit/miss, updates the board, returns if location is new or not */
int handleTurn(Player *thisPlayerPtr, Player *otherPlayerPtr, int currentPlayer, int x, int y)
{
    int foundPlace = TRUE;
    if (otherPlayerPtr->board[y][x] == CELL_EMPTY)
    {
        otherPlayerPtr->board[y][x] = CELL_MISS;
        thisPlayerPtr->stats.totalMisses++;
        char *playerName = "You";
        if (currentPlayer == PLAYER_COMPUTER)
        {
            playerName = "Computer";
        }
        printf("%s missed at %d, %d!\n", playerName, x, y);
        FILE *logFile = fopen(LOG_FILE, "a+");
        fprintf(logFile, "%s missed at %d, %d\n", playerName, x, y);
        fclose(logFile);
    }
    else if (otherPlayerPtr->board[y][x] == CELL_HIT || otherPlayerPtr->board[y][x] == CELL_MISS)
    {
        foundPlace = FALSE;
    }
    else
    {
        for (int i = 0; i < SHIP_COUNT; i++)
        {
            if (otherPlayerPtr->board[y][x] == otherPlayerPtr->ships[i].cell)
            {
                otherPlayerPtr->board[y][x] = CELL_HIT;
                thisPlayerPtr->stats.totalHits++;
                hitShip(&otherPlayerPtr->ships[i], currentPlayer, x, y);
                break;
            }
        }
    }
    return foundPlace;
}

/* Asks for Player input to choose a location */
void humanTurn(Player *humanPtr, Player *computerPtr)
{
    int foundPlace = FALSE;
    while (!foundPlace)
    {
        clearConsole();
        puts("Computer's board:");
        displayBoard(computerPtr->board, SHIPS_HIDE);
        puts("Your board:");
        displayBoard(humanPtr->board, SHIPS_SHOW);
        puts("YOUR TURN");
        puts("Enter an x and y value that represents your target");
        printf("> ");
        int x, y;
        scanf("%d %d", &x, &y);
        x = clampInt(x, 0, SIZE_BOARD - 1);
        y = clampInt(y, 0, SIZE_BOARD - 1);
        foundPlace = handleTurn(humanPtr, computerPtr, PLAYER_HUMAN, x, y);
        if (!foundPlace)
        {
            printf("Invalid location at %d, %d!\n", x, y);
        }
    }
}

/* Randomly chooses a location */
void computerTurn(Player *humanPtr, Player *computerPtr)
{
    clearConsole();
    puts("Computer's board:");
    displayBoard(computerPtr->board, SHIPS_HIDE);
    puts("Your board:");
    displayBoard(humanPtr->board, SHIPS_SHOW);
    puts("COMPUTER'S TURN");
    int foundPlace = FALSE;
    while (!foundPlace)
    {
        int x = randInt(0, SIZE_BOARD - 1);
        int y = randInt(0, SIZE_BOARD - 1);
        foundPlace = handleTurn(computerPtr, humanPtr, PLAYER_COMPUTER, x, y);
    }
}

/* Displays the Stats of a Player */
void displayStats(FILE *logFile, Stats stats, char *playerName)
{
    printf("\n%s stats:\n", playerName);
    fprintf(logFile, "\n%s stats:\n", playerName);
    printLogInt(logFile, "Total hits", stats.totalHits, "\n");
    printLogInt(logFile, "Total misses", stats.totalMisses, "\n");
    printLogInt(logFile, "Hit miss ratio", (int)stats.ratioHitsToMisses, "%%\n");
    printLogInt(logFile, "Total shots", stats.totalHits + stats.totalMisses, "\n");
}

/* Returns if every ship has been sunk or not */
int allShipsSunk(Ship ships[])
{
    for (int i = 0; i < SHIP_COUNT; i++)
    {
        if (!ships[i].sunk)
        {
            return FALSE;
        }
    }
    return TRUE;
}

/* Sets up each Player's board, returns if should return to main menu or not */
int setupGame(Player *humanPtr, Player *computerPtr)
{
    FILE *logFile = fopen(LOG_FILE, "w");
    fprintf(logFile, "BATTLESHIP LOG\n\n");
    fclose(logFile);
    int placeInput = SETUP_NONE;
    while (1)
    {
        clearConsole();
        puts("SHIP SETUP");
        puts("1) Manually");
        puts("2) Randomly");
        puts("3) Quit to menu");
        placeInput = getIntInput();
        if (placeInput == SETUP_MANUAL)
        {
            placeShipsManually(humanPtr);
            break;
        }
        else if (placeInput == SETUP_RANDOM)
        {
            placeShipsRandomly(humanPtr);
            break;
        }
        else if (placeInput == SETUP_QUIT)
        {
            return placeInput;
        }
    }
    placeShipsRandomly(computerPtr);
    return placeInput;
}

/* Plays a game of Battleship, returns who won */
int playGame(Player *humanPtr, Player *computerPtr)
{
    int currentPlayer = randInt(PLAYER_HUMAN, PLAYER_COMPUTER);
    int winStatus = -1;
    while (winStatus == -1)
    {
        if (currentPlayer == PLAYER_HUMAN)
        {
            humanTurn(humanPtr, computerPtr);
            if (allShipsSunk(computerPtr->ships))
            {
                winStatus = PLAYER_HUMAN;
            }
            currentPlayer = PLAYER_COMPUTER;
        }
        else if (currentPlayer == PLAYER_COMPUTER)
        {
            computerTurn(humanPtr, computerPtr);
            if (allShipsSunk(humanPtr->ships))
            {
                winStatus = PLAYER_COMPUTER;
            }
            currentPlayer = PLAYER_HUMAN;
        }
        pauseConsole();
    }
    return winStatus;
}

void endGame(int gameResult, Player *humanPtr, Player *computerPtr)
{
    humanPtr->stats.ratioHitsToMisses = 100 * (double)humanPtr->stats.totalHits / humanPtr->stats.totalMisses;
    computerPtr->stats.ratioHitsToMisses = 100 * (double)computerPtr->stats.totalHits / computerPtr->stats.totalMisses;
    FILE *logFile = fopen(LOG_FILE, "a+");
    if (gameResult == PLAYER_HUMAN)
    {
        printLog(logFile, "\nYOU WON! You sunk all of computer's ships!\n");
    }
    else if (gameResult == PLAYER_COMPUTER)
    {
        printLog(logFile, "\nYOU LOST! Computer sunk all of your ships!\n");
    }
    displayStats(logFile, humanPtr->stats, "Your");
    displayStats(logFile, computerPtr->stats, "Computer's");
    fclose(logFile);
}
