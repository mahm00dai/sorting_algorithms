#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @a: First node to swap.
 * @b: Second node to swap.
 */
void swap_nodes(listint_t *a, listint_t *b)
{
	listint_t *temp;

	if (a == NULL || b == NULL || a == b)
		return;

	temp = a->prev;
	if (temp)
		temp->next = b;
	b->prev = temp;

	a->next = b->next;
	if (b->next)
		b->next->prev = a;

	b->next = a;
	b->prev = temp;
	a->prev = b;

	if (!b->prev)
		*b = *a;

	print_list(a);
}

/**
 * insertion_sort_list - sort algorithm.
 *
 * @list: Pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert_pos;

	if (!list || !*list)
		return;

	current = (*list)->next;
	while (current)
	{
		insert_pos = current->prev;
		while (insert_pos && current->n < insert_pos->n)
		{
			swap_nodes(insert_pos, current);
			if (!current->prev)
				*list = current;
			insert_pos = current->prev;
		}
		current = current->next;
	}
}

