#include <stdio.h>
#include "quick_sort.h"
#include "sort_helper.h"

#define ARRAY_SIZE 10
#define ARRAY_SIZE_ONE 10
#define ARRAY_SIZE_TWO 10


// return the start of big part
int
partion(int *array, int start, int stop)
{
	if (stop > start) {
		int		little_idx = start;
		int		big_idx = stop - 1;
		int		key = array[stop];
		while (1) {
			while (array[little_idx] <= key && little_idx < stop)
				little_idx++;
			while (array[big_idx] > key && big_idx > start)
				big_idx--;
			if (big_idx > little_idx) {
				exchange(&array[big_idx], &array[little_idx]);
			} else {
				break;
			}
		}
		if (little_idx == start) {
			exchange(&array[start], &array[stop]);
			little_idx = start + 1;
		}
		return little_idx;
	} else
		return stop;
}

int 
quick_sort(int *array, int start, int stop)
{
	int		big_start = 0;
	if (stop > start) {
		big_start = partion(array, start, stop);
		if (big_start > start) {
			quick_sort(array, start, big_start - 1);
			quick_sort(array, big_start, stop);
		}
	}
	return 0;
}



bool 
quick_sort_test()
{
	int		i;
	int		test_array [ARRAY_SIZE] = {0};
	test_array_generator(test_array, ARRAY_SIZE);
	printf("quick sort input:\n");
	for (i = 0; i < ARRAY_SIZE; i++) {
		printf("%d ", test_array[i]);
	}
	printf("\n");
	quick_sort(test_array, 0, ARRAY_SIZE - 1);
	printf("quick sort output:\n");
	for (i = 0; i < ARRAY_SIZE; i++) {
		printf("%d ", test_array[i]);
	}
	printf("\n");
	if (increase_sort_answer_check(test_array, ARRAY_SIZE)) {
		printf("quick answer is right\n");
		return true;
	} else {
		printf("quick answer is wrong \n");
		return false;
	}
}
