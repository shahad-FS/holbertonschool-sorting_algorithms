#include "sort.h"
#include <limits.h>

/**
 * get_max - Find max value in array of integers
 *
 * @array: array to find max value of
 * @size: size of the array
 * Return: 0
 */
int get_max(int *array, size_t size)
{
	int max = INT_MIN;

	while (size--)
		if (array[size] > max)
			max = array[size];
	return (max);
}

/**
 * counting_sort - sort an array
 * @array: array to sort
 * @size: size of array to sort
 */
void counting_sort(int *array, size_t size)
{
	int *tmp, *cpy, j, max;
	size_t i;

	if (!array || size < 2)
		return;

	max = get_max(array, size);
	tmp = calloc(max + 1, sizeof(*tmp));
	if (!tmp)
		return;

	cpy = malloc(sizeof(*cpy) * size);
	if (!cpy)
	{
		free(tmp);
		return;
	}

	for (i = 0; i < size; i++)
		tmp[array[i]]++;

	for (j = 1; j < max + 1; j++)
		tmp[j] += tmp[j - 1];

	print_array(tmp, max + 1);

	for (i = 0; i < size; i++)
	{
		tmp[array[i]]--;
		cpy[tmp[array[i]]] = array[i];
	}

	for (i = 0; i < size; i++)
		array[i] = cpy[i];

	free(tmp);
	free(cpy);
}
