#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t val, i, j;

	if (array == NULL || size < 2)
		return;

	for (val = 1; val < (size / 3);)
		val = val * 3 + 1;

	for (; val >= 1; val /= 3)
	{
		for (i = val; i < size; i++)
		{
			j = i;
			while (j >= val && array[j - val] > array[j])
			{
				swap_ints(array + j, array + (j - val));
				j -= val;
			}
		}
		print_array(array, size);
	}
}
