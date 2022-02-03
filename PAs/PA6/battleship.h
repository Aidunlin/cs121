/* Programmer: Aidan Linerud
Assignment: PA 6
Description: Simulates the game of Battleship */

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "aidanlib.h"

#define LOG_FILE "battleship.log"
#define SIZE_BOARD 10
#define SHIP_COUNT 5

#define CELL_EMPTY '-'
#define CELL_HIT '*'
#define CELL_MISS 'm'

#define CELL_CARRIER 'c'
#define CELL_BATTLESHIP 'b'
#define CELL_CRUISER 'r'
#define CELL_SUBMARINE 's'
#define CELL_DESTROYER 'd'

#define SIZE_CARRIER 5
#define SIZE_BATTLESHIP 4
#define SIZE_CRUISER 3
#define SIZE_SUBMARINE 3
#define SIZE_DESTROYER 2

typedef enum MenuOption
{
    MENU_NONE,
    MENU_PLAY,
    MENU_RULES,
    MENU_EXIT
} MenuOption;

typedef enum SetupOption
{
    SETUP_NONE,
    SETUP_MANUAL,
    SETUP_RANDOM,
    SETUP_QUIT
} SetupOption;

typedef enum PlayerType
{
    PLAYER_HUMAN,
    PLAYER_COMPUTER
} PlayerType;

typedef enum Axis
{
    AXIS_HORIZONTAL,
    AXIS_VERTICAL
} Axis;

typedef enum ShipsDisplay
{
    SHIPS_SHOW,
    SHIPS_HIDE
} ShipsDisplay;

typedef struct Stats
{
    int totalHits;
    int totalMisses;
    double ratioHitsToMisses;
} Stats;

typedef struct Ship
{
    char cell;
    char *name;
    int size;
    int hits;
    int sunk;
} Ship;

typedef struct Player
{
    Stats stats;
    char board[SIZE_BOARD][SIZE_BOARD];
    Ship ships[SHIP_COUNT];
} Player;

/* Creates and returns a new Stats */
Stats initStats();

/* Initializes a 2D board */
void initBoard(char board[][SIZE_BOARD]);

/* Creates and returns a new Ship */
Ship initShip(char shipCell, char *shipName, int shipSize);

/* Creates and returns a new Player */
Player initPlayer();

/* Displays a 2D board */
void displayBoard(char board[][SIZE_BOARD], int hideShips);

/* Iteratively places a ship from a starting location if possible, returns if successful or not */
int placeShipIfValid(char board[][SIZE_BOARD], Ship ship, int axis, int x, int y);

/* Asks for Player input to place a ship */
void placeShipManually(char board[][SIZE_BOARD], Ship ship);

/* Consecutively place each ship with input from Player */
void placeShipsManually(Player *playerPtr);

/* Randomly places a ship */
void placeShipRandomly(char board[][SIZE_BOARD], Ship ship);

/* Consecutively places each ship for a Player randomly */
void placeShipsRandomly(Player *playerPtr);

/* Updates ship's hits counter and displays a message */
void hitShip(Ship *shipPtr, int currentPlayer, int x, int y);

/* Determines if a location is a hit/miss, updates the board, returns if location is new or not */
int handleTurn(Player *thisPlayerPtr, Player *otherPlayerPtr, int currentPlayer, int x, int y);

/* Asks for Player input to choose a location */
void humanTurn(Player *humanPtr, Player *computerPtr);

/* Randomly chooses a location */
void computerTurn(Player *humanPtr, Player *computerPtr);

/* Displays the Stats of a Player */
void displayStats(FILE *logFile, Stats stats, char *playerName);

/* Returns if every ship has been sunk or not */
int allShipsSunk(Ship ships[]);

/* Sets up each Player's board, returns if should return to main menu or not */
int setupGame(Player *humanPtr, Player *computerPtr);

/* Plays a game of Battleship, returns who won */
int playGame(Player *humanPtr, Player *computerPtr);

/* Updates and displays stats and win result */
void endGame(int gameResult, Player *humanPtr, Player *computerPtr);

#endif
