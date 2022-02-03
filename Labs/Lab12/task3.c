#include <stdio.h>
#include <string.h>

void recRevStr(char *src, int totalLength)
{
    int length = strlen(src) - (totalLength - strlen(src));
    if (length > 1)
    {
        char temp = src[0];
        src[0] = src[length - 1];
        src[length - 1] = temp;
        recRevStr(src + 1, totalLength);
    }
}

int main()
{
    char thing1[] = "race car";
    recRevStr(thing1, strlen(thing1));
    printf("%s\n", thing1);

    char thing2[] = "hello world";
    recRevStr(thing2, strlen(thing2));
    printf("%s\n", thing2);

    return 0;
}

/* 

11 - h e l l o _ w o r l d

11 - d e l l o _ w o r l h

9  - e l l o _ w o r l

9  - l l l o _ w o r e

7  - l l o _ w o r

7  - r l o _ w o l

5  - l o _ w o

5  - o o _ w l

3  - o _ w

3  - w _ o

1  - _

d l r o w _ o l l e h

*/
