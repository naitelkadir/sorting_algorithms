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
 * partition - ...
 * @size: ...
 * @array: ...
 * @low: ...
 * @high: ...
 * Return: ...
 */
size_t partition(int *array, size_t size, int low, int high)
{
	int i, j;
	int *pivot;

	pivot = array + high;
	for (i = j = low; j < high; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap_ints(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > *pivot)
	{
		swap_ints(array + i, pivot);
		print_array(array, size);
	}
	return (i);
}
/**
 * quick_sortrec - ...
 * @array: ...
 * @size: ...
 * @low: ...
 * @high: ...
 */
void quick_sortrec(int *array, size_t size, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, size, low, high);
		quick_sortrec(array, size, low, pi - 1);
		quick_sortrec(array, size, pi + 1, high);
	}
}
/**
 * quick_sort - ...
 * @array: ...
 * @size: ...
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quick_sortrec(array, size, 0, size - 1);
}
