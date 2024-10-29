#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - returns the maximum value in an array.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum value in the array.
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - performs counting sort based on a specific digit.
 * @array: The array of integers.
 * @size: The size of the array.
 * @exp: The current exponent (digit).
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};
	size_t i;

	if (!output)
		return;

	for (i = 0; i < size; i++)
	{
		count[(array[i] / exp) % 10]++;
	}

	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}
	print_array(array, size);

	free(output);
}

/**
 * radix_sort - sorts an array of integers using the Radix sort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
	}
}

