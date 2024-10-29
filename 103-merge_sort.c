#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of array[].
 * @array: The array to merge
 * @left: The starting index of the left subarray
 * @mid: The ending index of the left subarray
 * @right: The ending index of the right subarray
 */
void merge(int *array, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;
	size_t n1 = mid - left + 1;
	size_t n2 = right - mid;
	int *L, *R;

	L = malloc(n1 * sizeof(int));
	R = malloc(n2 * sizeof(int));
	if (L == NULL || R == NULL)
		return;

	for (i = 0; i < n1; i++)
		L[i] = array[left + i];
	for (j = 0; j < n2; j++)
		R[j] = array[mid + 1 + j];

	printf("Merging...\n[left]: ");
	for (i = 0; i < n1; i++)
	{
		printf("%d", L[i]);
		if (i < n1 - 1)
			printf(", ");
	}
	printf("\n[right]: ");
	for (j = 0; j < n2; j++)
	{
		printf("%d", R[j]);
		if (j < n2 - 1)
			printf(", ");
	}
	printf("\n");

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}

	printf("[Done]: ");
	for (k = left; k <= right; k++)
	{
		printf("%d", array[k]);
		if (k < right)
			printf(", ");
	}
	printf("\n");

	free(L);
	free(R);
}

/**
 * merge_sort_recursive - Recursive helper function for merge_sort
 * @array: The array to sort
 * @left: The starting index of the array
 * @right: The ending index of the array
 */
void merge_sort_recursive(int *array, size_t left, size_t right)
{
	if (left < right)
	{
		size_t mid = left + (right - left) / 2;

		merge_sort_recursive(array, left, mid);
		merge_sort_recursive(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}

/**
 * merge_sort - Sorts an array of integers using the Merge sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursive(array, 0, size - 1);
}

