#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE_BOARD 3

typedef struct coordinate
{
    int row;
    int column;
} Coordinate;

typedef struct cell
{
    int occupied;
    char symbol;
    Coordinate location;
} Cell;

typedef struct game_info
{
    int wins;
    int losses;
    int total_games_played;
} Game_info;

Coordinate init_coordinate(int row, int column)
{
    Coordinate coordinate;
    coordinate.row = row;
    coordinate.column = column;
    return coordinate;
}

Cell init_cell(int row, int column)
{
    Cell cell;
    cell.occupied = 0;
    cell.symbol = ' ';
    cell.location = init_coordinate(row, column);
    return cell;
}

Game_info init_game_info(void)
{
    Game_info game_info;
    game_info.wins = 0;
    game_info.losses = 0;
    game_info.total_games_played = 0;
    return game_info;
}

void init_game_board(Cell game_board[SIZE_BOARD][SIZE_BOARD])
{
    for (int y = 0; y < SIZE_BOARD; y++)
        for (int x = 0; x < SIZE_BOARD; x++)
            game_board[y][x] = init_cell(y, x);
}

void display_game_board(Cell game_board[SIZE_BOARD][SIZE_BOARD])
{
    printf("\n  ");
    for (int i = 0; i < SIZE_BOARD; i++)
        printf("%d ", i);
    printf("\n");
    for (int y = 0; y < SIZE_BOARD; y++)
    {
        printf("%d ", y);
        for (int x = 0; x < SIZE_BOARD; x++)
            printf("%c ", game_board[y][x].symbol);
        printf("\n");
    }
}

int check_if_valid(int x, int y, Cell game_board[SIZE_BOARD][SIZE_BOARD])
{
    int x_valid = x >= 0 && x < SIZE_BOARD;
    int y_valid = y >= 0 && y < SIZE_BOARD;
    return x_valid && y_valid && !game_board[y][x].occupied;
}

int check_if_won(char player, int x, int y, Cell game_board[SIZE_BOARD][SIZE_BOARD])
{
    int winX = 1, winY = 1, winD1 = 1, winD2 = 1;
    for (int i = 0; i < SIZE_BOARD; i++)
    {
        if (game_board[i][x].symbol != player)
            winX = 0;
        if (game_board[y][i].symbol != player)
            winY = 0;
        if (game_board[i][i].symbol != player)
            winD1 = 0;
        if (game_board[i][SIZE_BOARD - i - 1].symbol != player)
            winD2 = 0;
    }
    return winX || winY || winD1 || winD2;
}

char pick_player(void)
{
    if (rand() % 2 == 0)
        return 'O';
    return 'X';
}

char alternate_player(char player)
{
    if (player == 'X')
        return 'O';
    return 'X';
}

void display_game_result(int win, char player)
{
    if (win)
    {
        printf("%c wins!\n", player);
    }
    else
        printf("Tie!\n");
}

void update_info(int win, char player, Game_info *player1_ptr, Game_info *player2_ptr)
{
    if (win)
    {
        if (player == 'X')
        {
            player1_ptr->wins++;
            player2_ptr->losses++;
        }
        if (player == 'O')
        {
            player1_ptr->losses++;
            player2_ptr->wins++;
        }
    }
    player1_ptr->total_games_played++;
    player2_ptr->total_games_played++;
}

void display_player_info(Game_info player_info, char player)
{
    printf("Player %c:\n", player);
    printf("- Wins: %d\n", player_info.wins);
    printf("- Losses: %d\n", player_info.losses);
}

void display_stats(Game_info player1_info, Game_info player2_info)
{
    printf("\nStats:\n");
    printf("Total games played: %d\n", player1_info.total_games_played);
    display_player_info(player1_info, 'X');
    display_player_info(player2_info, 'O');
}

int main(void)
{
    Game_info player1_info = init_game_info();
    Game_info player2_info = init_game_info();
    char input;
    while (input != 'n')
    {
        Cell game_board[SIZE_BOARD][SIZE_BOARD];
        init_game_board(game_board);
        char player = pick_player();
        int turn = 0;
        int max_turns = SIZE_BOARD * SIZE_BOARD;
        int win = 0;
        while (turn < max_turns)
        {
            printf("\n");
            display_game_board(game_board);
            printf("%c's turn, enter x and y\n", player);
            int x, y;
            scanf("%d %d", &x, &y);
            if (check_if_valid(x, y, game_board))
            {
                game_board[y][x].symbol = player;
                game_board[y][x].occupied = 1;
                win = check_if_won(player, x, y, game_board);
                if (win)
                    break;
                player = alternate_player(player);
                turn++;
            }
        }
        display_game_board(game_board);
        display_game_result(win, player);
        update_info(win, player, &player1_info, &player2_info);
        printf("Would you like to play another game? [y/n] ");
        scanf(" %c", &input);
    }
    display_stats(player1_info, player2_info);
    printf("Goodbye!\n");
    return 0;
}
