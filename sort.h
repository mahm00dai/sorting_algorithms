#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - singly linked list node
 * @n: integer
 * @next: points to the next node
 * @prev: points to the previous node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
	int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void insertion_sort_list(listint_t **list);
void print_list(const listint_t *list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *array, int a, int b);
int partition(int *array, int low, int high);
void quick_sort_recursive(int *array, int low, int high);
void shell_sort(int *array, size_t size);
/*void swap_nodes(listint_t *a, listint_t *b);*/
void swap_nodes(listint_t *node_a, listint_t *node_b, listint_t **list);
void cocktail_sort_list(listint_t **list);
/*void counting_sort(int *array, size_t size);*/
void merge(int *array, size_t left, size_t mid, size_t right);
void merge_sort_recursive(int *array, size_t left, size_t right);
void merge_sort(int *array, size_t size);
void sift_down(int *array, size_t size, size_t root, size_t max);
void heapify(int *array, size_t size);
void heap_sort(int *array, size_t size);
int get_max(int *array, size_t size);
void counting_sort(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);

#endif /* SORT_H */

