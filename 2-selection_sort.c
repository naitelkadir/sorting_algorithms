#include "sort.h"

/**
 * selection_sort - ...
 * @array: ...
 * @size: ...
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int reverse, m;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{	m = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < m)
			{
				m = array[j];
			}
		}
		for (k = i + 1; k < size; k++)
		{
			if (array[k] == m)
			{
				reverse = array[i];
				array[i] = array[k];
				array[k] = reverse;
				print_array(array, size);
			}
		}
	}
}
