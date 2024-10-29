#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array
 * @array: The array of integers to sort
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *output_array;
	int max = 0;
	size_t i;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count_array = malloc((max + 1) * sizeof(int));
	output_array = malloc(size * sizeof(int));
	if (count_array == NULL || output_array == NULL)
	{
		free(count_array);
		free(output_array);
		return;
	}
	for (i = 0; i <= max; i++)
		count_array[i] = 0;
	for (i = 0; i < size; i++)
		count_array[array[i]]++;
	for (i = 0; i <= max; i++)
	{
		printf("%d", count_array[i]);
		if (i < max)
			printf(", ");
	}
	printf("\n");
	for (i = 1; i <= max; i++)
		count_array[i] += count_array[i - 1];
	for (i = size; i > 0; i--)
	{
		output_array[count_array[array[i - 1]] - 1] = array[i - 1];
		count_array[array[i - 1]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output_array[i];

	free(count_array);
	free(output_array);
}

