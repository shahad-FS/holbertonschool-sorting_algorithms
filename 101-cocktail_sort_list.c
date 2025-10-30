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
 *
 * Return: Pointer to the last node reached
 */
listint_t *forward_pass(listint_t **list)
{
	listint_t *tmp = *list, *last = NULL;

	while (tmp && tmp->next)
	{
		if (tmp->n > tmp->next->n)
		{
			swap_nodes(list, tmp, tmp->next);
			last = tmp->prev;
		}
		else
		{
			last = tmp;
			tmp = tmp->next;
		}
	}
	return (last);
}

/**
 * backward_pass - Move backward through the list, swapping as needed
 * @list: Pointer to the head of list
 * @end: Pointer to the node where backward pass stops
 *
 * Return: Pointer to the first node reached
 */
listint_t *backward_pass(listint_t **list, listint_t *end)
{
	listint_t *tmp = end, *first = NULL;

	while (tmp && tmp->prev)
	{
		if (tmp->n < tmp->prev->n)
		{
			swap_nodes(list, tmp->prev, tmp);
			first = tmp->next;
		}
		else
		{
			first = tmp;
			tmp = tmp->prev;
		}
	}
	return (first);
}

/**
 * cocktail_sort_list - Sort a doubly linked list using cocktail shaker sort
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *end;

	if (!list || !*list || !(*list)->next)
		return;
	
	end = NULL;
	while (swapped)
	{
		swapped = 0;
		end = forward_pass(list);
		if (!end)
			break;
		if (end && end->prev)
			swapped = 1;
		
		end = backward_pass(list, end);
	}
}
