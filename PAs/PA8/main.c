#include "problems.h"

int main()
{
	printf("\nPROBLEM 1\n");
	char p1_dest_str[30] = "hello there";
	char p1_src_str[] = "general kenobi";
	printf("%s\n", my_str_n_cat(p1_dest_str, p1_src_str, 15));

	printf("\nPROBLEM 2\n");
	int p2_values[] = { 0, 2, 3, 4, 5 };
	printf("%d\n", binary_search(p2_values, 3, 5));
	printf("%d\n", binary_search(p2_values, 6, 5));
	printf("%d\n", binary_search(p2_values, 1, 5));

	printf("\nPROBLEM 3\n");
	char* p3_strings[] = { "lorem", "ipsum", "dolor", "sit", "amet" };
	bubble_sort(p3_strings, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", p3_strings[i]);
	}

	printf("\nPROBLEM 4\n");
	printf("%d\n", is_palindrome("race car", 8));

	printf("\nPROBLEM 5\n");
	printf("%d\n", sum_primes(10)); // 2 + 3 + 5 + 7 = 17

	printf("\nPROBLEM 6\n");
	char p6_str[] = "test string";
	Occurrences p6_occurrences[26];
	for (int i = 0; i < 26; i++)
	{
		p6_occurrences[i].frequency = 0;
		p6_occurrences[i].num_occurrences = 0;
	}
	int p6_out_int = 0;
	char p6_out_char = '\0';
	maximum_occurences(p6_str, p6_occurrences, &p6_out_int, &p6_out_char);
	printf("'%c' occurs %d times\n", p6_out_char, p6_out_int);

	printf("\nPROBLEM 7\n");
	signed int p7_values[4][5] = {
		{-5, 6, 0, 2, 2},
		{2, 2, 2, 9, 3},
		{3, 3, 2, 1 - 8},
		{7, -2, 6, 0, 4}
	};
	signed int* p7_start_ptr = NULL;
	int p7_num_integers = 0;
	max_consecutive_integers(p7_values, 4, 5, &p7_start_ptr, &p7_num_integers);
	if (p7_start_ptr != NULL)
	{
		printf("number: %d\n", *p7_start_ptr);
	}
	printf("count: %d\n", p7_num_integers);

	return 0;
}
