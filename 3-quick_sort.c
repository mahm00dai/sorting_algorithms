#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers in an array and prints the array.
 * @array: The array of integers.
 * @a: The index of the first integer.
 * @b: The index of the second integer.
 */
void swap(int *array, int a, int b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
	print_array(array, 10);
}

/**
 * partition - Partitions the array using Lomuto's scheme.
 * @array: The array of integers.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 *
 * Return: The index of the pivot after partitioning.
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
				swap(array, i, j);
		}
	}
	if (i + 1 != high)
		swap(array, i + 1, high);
	return (i + 1);
}

/**
 * quick_sort_recursive - Implements the Quick Sort algorithm recursively.
 * @array: The array of integers.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 */
void quick_sort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
		int pi = partition(array, low, high);

		quick_sort_recursive(array, low, pi - 1);
		quick_sort_recursive(array, pi + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1);
}

