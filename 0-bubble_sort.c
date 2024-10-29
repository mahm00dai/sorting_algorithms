#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;
	int swapped;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/* Print the array after each swap */
				print_array(array, size);
				swapped = 1;
			}
		}
		/* If no elements were swapped, the array is sorted */
		if (swapped == 0)
			break;
	}
}

