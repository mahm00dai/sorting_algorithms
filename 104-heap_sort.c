#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - swaps two elements in an array.
 * @array: The array of integers.
 * @i: The first index.
 * @j: The second index.
 */
void swap(int *array, int a, int b)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

/**
 * sift_down - ensures the heap property is maintained.
 * @array: The array of integers.
 * @size: The size of the array.
 * @root: The root index of the heap.
 * @max: The maximum size of the heap.
 */
void sift_down(int *array, size_t size, size_t root, size_t max)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < max && array[left] > array[largest])
		largest = left;
	if (right < max && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(array, root, largest);
		print_array(array, size);
		sift_down(array, size, largest, max);
	}
}

/**
 * heapify - creates a max heap from an array.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void heapify(int *array, size_t size)
{
	for (ssize_t i = size / 2 - 1; i >= 0; i--)
	{
		sift_down(array, size, i, size);
	}
}

/**
 * heap_sort - sorts an array of integers using the Heap sort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	heapify(array, size);

	for (ssize_t i = size - 1; i > 0; i--)
	{
		swap(array, 0, i);
		print_array(array, size);
		sift_down(array, size, 0, i);
	}
}

