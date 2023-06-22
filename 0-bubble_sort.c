#include "sort.h"

/**
 * bubble_sort - sorts any array of integers
 * @array: the array to list 
 * @size: the size of the array to sort
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int reverse;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				reverse = array[j];
				array[j] = array[j + 1];
				array[j + 1] = reverse;
				print_array(array, size);
			}

		}
	}
}
