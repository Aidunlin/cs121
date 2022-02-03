#include <stdio.h>

int alreadyChecked(int checked[64][2], int x, int y)
{
    for (int i = 0; i < 64; i++)
    {
        if (checked[i][0] == x && checked[i][1] == y)
        {
            return 1;
        }
    }

    return 0;
}

void addToChecked(int checked[64][2], int x, int y)
{
    for (int i = 0; i < 64; i++)
    {
        if (checked[i][0] == -1)
        {
            checked[i][0] = x;
            checked[i][1] = y;
            return;
        }
    }
}

int walkSpecificPath(char *maze[8], int checked[64][2], int x, int y)
{
    if (maze[y][x] == ' ' && !alreadyChecked(checked, x, y))
    {
        addToChecked(checked, x, y);
        if (walkPath(maze, checked, x, y) == 1)
        {
            return 1;
        }
    }

    return 0;
}

int walkPath(char *maze[8], int checked[64][2], int x, int y)
{
    int isEnd = x == 7 && y == 7;
    int foundUp = y > 0 && walkSpecificPath(maze, checked, x, y - 1);
    int foundDown = y < 8 && walkSpecificPath(maze, checked, x, y + 1);
    int foundLeft = x > 0 && walkSpecificPath(maze, checked, x - 1, y);
    int foundRight = x < 8 && walkSpecificPath(maze, checked, x + 1, y);

    return isEnd || foundUp || foundDown || foundLeft || foundRight;
}

int main()
{
    char *maze[8];

    maze[0] = "XXXXXXXX";
    maze[1] = "       X";
    maze[2] = "XXXXXX X";
    maze[3] = "X    X X";
    maze[4] = "X XX   X";
    maze[5] = "X  XXXXX";
    maze[6] = "XX     X";
    maze[7] = "XXXXXX  ";

    int checked[64][2];

    for (int i = 0; i < 64; i++)
    {
        checked[i][0] = -1;
        checked[i][1] = -1;
    }

    int result = walkPath(maze, checked, 0, 1);

    if (result == 1)
    {
        puts("Path found");
    }
    else
    {
        puts("No path");
    }
}
