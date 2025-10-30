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
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	b->next = a;
	a->prev = b;

	print_list(*list);
}

/**
 * forward_pass - Move forward through the list, swapping as needed
 * @list: Pointer to the head of list
 * @end: Pointer to the node where forward pass stops
 *
 * Return: Pointer to the last node reached
 */
listint_t *forward_pass(listint_t **list, listint_t *end)
{
	listint_t *tmp = *list, *last = end;
	int swapped = 0;

	while (tmp && tmp->next != last)
	{
		if (tmp->n > tmp->next->n)
		{
			swap_nodes(list, tmp, tmp->next);
			swapped = 1;
		}
		else
		{
			tmp = tmp->next;
		}
	}
	return (swapped ? tmp : NULL);
}

/**
 * backward_pass - Move backward through the list, swapping as needed
 * @list: Pointer to the head of list
 * @start: Pointer to the node where backward pass starts
 *
 * Return: 1 if any swap occurred, 0 otherwise
 */
int backward_pass(listint_t **list, listint_t *start)
{
	listint_t *tmp = start;
	int swapped = 0;

	while (tmp && tmp->prev)
	{
		if (tmp->n < tmp->prev->n)
		{
			swap_nodes(list, tmp->prev, tmp);
			swapped = 1;
		}
		else
		{
			tmp = tmp->prev;
		}
	}
	return (swapped);
}

/**
 * cocktail_sort_list - Sort a doubly linked list using cocktail shaker sort
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *end = NULL;

	if (!list || !*list || !(*list)->next)
		return;
	
	while (swapped)
	{
		swapped = 0;
		end = forward_pass(list, end);
		if (!end)
			break;
		if (backward_pass(list, end))
			swapped = 1;
	}
}
