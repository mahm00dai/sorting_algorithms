#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @node_a: The first node to swap.
 * @node_b: The second node to swap.
 * @list: Double pointer to the head of the list.
 */
void swap_nodes(listint_t *node_a, listint_t *node_b, listint_t **list)
{
	listint_t *temp = node_b->next;

	if (node_a->prev)
		node_a->prev->next = node_b;
	else
		*list = node_b;

	if (node_b->next)
		node_b->next->prev = node_a;

	node_b->prev = node_a->prev;
	node_a->next = temp;

	node_b->next = node_a;
	node_a->prev = node_b;

	if (temp)
		temp->prev = node_a;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the Cocktail shaker sort algorithm.
 * @list: Double pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		current = *list;

		while (current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next, list);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				current = current->next;
			}
		}

		if (!swapped)
			break;

		swapped = 0;

		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current->prev, current, list);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				current = current->prev;
			}
		}
	}
}

