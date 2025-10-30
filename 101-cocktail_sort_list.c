#include "sort.h"

/**
 * swap_nodes - Swap two adjacent nodes a and b in a doubly linked list
 * @list: Pointer to the head of the list
 * @a: First node
 * @b: Second node (a->next)
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (!a || !b)
		return;
	if (a->prev)
		a->prev->next = b;
	b->prev = a->prev;

	a->next = b->next;
	if (b->next)
		b->next->prev = a;

	b->next = a;
	a->prev = b;

	if (!b->prev)
		*list = b;
	print_list(*list);
}

/**
 * forward_pass - One forward pass of cocktail shaker sort
 * @list: Pointer to the head of the list
 * @end: Pointer to last sorted node
 *
 * Return: 1 if any swap happened, 0 otherwise
 */
int forward_pass(listint_t **list, listint_t *end)
{
	int swapped = 0;
	listint_t *tmp;

	for (tmp = *list; tmp->next != end; tmp = tmp->next)
	{
		if (tmp->n > tmp->next->n)
		{
			swap_nodes(list, tmp, tmp->next);
			swapped = 1;
		}
	}
	return swapped;
}

/**
 * backward_pass - One backward pass of cocktail shaker sort
 * @list: Pointer to the head of the list
 * @start: Pointer to first sorted node
 *
 * Return: 1 if any swap happened, 0 otherwise
 */
int backward_pass(listint_t **list, listint_t *start)
{
	int swapped = 0;
	listint_t *tmp;

	for (tmp = start->prev; tmp->prev != NULL; tmp = tmp->prev)
	{
		if (tmp->n < tmp->prev->n)
		{
			swap_nodes(list, tmp->prev, tmp);
			swapped = 1;
		}
	}
	return swapped;
}

/**
 * cocktail_sort_list - Sort a doubly linked list using cocktail shaker sort
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *end = NULL;

	if (!list || !*list || !(*list)->next)
		return;

	while (swapped)
	{
		swapped = forward_pass(list, end);
		if (!swapped)
			break;
		
		end = *list;
		swapped = backward_pass(list, end);
	}
}
