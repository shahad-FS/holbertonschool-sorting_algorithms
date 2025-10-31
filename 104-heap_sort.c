#include "sort.h"

/**
 * swap_int - Swap two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Ensures the max heap property for a subtree
 * @array: Array of integers
 * @size: Total size of the array
 * @n: Current heap size
 * @i: Index of root node of subtree
 */
void heapify(int *array, size_t size, size_t n, size_t i)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;
	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap_int(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, size, n, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (!array || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		heapify(array, size, size, i - 1);

	for (i = size - 1; i > 0; i--)
	{
		swap_int(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
