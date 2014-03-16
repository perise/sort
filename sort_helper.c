#include <time.h>
#include <stdlib.h>
#include "sort_helper.h"
bool 
increase_sort_answer_check(int *a, int size)
{
	int		i = 0;
	while (i + 1 < size) {
		if (a[i] > a[i + 1])
			return false;
		++i;
	}
	return true;
}

void
exchange(int *p, int *q)
{
	int		temp = *p;
	*p = *q;
	*q = temp;
}

void
test_array_generator(int *array, int size)
{
	int		i = 0;
	srand((unsigned)time(0));
	for (i = 0; i < size; i++) {
		array[i] = rand() % 100;
	}
}
