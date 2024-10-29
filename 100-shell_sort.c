#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm with the Knuth sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: Nothing.
 */
void shell_sort(int *array, size_t size)
{
	int gap, i, j, temp;
	int gaps[100];
	int gap_count = 0;

	gap = 1;
	while (gap < size)
	{
		gaps[gap_count++] = gap;
		gap = gap * 3 + 1;
	}

	for (gap_count--; gap_count >= 0; gap_count--)
	{
		gap = gaps[gap_count];

		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}

		print_array(array, size);
	}
}

