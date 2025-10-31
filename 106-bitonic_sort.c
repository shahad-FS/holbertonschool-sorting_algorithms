#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap_int (int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - Recursively merges a bitonic sequence.
 * @array: The array to sort.
 * @size: Size of the total array.
 * @start: Starting index of the sequence.
 * @seq_size: Size of the current sequence.
 * @dir: Direction of sorting (1 for UP, 0 for DOWN).
 */
void bitonic_merge(int *array, size_t size, size_t start,
		   size_t seq_size, int dir)
{
	size_t i, half;

	if (seq_size <= 1)
		return;

	half = seq_size / 2;

	for (i = start; i < start + half; i++)
	{
		if ((dir == 1 && array[i] > array[i + half]) ||
			(dir == 0 && array[i] < array[i + half]))
		{
			swap_int(&array[i], &array[i + half]);
			print_array(array, size);
		}
	}

	bitonic_merge(array, size, start, half, dir);
	bitonic_merge(array, size, start + half, half, dir);
}

/**
 * bitonic_seq - Builds a bitonic sequence recursively.
 * @array: The array to sort.
 * @size: Size of the total array.
 * @start: Starting index of the sequence.
 * @seq_size: Size of the current sequence.
 * @dir: Direction of sorting (1 for UP, 0 for DOWN).
 */
void bitonic_seq(int *array, size_t size, size_t start,
		 size_t seq_size, int dir)
{
	size_t half;

	if (seq_size <= 1)
		return;
	printf("Merging [%lu%lu] (%s):\n", seq_size, size,
			dir == 1 ? "UP" : "DOWN");
	print_array(array + start, seq_size);

	half = seq_size / 2;

	bitonic_seq(array, size, start, half, 1);
	bitonic_seq(array, size, start + half, half, 0);
	bitonic_merge(array, size, start, seq_size, dir);

	printf("Result [%lu%lu] (%s):\n", seq_size, size,
			dir == 1 ? "UP" : "DOWN");
	print_array(array + start, seq_size);
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 *                using the Bitonic sort algorithm.
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_seq(array, size, 0, size, 1);
}
