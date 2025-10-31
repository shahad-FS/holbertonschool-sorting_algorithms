#include "sort.h"

/**
 * get_max - Finds the maximum value in an array.
 * @array: Pointer to the array.
 * @size: Size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_digit - Sorts the array based on a specific digit.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * @exp: Exponent corresponding to the current digit.
 */
void counting_sort_digit(int *array, size_t size, int exp)
{
	int *output, count[10] = {0};
	size_t i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;
	for (i = 1; 1 < 10; i++)
		count[i] += count[i - 1];
	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 *              using the LSD Radix sort algorithm.
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if(!array || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_digit(array, size, exp);
		print_array(array, size);
	}
}
