#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - Sorts a bitonic sequence inside an array of integers.
 * @array: The array to sort.
 * @size: The total size of the array.
 * @start: The starting index of the sequence in the array to sort.
 * @seq: The size of the sequence to sort.
 * @flow: The direction to sort in (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == 1 && array[i] > array[i + jump]) ||
			    (flow == 0 && array[i] < array[i + jump]))
				swap_int(&array[i], &array[i + jump]);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Converts a subarray of integers into a bitonic sequence.
 * @array: The array to sort.
 * @size: The total size of the array.
 * @start: The starting index of the subarray to sort.
 * @seq: The size of the subarray to sort.
 * @flow: The direction to sort in (1 for ascending, 0 for descending).
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == 1) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, 1);
		bitonic_seq(array, size, start + cut, cut, 0);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending
 *                order using the Bitonic sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each merge.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, 1);
}
