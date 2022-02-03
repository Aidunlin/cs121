#include <stdio.h>

// sum(765) = 18
int sum(int value)
{
    if (value == 0)
    {
        return 0;
    }
    else
    {
        return value % 10 + sum(value / 10);
    }
}

int main()
{
    printf("%d\n", sum(765));
    return 0;
}
