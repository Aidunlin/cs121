#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void strcat2(char *dest, char *src1, char *src2)
{
    strcat(dest, src1);
    strcat(dest, src2);
}

int main(void)
{
    srand((unsigned int)time(NULL));
    char *article[5] = {"the", "a", "one", "some", "any"};
    char *noun[5] = {"boy", "girl", "dog", "town", "car"};
    char *verb[8] = {"drove", "jumped", "ran", "walked", "skipped"};
    char *preposition[6] = {"to", "from", "over", "under", "on"};
    for (int i = 0; i < 20; i++)
    {
        char sentence[50] = "";
        strcat2(sentence, article[rand() % 5], " ");
        strcat2(sentence, noun[rand() % 5], " ");
        strcat2(sentence, verb[rand() % 5], " ");
        strcat2(sentence, preposition[rand() % 5], " ");
        strcat2(sentence, article[rand() % 5], " ");
        strcat2(sentence, noun[rand() % 5], "!");
        sentence[0] -= 'a' - 'A';
        puts(sentence);
    }
    return 0;
}
