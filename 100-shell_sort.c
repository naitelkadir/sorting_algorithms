#include "sort.h"

/**
 * swap_ints - ...
 * @a: ...
 * @b: ...
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * shell_sort - ...
 * @array: ...
 * @size: ...
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	
	for (gap = size / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
			{
				swap_ints(array + j, array + (j - gap));
			}
		}
		print_array(array, size);
	}
}
