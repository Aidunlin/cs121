#include <stdio.h>


// This function returns the length of the string pointed to by s. The computation of length does NOT include the null character.
int my_strlen(const char* s)
{
  int size = 0;
  for (; s[size] != '\0'; size++);
  return size;
}


// Accepts a string as an argument and reverses the string without creating an extra array to perform the reversing.
// This is a form of in place reversal. The function should return a pointer to the reversed string.
// Implement a solution to this function using array notation only.
char* string_reverse(char s[])
{
  int size = my_strlen(s);

  for (int i = 0; i < size / 2; i++)
  {
    char temp = s[i];
    s[i] = s[size - i - 1];
    s[size - i - 1] = temp;
  }

  return s;
}

// string_reverse() using pointer notation and pointer arithmetic only
char* string_reverse2(char s[])
{
  int size = my_strlen(s);

  char* c1 = s;
  char* c2 = s + size - 1;

  for (int i = 0; i < size / 2; i++)
  {
    char temp = *c2;
    *c2 = *c1;
    *c1 = temp;
    c1++;
    c2--;
  }

  return s;
}


// Copies all characters in the array pointed to by source into the array pointed to by destination. The null character is also copied. The function returns destination.
char* my_strcpy(char* destination, const char* source)
{
  int size = my_strlen(source);

  for (int i = 0; i < size + 1; i++)
  {
    destination[i] = source[i];
  }
  return destination;
}

// This function appends a copy of the string pointed to by source (including the null character) to the end of the string pointed to by destination.
// The append overwrites the null character at the end of destination. The string pointed to by destination is returned.
char* my_strcat(char* destination, const char* source)
{
  int dest_size = my_strlen(destination);
  int source_size = my_strlen(source);

  for (int i = 0; i < source_size + 1; i++)
  {
    destination[dest_size + i] = source[i];
  }

  return destination;
}

// This function compares the string pointed to by s1 to the string pointed to by s2.
// If the string pointed to by s1 comes before the string pointed to by s2 in dictionary ordering, then -1 is returned.
// If the string pointed to by s1 is the same as the string pointed to by s2, then 0 is returned (the compare function is case sensitive).
// Otherwise 1 is returned.
int my_strcmp(const char* s1, const char* s2)
{
  int size = my_strlen(s1);
  int output = 0;

  for (int i = 0; i < size; i++)
  {
    if (s1[i] < s2[i])
    {
      output = -1;
      break;
    }
    else if (s1[i] > s2[i])
    {
      output = 1;
      break;
    }
  }

  return output;
}



void task1()
{
  puts("TASK 1");

  char thing[10] = { 'h', 'i', ' ', 't', 'h', 'e', 'r', 'e' };
  puts(string_reverse(thing));

  char thing2[10] = { 'r', 'a', 'c', 'e', ' ', 'c', 'a', 'r' };
  puts(string_reverse2(thing2));
}

void task2()
{
  puts("TASK 2");

  char thing[10] = { 'h', 'i', ' ', 't', 'h', 'e', 'r', 'e' };
  char thing2[10] = { 'r', 'a', 'c', 'e', ' ', 'c', 'a', 'r' };
  puts(my_strcpy(thing, thing2));

  char thing3[20] = { 'h', 'i', ' ', 't', 'h', 'e', 'r', 'e' };
  char thing4[10] = { 'r', 'a', 'c', 'e', ' ', 'c', 'a', 'r' };
  puts(my_strcat(thing3, thing4));

  printf("%d\n", my_strcmp(thing, thing3));
}

int main()
{
  task1();
  task2();
  return 0;
}
